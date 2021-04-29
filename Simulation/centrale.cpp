#include <iostream>
#include "centrale.hpp"
#include "RND.hpp"

/** Constructeur(s) **/

centrale* centrale::la_centrale = nullptr;

centrale::centrale(){
    E_centrale = 1.;
    E_enceinte = 1.;
    P_enceinte = 1.;
    MW = 0.;
    R_enceinte = 0.00002;
}

centrale& centrale::get(){
    if (centrale::la_centrale == nullptr)
        centrale::la_centrale = new centrale;
    return *centrale::la_centrale;
}

/** Méthodes **/

double centrale::get_E_enceinte() const{
    return E_enceinte;
}

double centrale::get_E_centrale() const{
    return E_centrale;
}

double centrale::get_P_enceinte() const{
    return P_enceinte;
}

double centrale::get_MW() const{
    return MW;
}

double centrale::get_R_enceinte() const{
    return R_enceinte;
}

void centrale::maj_pression_enceinte(){
    double P1 = Circuit_Primaire->get_Pression();
    double E_cuve = Reacteur->get_E_cuve();
    double E_piscine = Reacteur->get_E_piscine();
    double E_C1 = Circuit_Primaire->get_E_circuit();
    double E_vap = Circuit_Secondaire->get_etat_gen_vapeur();
    double P_vap = Circuit_Secondaire->get_pression_vapeur();

    if (((P1>8.) && (E_cuve<1.) && (E_piscine<1.))||((E_cuve<0.3) && (E_piscine<0.4))){
        P_enceinte += (2. - E_cuve - E_piscine)/23;
    }

    if (((E_C1<0.6) && (P1 >12.)) || (E_C1<0.2)){
        P_enceinte += (1. - E_C1)/30; 
    }

    if ((E_vap<0.9) && (P_vap>2.)){
        P_enceinte += (1. - E_vap)/20;
    }

    P_enceinte = fmin(P_enceinte,5.);

    if((E_enceinte>0.5) && (E_enceinte<0.6)){
        P_enceinte -= (1. - E_enceinte)/2 * P_enceinte;
    }

    P_enceinte -= (-0.13)*(RND(1.)>0.7);
}

void centrale::maj_R_enceinte(){
    double E_C1 = Circuit_Primaire->get_E_circuit();
    double R1 = Circuit_Primaire->get_Radioactivite();
    double E_press = Circuit_Primaire->get_E_pressuriseur();
    double E_piscine = Reacteur->get_E_piscine();
    double R_piscine = Reacteur->get_R_piscine();

    R_enceinte = RND(1./55)+ 0.00002 + ((1. - E_C1)*R1)/(98.98) + (1. - E_press)*10.;

    if ((E_piscine<0.55) && (R_piscine>3000)){
        R_enceinte = 1.25 * R_enceinte;
    }

    if (E_enceinte<0.9){
        R_enceinte /= 1.3;
    }

    if (E_enceinte<0.1){
        R_enceinte /= 1.5;
    }

}

void centrale::maj_E_centrale(){
    double E_canaux = Reacteur->get_E_canaux();
    double E_barre = Reacteur->get_E_barre();
    double E_cuve = Reacteur->get_E_cuve();
    double E_piscine = Reacteur->get_E_piscine();
    double E_p1 = Circuit_Primaire->get_E_pompe();
    double E_p2 = Circuit_Secondaire->get_E_pompe();
    double E_EC = Circuit_Primaire->get_E_echangeur();
    double E_vap = Circuit_Secondaire->get_etat_gen_vapeur();
    double E_press = Circuit_Primaire->get_E_pressuriseur();
    double E_res = Circuit_Primaire->get_E_resistance();
    double E_C1 = Circuit_Primaire->get_E_circuit();
    double E_C2 = Circuit_Secondaire->get_E_circuit();
    double E_bore = Reacteur->get_E_bore();
    double E_cond = Circuit_Secondaire->get_etat_condensateur();

    E_centrale = (E_canaux + 2*E_barre + 8*E_cuve + 3*E_piscine + E_p1 + E_p2 + 5*E_EC + 4*E_vap + E_press + E_res + 4*E_enceinte + 8*E_C1 + 3*E_C2 + E_bore + E_cond)/44.;

}

void centrale::maj_MW(){
    double T_vap = Circuit_Secondaire->get_temp_vapeur();
    double E_C2 = Circuit_Secondaire->get_E_circuit();
    double P_vap = Circuit_Secondaire->get_pression_vapeur();
    double P1 = Circuit_Primaire->get_Pression();

    if ((T_vap<120.) || (E_C2<0.22)){
        MW = 0;
    }

    if (T_vap<3000.){
        MW = (int) fmax(5.787*(T_vap-120.)+28.118*(P_vap-1.)+P1,0);
    }

    else {
        MW = 30000;
    }

    if (E_C2<0.6){
        MW = MW*E_C2;
    }

    if ((MW>1400) && (MW<1412)){
        MW = 1400;
    }

}

void centrale::degr_E_enceinte(){

    if ((P_enceinte>2.) && (P_enceinte<3.4) && (E_enceinte>0.5)){
        E_enceinte -= (RND(0.02))*(RND(1.)>=0.7);
    }

    if ((P_enceinte>=3.4) && (P_enceinte<4.5) && (E_enceinte>0.25)){
        E_enceinte -= (RND(0.06))*(RND(1.)>=0.4);
    }

    if ((P_enceinte>=4.5) || (E_enceinte == 0.)){
        E_enceinte = 0.; //Gérer les risques pollution
    }
}

void centrale::maj_Reacteur(){
    double R1 = Circuit_Primaire->get_Radioactivite();
    double T1 = Circuit_Primaire->get_Temperature();
    double E_C1 = Circuit_Primaire->get_E_circuit();

    Reacteur->maj_R_piscine(R1);
    Reacteur->degr_E_barre(T1);
    Reacteur->degr_E_bore(T1, E_C1);
    Reacteur->degr_E_canaux(T1);
    Reacteur->degr_E_cuve(T1, E_C1);
    Reacteur->degr_E_piscine(T1, E_C1);
} 

/* void centrale::maj_Circuit_Primaire(){

    Circuit_Primaire->maj_Debit_eau();
    Circuit_Primaire->maj_Inertie();
    Circuit_Primaire->maj_Pression();
    Circuit_Primaire->maj_Radioactivite();
    Circuit_Primaire->maj_T_pressuriseur_eff();
    Circuit_Primaire->maj_Temperature();
}
 */

