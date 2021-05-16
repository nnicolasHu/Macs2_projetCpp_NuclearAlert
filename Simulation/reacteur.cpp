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

/*void reacteur::set_bore(double valeur_demandee){
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
}*/

void reacteur::incr_bore() {
    if (Tx_bore<0.5 ){
        Tx_bore += 0.01;
    }
}

void reacteur::decr_bore() {
    if (Tx_bore>0.0){  //erreur arrondi à 0?
        Tx_bore -= 0.01;
    }
    if (Tx_bore<0) Tx_bore = 0.;
}

void reacteur::maj_bore(){
    TBore_eff += 0.01*(TBore_eff<Tx_bore) - 0.01*(TBore_eff>Tx_bore);
}

double reacteur::get_Tx_bore() const {
    return Tx_bore;
}

double reacteur::get_TBore_eff() const{
    return TBore_eff;
}

double reacteur::get_E_bore() const{
    return E_bore;
}

void reacteur::set_graphite(double valeur_demandee){
    Tx_graphite = valeur_demandee;
    
}

void reacteur::incr_graphite() {
    if ( Tx_graphite<1.){
        Tx_graphite += 0.01;
    }
}

void reacteur::decr_graphite() {
    if (Tx_graphite>1-E_barre+0.01){
        Tx_graphite -= 0.01;
    }
    if (Tx_graphite<0.01) Tx_graphite=0.; //refuse de descende à 0 de manière aléatoire?
}

void reacteur::maj_graphite(){ 
    TGraphite_eff += 0.01*(TGraphite_eff<Tx_graphite) - 0.01*(TGraphite_eff>Tx_graphite);
    // la valeur demandée ne peut être plus petite que 1-E_barre
    if (Tx_graphite<1-E_barre) {
        Tx_graphite = 1-E_barre;
    }
}

double reacteur::get_Tx_graphite() const {
    return Tx_graphite;
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

std::string reacteur::degr_E_cuve(double T1, double E_circuit_primaire, double E_enceinte, bool urg){
    std::string message;
    if (E_cuve>0.){
        if ((T1>=50) && (E_circuit_primaire<0.6)){
            E_cuve -=  (RND(0.02))*(RND(1.)>=0.6);
            message += "Risque de dégradation de la cuve"s;
        }
        if ((T1>=50) && (E_circuit_primaire<0.3)){
            E_cuve -=  (RND(0.03))*(RND(1.)>=0.7);
            message += "Risque de forte dégradation de la cuve"s;
        }
        if ((T1>=50) && (E_circuit_primaire<0.2)){
            E_cuve -=  (RND(0.06))*(RND(1.)>=0.2);
            message += "Risque très important de très forte dégradation de la cuve"s;
        }
        if (E_enceinte == 0.){
            E_cuve -= (0.5 + RND(0.1))*(RND(1.)>=0.35);
        }
        if (urg == true){
            E_cuve -= (RND(0.08))*(RND(1.)>=0.6);
        }
    }
    if (E_cuve <= 0.){
        E_cuve = 0.;
    }
    return(message);
}

std::string reacteur::degr_E_piscine(double T1, double E_circuit_primaire,double E_enceinte){

    std::string message;

    if(E_piscine >0.){
        if ((T1>=50) && (E_circuit_primaire<0.2)){
            E_piscine -= (RND(0.06))*(RND(1.)>=0.2);
            message += "Risque très important de dégradation de la piscine"s;
        }
        if (E_enceinte == 0.){
            E_piscine -= (0.6 + RND(0.16))*(RND(1.)>=0.35);
        }
    }
    if (E_piscine <= 0.){
        E_piscine = 0.;
    }
    return(message);
}

std::string reacteur::degr_E_barre(double T1, bool urg){

    std::string message;

    if(E_barre>0.){
        if ((T1>=50) && (E_canaux<0.6) && (TGraphite_eff>0.4) ){
            E_barre -= (RND(0.02))*(RND(1.)>=0.7);
            message += "Risque de dégradation des barres de graphite"s;
        }
        if ((T1>=50) && (E_cuve<0.7) && (TGraphite_eff>0.4) ){
            E_barre -= (RND(0.03))*(RND(1.)>=0.6);
            message += "Risque important de dégradation des barres de graphite"s;
        }
        if ((T1>=420) && (TGraphite_eff>0.2) ){
            E_barre -= RND(0.03);
            message += "Dégradation possible des barres"s;
        }
        if (urg == true){
            E_barre -= (0.02 + RND(0.08))*(RND(1.)>=0.7);
        }
    }
    if (E_barre <= 0.){
        E_barre = 0.;
    }
    return(message);
}

std::string reacteur::degr_E_canaux(double T1, bool urg){
    
    std::string message;

    if(E_canaux>0.){
        if ((T1>=50) && (E_cuve<0.5)){
            E_canaux -= (RND(0.05))*(RND(1.)>=0.5);
            message += "Risque important de dégradation importante des canaux"s;
        }
        if (urg == true){
            E_canaux -= ((0.05) + RND(0.1))*(RND(1.)>=0.2);
        }
    }
    if (E_canaux <= 0.){
        E_canaux = 0.;
    }
    return(message);

}

std::string reacteur::degr_E_bore(double T1, double E_circuit_primaire){

    std::string message;

    if(E_bore>0.){
        if ((T1>=50) && (E_cuve<0.5) && (E_circuit_primaire<0.5)){
            E_bore -= (RND(0.02))*(RND(1.)>=0.5);
            message += "Risque important de dégradation de l'injecteur d'acide borique"s;
        }
    }
    if (E_bore <= 0.){
        E_bore = 0.;
    }
    return(message);
}

bool reacteur::repa_E_bore(){
    bool reparation = false;

    if (RND(1.)>=0.7){
        if (E_bore < 0.96){
            E_bore += RND(0.04);
        }

        if (E_bore >= 0.96){
            E_bore = 1.;
        }
    }

    if (E_bore >= 0.96){
        reparation = true;
    }

    return reparation;
}