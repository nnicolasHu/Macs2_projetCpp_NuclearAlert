#include <iostream>
#include "CircuitSecondaire.hpp"

/** Constructeur(s) **/

circuitSecondaire::circuitSecondaire()
    :etat_gen_vapeur{1.0},
     etat_condensateur{1.0},
     regime_pompe_condensateur{0.0},
     temperature_vap{25.0},
     pression_vapeur{1.0},
     debit_cond{0.0},
     delta_cond{0.0}
     {}

/** Méthodes **/

void circuitSecondaire::set_regime_pompe_cond(double valeur_demandee){

    double etat_cond = this->get_etat_condensateur();

    if((valeur_demandee >= 0) && (valeur_demandee<= etat_cond )){
        this->regime_pompe_condensateur = valeur_demandee;
    }

    else{
        std::cout << " Erreur sur le régime demandé à la pompe condensateur ! " << std::endl;
    }
}

double circuitSecondaire::get_regime_pompe_cond() const{
    return this->regime_pompe_condensateur;
}

double circuitSecondaire::get_etat_gen_vapeur() const{
    return this->etat_gen_vapeur;
}

double circuitSecondaire::get_etat_condensateur() const{
    return this->etat_condensateur;
}

double circuitSecondaire::get_temp_vapeur() const{
    return this->temperature_vap;
}

double circuitSecondaire::get_pression_vapeur() const{
    return this->pression_vapeur;
}

double circuitSecondaire::get_debit_cond() const{
    return this->debit_cond;
}

double circuitSecondaire::get_delta_cond() const{
    return this->delta_cond;
}

