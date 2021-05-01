#include <iostream>
#include "reacteur.hpp"
#include "RND.hpp"

/** Constructeur(s) **/

reacteur::reacteur(){
    E_cuve = 1.;
    E_piscine = 1.;
    E_canaux = 1.;
    E_barre = 1.;
    E_bore = 1.;
    Tx_bore = 0.47;
    TBore_eff =  0.47;
    Tx_graphite = 0.;
    TGraphite_eff =  0.;
    R_piscine = 0.; 
}

/** Méthodes **/

void reacteur::set_bore(double valeur_demandee){
    if ((valeur_demandee <= 0.5) && (valeur_demandee >= 0.0)){
       Tx_bore = valeur_demandee; 
       if (TBore_eff < Tx_bore){
            TBore_eff += 0.01;
        }
        if (TBore_eff > Tx_bore){
            TBore_eff -= 0.01;
        }
    }
    else {
        std::cout << " Erreur sur le taux de bore demandé ! " <<
        std::endl; 
    }
}

double reacteur::get_TBore_eff() const{
    return TBore_eff;
}

double reacteur::get_E_bore() const{
    return E_bore;
}

void reacteur::set_graphite(double valeur_demandee){
    if ((valeur_demandee>=(1. - E_barre)) && (valeur_demandee<=1.)){
        Tx_graphite = valeur_demandee;
        if (TGraphite_eff < Tx_graphite){
            TGraphite_eff += 0.01;
        }
        if (TGraphite_eff > Tx_graphite){
            TGraphite_eff += -0.01;
        }
    }
    else {
        std::cout << " Erreur sur la proportion de graphite demandée ! " <<
        std::endl; 
    }
}

double reacteur::get_TGraphite_eff() const{
    return TGraphite_eff;
}

double reacteur::get_E_barre() const{
    return E_barre;
}

double reacteur::get_E_cuve() const{
    return E_cuve;
}

double reacteur::get_E_piscine() const{
    return E_piscine;
}

double reacteur::get_E_canaux() const{
    return E_canaux;
}

double reacteur::get_R_piscine() const{
    return R_piscine;
}

void reacteur::set_E_cuve(double val){
    E_cuve = val;
}

void reacteur::set_E_piscine(double val){
    E_piscine = val;
}

void reacteur::set_R_piscine(double val){
    R_piscine = val;
}

void reacteur::set_E_barre(double val){
    E_barre = val;
}

void reacteur::set_E_canaux(double val){
    E_canaux = val;
}

void reacteur::set_E_bore(double val){
    E_bore = val;
}

void reacteur::maj_R_piscine(double R1){
    R_piscine = (1.- E_cuve)*R1 + 100 + RND(45);
}

void reacteur::degr_E_cuve(double T1, double E_circuit_primaire){
    double E_enceinte = Centrale->get_E_enceinte();

    if (E_cuve>0.){
        if ((T1>=50) && (E_circuit_primaire<0.6)){
            E_cuve -=  (RND(0.02))*(RND(1.)>=0.6);
        }
        if ((T1>=50) && (E_circuit_primaire<0.3)){
            E_cuve -=  (RND(0.03))*(RND(1.)>=0.7);
        }
        if ((T1>=50) && (E_circuit_primaire<0.2)){
            E_cuve -=  (RND(0.06))*(RND(1.)>=0.2);
        }
        if (E_enceinte == 0.){
            E_cuve -= (0.5 + RND(0.1))*(RND(1.)>=0.35);
        }
    }
    if (E_cuve <= 0.){
        E_cuve = 0.;
    }
}

void reacteur::degr_E_piscine(double T1, double E_circuit_primaire){
    double E_enceinte = Centrale->get_E_enceinte();

    if(E_piscine >0.){
        if ((T1>=50) && (E_circuit_primaire<0.2)){
        E_piscine -= (RND(0.06))*(RND(1.)>=0.2);
        }
        if (E_enceinte == 0.){
            E_piscine -= (0.6 + RND(0.16))*(RND(1.)>=0.35);
        }
    }
    if (E_piscine <= 0.){
        E_piscine = 0.;
    }
}

void reacteur::degr_E_barre(double T1){
    if(E_barre>0.){
        if ((T1>=50) && (E_canaux<0.6) && (TGraphite_eff>0.4) ){
            E_barre -= (RND(0.02))*(RND(1.)>=0.7);
        }
        if ((T1>=50) && (E_cuve<0.7) && (TGraphite_eff>0.4) ){
            E_barre -= (RND(0.03))*(RND(1.)>=0.6);
        }
        if ((T1>=420) && (TGraphite_eff>0.2) ){
            E_barre -= RND(0.03);
        }
    }
    if (E_barre <= 0.){
        E_barre = 0.;
    }
}

void reacteur::degr_E_canaux(double T1){
    if(E_canaux>0.){
        if ((T1>=50) && (E_cuve<0.5)){
            E_canaux -= (RND(0.05))*(RND(1.)>=0.5);
        }
    }
    if (E_canaux <= 0.){
        E_canaux = 0.;
    }

}

void reacteur::degr_E_bore(double T1, double E_circuit_primaire){
    if(E_bore>0.){
        if ((T1>=50) && (E_cuve<0.5) && (E_circuit_primaire<0.5)){
            E_bore -= (RND(0.02))*(RND(1.)>=0.5);
        }
    }
    if (E_bore <= 0.){
        E_bore = 0.;
    }
}
