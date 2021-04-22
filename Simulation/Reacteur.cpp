#include <iostream>
#include "Reacteur.hpp"

/** Constructeur(s) **/

reacteur::reacteur(){
    etat_cuve = 1.;
    etat_piscine = 1.;
    etat_canaux = 1.;
    etat_graphite = 1.;
    etat_injecteur = 1.;
    taux =  0.47;
    proportion_graphite = 0.;
    radiation_piscine = 0.; 
}

/** Méthodes **/

void reacteur::set_bore(double valeur_demandee){
    if ((valeur_demandee <= 0.5) && (valeur_demandee >= 0.0)){
       taux = valeur_demandee; 
    }
    else {
        std::cout << " Erreur sur le taux de bore demandée ! " <<
        std::endl; 
    }
}

double reacteur::get_bore() const{
    return taux;
}

double reacteur::get_injecteur() const{
    return etat_injecteur;
}

void reacteur::set_graphite(double valeur_demandee){
    double etat_barre = get_graphite(); 
    if ((valeur_demandee>=(1. - etat_barre)) && (valeur_demandee<=1.)){
        proportion_graphite = valeur_demandee;
    }
    else {
        std::cout << " Erreur sur la proportion de graphite demandée ! " <<
        std::endl; 
    }
}

double reacteur::get_graphite() const{
    return proportion_graphite;
}

double reacteur::get_barre() const{
    return etat_graphite;
}

double reacteur::get_cuve() const{
    return etat_cuve;
}

double reacteur::get_piscine() const{
    return etat_piscine;
}

double reacteur::get_canaux() const{
    return etat_canaux;
}

double reacteur::get_radiation() const{
    return radiation_piscine;
}


