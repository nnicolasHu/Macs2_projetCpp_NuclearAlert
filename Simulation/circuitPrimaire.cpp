#include "circuitPrimaire.hpp"
#include <iostream>


/** Constructeur(s) **/

circuitPrimaire::circuitPrimaire() {
    circuit();
    E_pressuriseur = 1.;
    E_resistance = 1.;
    E_echangeur = 1.;
    T_pressuriseur = 25.;
    T_pressuriseur_eff = 25.;
}


/** Méthodes **/

// les getters
double circuitPrimaire::get_E_pressuriseur() const{
    return E_pressuriseur;
}

double circuitPrimaire::get_E_resistance() const{
    return E_resistance;
}

double circuitPrimaire::get_E_echangeur() const{
    return E_echangeur;
}

double circuitPrimaire::get_T_pressuriseur() const{
    return T_pressuriseur;
}

double circuitPrimaire::get_T_pressuriseur_eff() const{
    return T_pressuriseur_eff;
}


// les setters
void circuitPrimaire::set_E_pressuriseur(double etat) {
    if (etat>=0 & etat<=1) E_pressuriseur=etat;
}

void circuitPrimaire::set_E_resistance(double etat) {
    if (etat>=0 & etat<=1) E_resistance=etat;
}

void circuitPrimaire::set_E_echangeur(double etat) {
    if (etat>=0 & etat<=1) E_echangeur=etat;
}

void circuitPrimaire::set_T_pressuriseur(double temperature) {
    if (temperature>=25 & temperature<=100*(this->E_pressuriseur + this->E_resistance)) T_pressuriseur=temperature;
}

/*
void circuitPrimaire::set_temp_pressuriseur(double valeur_demandee){

    double etat_p = get_etat_pressuriseur();
    double etat_r = get_etat_resistance(); 

    if((valeur_demandee>=25.)&&(valeur_demandee<=(etat_p + etat_r)*100)){
        temperature_press = valeur_demandee;
    }

    else{
        std::cout << " Erreur sur la température demandée pour le pressuriseur ! " << 
        std::endl;
    }
    
}
*/


int main() {
    circuitPrimaire C1;
    std::cout << "état du circuit = " <<C1.get_E_circuit() << std::endl;
    return EXIT_SUCCESS;
}