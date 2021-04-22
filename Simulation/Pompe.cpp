#include "Pompe.hpp"
#include <iostream>

/** Constructeur **/

pompe::pompe(){
    etat_pompe = 1.;
    regime = 0.;
}

/** Méthodes **/

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

