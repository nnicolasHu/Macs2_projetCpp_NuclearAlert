#include <iostream>
#include "Circuit_secondaire.hpp"

/** Constructeur(s) **/

circuitSecondaire::circuitSecondaire(){
  
    etat_gen_vapeur = 1.;
    etat_condensateur = 1.;
    regime_pompe_condensateur = 0.;
    temperature_vap = 25.;
    pression_vapeur = 1.;
    debit_cond = 0.;
    delta_cond = 0.;


}

/** Méthodes **/

void circuitSecondaire::set_regime_pompe_cond(double valeur_demandee){

    double e = get_etat_condensateur();

    if((valeur_demandee>=0) && (valeur_demandee<=e)){
        regime_pompe_condensateur = valeur_demandee;
    }

    else{
        std::cout << " Erreur sur le régime demandé à la pompe condensateur ! " <<
        std::endl;
    }
}

double circuitSecondaire::get_regime_pompe_cond() const{
    return regime_pompe_condensateur;
}

double circuitSecondaire::get_etat_gen_vapeur() const{
    return etat_gen_vapeur;
}

double circuitSecondaire::get_etat_condensateur() const{
    return etat_condensateur;
}

double circuitSecondaire::get_temp_vapeur() const{
    return temperature_vap;
}

double circuitSecondaire::get_pression_vapeur() const{
    return pression_vapeur;
}

double circuitSecondaire::get_debit_cond() const{
    return debit_cond;
}

double circuitSecondaire::get_delta_cond() const{
    return delta_cond;
}

