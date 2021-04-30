#include <iostream>
#include "circuitSecondaire.hpp"
#include "RND.hpp"

/** Constructeur(s) **/

circuitSecondaire::circuitSecondaire()
    :circuit(),
     E_vapeur{1.0},
     E_condenseur{1.0},
     F_condenseur{0.0},
     T_vapeur{25.0},
     P_vapeur{1.0},
     D_condenseur{0.0},
     Delta_ES{0.0}
     {}

/** Méthodes **/

void circuitSecondaire::set_F_condenseur(double valeur_demandee){

    double etat_cond = this->get_E_condenseur();

    if((valeur_demandee >= 0) && (valeur_demandee<= etat_cond )){
        this->F_condenseur = valeur_demandee;
    }

    else{
        std::cout << " Erreur sur le régime demandé à la pompe condensateur ! " << std::endl;
    }
}

double circuitSecondaire::get_F_condenseur() const{
    return this->F_condenseur;
}

double circuitSecondaire::get_E_vapeur() const{
    return this->E_vapeur;
}

double circuitSecondaire::get_E_condenseur() const{
    return this->E_condenseur;
}

double circuitSecondaire::get_T_vapeur() const{
    return this->T_vapeur;
}

double circuitSecondaire::get_P_vapeur() const{
    return this->P_vapeur;
}

double circuitSecondaire::get_D_condenseur() const{
    return this->D_condenseur;
}

double circuitSecondaire::get_Delta_ES() const{
    return this->Delta_ES;
}

void circuitSecondaire::degrad_all(double E_chaleur){
    this->degrad_E_circuit();
    this->degrad_E_pompe();
    this->degrad_E_vapeur(E_chaleur);
    this->degrad_E_chaleur(E_chaleur);
}

void circuitSecondaire::degrad_E_circuit(){
    if (this->get_E_circuit() > 0) {
        if (this->get_T_vapeur() > 130 && this->get_E_circuit() < 0.5){ // cas T_vap > 130 && E_ec < 0.5
            double degrad = (RND(1.) <= 0.3) * RND(0.015);
            std::cout << "Risque important de degradation du circuit secondaire" << std::endl;
            if (degrad > 0){
                this->set_E_circuit(this->get_E_circuit() - degrad);
            }
        }
        if (this->get_T_vapeur() >= 310){ // cas T_vap >= 310 °C
            double degrad = (RND(1.) <= 0.25) * RND(0.04);
            std::cout << "Risque important de degradation du circuit secondaire a cause de la temperature" << std::endl;
            if (this->get_E_circuit() - degrad > 0){
                this->set_E_circuit(this->get_E_circuit() - degrad);
            }
            else {
                this->set_E_circuit(0);
            }
        }
        if (this->get_Delta_ES() < 11 && this->get_T_vapeur() >= 130){
            std::cout << "Risque possible de degradation du circuit secondaire du au refroidissement " << std::endl;
        }
    }
}

void circuitSecondaire::degrad_E_pompe(){
    if (this->get_E_pompe() > 0 ){

        if (this->get_E_circuit() < 0.6) {
            double degrad = (RND(1.) <= 0.3) * RND(0.02);
            std::cout << "Risque important de degradation de la pompe du circuit secondaire" << std::endl;
            if ( this->get_E_pompe() - degrad > 0 ){
                this->set_E_pompe(this->get_E_pompe() - degrad);
            }
            else {
                this->set_E_pompe(0);
            }
        }
    }
}

void circuitSecondaire::degrad_E_vapeur(double E_chaleur){
    if (this->get_E_vapeur() > 0 ){
        if (this->get_E_circuit() < 0.4){ // cas E_c2 < 0.6
            double degrad = (RND(1.0) <= 0.3) * RND(0.02);
            std::cout << "Risque important de degradation du générateur de vapeur" << std::endl;
            if (this->E_vapeur - degrad > 0){
                this->E_vapeur = this->get_E_vapeur() - degrad; 
            }
            else {
                this->E_vapeur = 0;
            }
        }
        if (E_chaleur < 0.4){
            double degrad = (RND(1.0) <= 0.25) * RND(0.03);
            std::cout << "Risque important de dégradation de l’echangeur de chaleur" << std::endl;
            if (this->E_vapeur - degrad > 0){
                this->E_vapeur = this->get_E_vapeur() - degrad; 
            }
            else {
                this->E_vapeur = 0;
            }
        }
    }
}

void circuitSecondaire::degrad_E_chaleur(double E_chaleur){
    if (E_chaleur < 0.7){
        std::cout << "Probleme d’echange entre le circuit primaire et le circuit secondaire" << std::endl;
    }
}

void circuitSecondaire::update_T_vapeur(double E_ec,double T1,double It2){
    double new_T = std::max(99.0 , E_ec*(T1/1.51) + 26 + It2*(It2 > 3) );
    this->Temperature = new_T;
}

void circuitSecondaire::update_P_vapeur(){
    if (this->get_P_vapeur() < 120){
        this->P_vapeur = 1.0 ;
    }
    else {
        double new_P_vapeur = std::max(1.0 , (this->get_E_circuit() + 0.1)*this->get_E_vapeur()*(this->get_F_pompe()/50 + (this->get_T_vapeur() - 135)/10 ) );
        this->P_vapeur = new_P_vapeur;
    }
}

void circuitSecondaire::update_Debit_eau(){
    double Z = this->get_E_circuit() * (this->get_E_condenseur() + 0.1)*this->get_E_vapeur()*this->get_F_pompe()*0.85;
    if (this->get_T_vapeur() > 3 && Z < 3){
        this->Debit_eau = this->get_E_circuit()*(this->get_E_condenseur() + 0.1)*this->get_E_vapeur()*1.3;
    }
    else {
        this->Debit_eau = Z;
    }
}

void circuitSecondaire::update_D_condenseur(){
    this->D_condenseur = this->get_E_condenseur()*this->get_F_condenseur()*150;
}

void circuitSecondaire::update_Delta_ES(){
    this->Delta_ES = this->get_D_condenseur()/7.5;
}

void circuitSecondaire::update_Inertie(double T_circuit_primaire){
    if(this->get_F_pompe() < (0.55 + RND(0.15) )  && T_circuit_primaire > 200){
        this->Inertie += RND(T_circuit_primaire/100);
    }
    else if (this->Inertie > 0){
        this->Inertie = std::max(0.0 , this->Inertie - RND(3) );
    }
}

void circuitSecondaire::update_Radioactivite(double E_ec, double Radioactivite_circuit_primaire){
    double new_R2 = std::max(this->Radioactivite , (1-E_ec)*Radioactivite_circuit_primaire);
    this->Radioactivite = new_R2;
}