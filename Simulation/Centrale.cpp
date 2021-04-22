#include <iostream>
#include "Centrale.hpp"

/** Constructeur(s) **/

centrale::centrale(){
    etat_centrale = 1.;
    etat_enceinte = 1.;
    pression_enceinte = 1.;
    production = 0.;
    radioactivité = 0.00002;
}

/** Méthodes **/

double centrale::get_etat_enceinte(){
    return etat_enceinte;
}

double centrale::get_etat_centrale(){
    return etat_centrale;
}

double centrale::get_pression(){
    return pression_enceinte;
}

double centrale::get_production(){
    return production;
}

double centrale::get_radioactivite(){
    return radioactivité;
}

int main(){
    return EXIT_SUCCESS;
}