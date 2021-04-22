#include "Circuit_primaire.hpp"
#include <iostream>


/** Constructeur(s) **/

circuitPrimaire::circuitPrimaire(){
    etat_pressuriseur = 1.;
    etat_resistance = 1.;
    etat_echangeur = 1.;
    temperature_press = 25.;
    pression = 1.;
    temperature = 25.;
}

/** Méthodes **/

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

double circuitPrimaire::get_temp_pressuriseur() const{
    return temperature_press;
}

double circuitPrimaire::get_etat_pressuriseur() const{
    return etat_pressuriseur;
}

double circuitPrimaire::get_etat_resistance() const{
    return etat_resistance;
}

double circuitPrimaire::get_etat_echangeur() const{
    return etat_echangeur;
}

double circuitPrimaire::get_pression() const{
    return pression;
}

double circuitPrimaire::get_temperature() const{
    return temperature;
}
