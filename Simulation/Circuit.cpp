#include "Circuit.hpp"
#include <iostream>

/** Constructeur **/

circuit::circuit(){
    etat = 1.;
    debit = 0.;
    inertie_temp = 0.;
    radioactivité = 0.;
}

/** Méthodes **/

double circuit::get_etat_circuit() const{
    return etat;
}

double circuit::get_debit() const{
    return debit;
}

double circuit::get_inertie() const{
    return inertie_temp;
}

double circuit::get_radioactivite() const{
    return radioactivité;
}

/*
double pompe::get_etat_pompe() const{
    return etat_pompe;
}

double pompe::get_regime() const{
    return regime;
}

void pompe::set_regime(double valeur){

    double e = get_etat_pompe();

    if ((valeur >= 0) && (valeur <= e)){
        regime = valeur;
    } 

    else{
        std::cout << " Erreur valeur régime demandée ! " <<
        std::endl;
    }
}


*/