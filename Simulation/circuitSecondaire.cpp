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
        if (degrad > 0){
            this->set_E_circuit(this->get_E_circuit() - degrad);
        }
    }
    if (this->get_Delta_ES() < 11 && this->get_T_vapeur() >= 130){
        std::cout << "Risque possible de degradation du circuit secondaire du au refroidissement" << std::endl;
    }
}

void circuitSecondaire::degrad_E_pompe(){
    if (this->get_E_circuit() < 0.6) {
        double degrad = (RND(1.) <= 0.3) * RND(0.02);
        std::cout << "Risque important de degradation de la pompe du circuit secondaire" << std::endl;
        if (degrad > 0){
            this->set_E_pompe(this->get_E_pompe() - degrad);
        }
    }
    // faire cas E_ec
}

void circuitSecondaire::degrad_E_vapeur(double E_chaleur){
    if (this->get_E_circuit() < 0.4){ // cas E_c2 < 0.6
        double degrad = (RND(1.0) <= 0.3) * RND(0.02);
        std::cout << "Risque important de degradation du générateur de vapeur" << std::endl;
        if (degrad > 0){
            this->E_vapeur = this->get_E_vapeur() - degrad; 
        }
    }
    if (E_chaleur < 0.4){
        double degrad = (RND(1.0) <= 0.25) * RND(0.03);
        std::cout << "Risque important de dégradation de l’echangeur de chaleur" << std::endl;
        if (degrad > 0){
            this->E_vapeur = this->get_E_vapeur() - degrad; 
        }
    }
}

void circuitSecondaire::degrad_E_chaleur(double E_chaleur){
    if (E_chaleur < 0.7){
        std::cout << "Probleme d’echange entre le circuit primaire et le circuit secondaire" << std::endl;
    }
}
