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
    Evac = 0.;
    Order = 0;
    R_air = 0.;
    R_eau = 0.;
    Contamination = 0;
    ptrReacteur = std::make_unique<reacteur>();
    ptrCircuit_Primaire = std::make_unique<circuitPrimaire>();
    ptrCircuit_Secondaire = std::make_unique<circuitSecondaire>();
    ptrOuvriers = std::make_unique<ouvriers>();
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



reacteur& centrale::get_Reacteur() const {
    return *ptrReacteur;
}

circuitPrimaire& centrale::get_Circuit_Primaire() const {
    return *ptrCircuit_Primaire;
}

circuitSecondaire& centrale::get_Circuit_Secondaire() const {
    return *ptrCircuit_Secondaire;
}

ouvriers& centrale::get_Ouvriers() const {
    return *ptrOuvriers;
}


void centrale::set_E_enceinte(double val){
    E_enceinte = val;
}

void centrale::set_P_enceinte(double val){
    P_enceinte = val;
}
void centrale::set_R_enceinte(double val){
    R_enceinte = val;
}

void centrale::set_E_centrale(double val){
    E_centrale = val;
}

void centrale::set_MW(int val){
    MW = val;
}

void centrale::set_Evac(double val){
    Evac = val;
}

void centrale::set_R_air(double val){
    R_air = val;
}

void centrale::set_R_eau(double val){
    R_eau = val;
}

void centrale::set_Contamination(int val){
    Contamination = val;
}

void centrale::maj_P_enceinte(){
    double P1 = ptrCircuit_Primaire->get_Pression();
    double E_cuve = ptrReacteur->get_E_cuve();
    double E_piscine = ptrReacteur->get_E_piscine();
    double E_C1 = ptrCircuit_Primaire->get_E_circuit();
    double E_vap = ptrCircuit_Secondaire->get_E_vapeur();
    double P_vap = ptrCircuit_Secondaire->get_P_vapeur();

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
    double E_C1 = ptrCircuit_Primaire->get_E_circuit();
    double R1 = ptrCircuit_Primaire->get_Radioactivite();
    double E_press = ptrCircuit_Primaire->get_E_pressuriseur();
    double E_piscine = ptrReacteur->get_E_piscine();
    double R_piscine = ptrReacteur->get_R_piscine();

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
    double E_canaux = ptrReacteur->get_E_canaux();
    double E_barre = ptrReacteur->get_E_barre();
    double E_cuve = ptrReacteur->get_E_cuve();
    double E_piscine = ptrReacteur->get_E_piscine();
    double E_p1 = ptrCircuit_Primaire->get_E_pompe();
    double E_p2 = ptrCircuit_Secondaire->get_E_pompe();
    double E_EC = ptrCircuit_Primaire->get_E_echangeur();
    double E_vap = ptrCircuit_Secondaire->get_E_vapeur();
    double E_press = ptrCircuit_Primaire->get_E_pressuriseur();
    double E_res = ptrCircuit_Primaire->get_E_resistance();
    double E_C1 = ptrCircuit_Primaire->get_E_circuit();
    double E_C2 = ptrCircuit_Secondaire->get_E_circuit();
    double E_bore = ptrReacteur->get_E_bore();
    double E_cond = ptrCircuit_Secondaire->get_E_condenseur();

    E_centrale = (E_canaux + 2*E_barre + 8*E_cuve + 3*E_piscine + E_p1 + E_p2 + 5*E_EC + 4*E_vap + E_press + E_res + 4*E_enceinte + 8*E_C1 + 3*E_C2 + E_bore + E_cond)/44.;

}

void centrale::maj_MW(){
    double T_vap = ptrCircuit_Secondaire->get_T_vapeur();
    double E_C2 = ptrCircuit_Secondaire->get_E_circuit();
    double P_vap = ptrCircuit_Secondaire->get_P_vapeur();
    double P1 = ptrCircuit_Primaire->get_Pression();

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

std::string centrale::degr_E_enceinte(){
    std::string messageErreur = "";
    if(E_enceinte>0.){
        if ((P_enceinte>2.) && (P_enceinte<3.4)){ // cas général (pas forcément de dégradation)
            messageErreur += "Dégradation potentielle de l’enceinte de confinement dû à la pression \n"s;
            if (E_enceinte>0.5){ // cas avec dégradation
            E_enceinte -= (RND(0.02))*(RND(1.)>=0.7);
            }
        }

        if ((P_enceinte>=3.4) && (P_enceinte<4.5)){ // cas général (pas forcément de dégradation)
            messageErreur += "Risque important de dégradation de l’enceinte de confinement dû à la pression \n"s;
            if (E_enceinte>0.25){ // cas avec dégradation
            E_enceinte -= (RND(0.06))*(RND(1.)>=0.4);
            }
        }

        if(E_enceinte < 0){
            E_enceinte = 0;
        }

        if ((P_enceinte>=4.5) || (E_enceinte == 0.)){
            E_enceinte = 0.; //Gérer les risques pollution
            messageErreur += "Destruction totale de l’enceinte de confinement \n"s;
        }
    }
    if (E_enceinte <= 0.){
        E_enceinte = 0.;
    }
    return messageErreur;
}

void centrale::maj_Reacteur(){
    double R1 = ptrCircuit_Primaire->get_Radioactivite();
    double T1 = ptrCircuit_Primaire->get_Temperature();
    double E_C1 = ptrCircuit_Primaire->get_E_circuit();
    bool urg = arret_urgence();

    ptrReacteur->maj_R_piscine(R1);
    ptrReacteur->degr_E_barre(T1, urg);
    ptrReacteur->degr_E_bore(T1, E_C1);
    ptrReacteur->degr_E_canaux(T1, urg);
    ptrReacteur->degr_E_cuve(T1, E_C1, E_enceinte, urg);
    ptrReacteur->degr_E_piscine(T1, E_C1, E_enceinte);
} 

void centrale::maj_Circuit_Primaire(){
    double E_cuve = ptrReacteur->get_E_cuve();
    double TBore_eff = ptrReacteur->get_TBore_eff();
    double TGraphite_eff = ptrReacteur->get_TGraphite_eff();
    double T_vapeur = ptrCircuit_Secondaire->get_T_vapeur();

    ptrCircuit_Primaire->maj_Debit_eau_1(E_cuve);
    ptrCircuit_Primaire->maj_Inertie(TBore_eff, TGraphite_eff, T_vapeur);
    ptrCircuit_Primaire->maj_Pression();
    ptrCircuit_Primaire->maj_Radioactivite(TBore_eff, MW);
    ptrCircuit_Primaire->maj_T_pressuriseur_eff();
    ptrCircuit_Primaire->maj_Temperature(TBore_eff, TGraphite_eff);
    ptrCircuit_Primaire->degr_E_circuit(E_enceinte);
    ptrCircuit_Primaire->degr_E_pompe();
    ptrCircuit_Primaire->degr_E_pressuriseur(E_enceinte);
    ptrCircuit_Primaire->degr_E_resistance(E_enceinte);
    ptrCircuit_Primaire->degr_E_echangeur();
}

void centrale::maj_Circuit_Secondaire(){
    double E_chaleur = ptrCircuit_Primaire->get_E_echangeur();
    double T1 = ptrCircuit_Primaire->get_Temperature();
    double R1 = ptrCircuit_Primaire->get_Radioactivite();
    
    ptrCircuit_Secondaire->degrad_all(E_chaleur,E_enceinte);
    ptrCircuit_Secondaire->maj_T_vapeur(E_chaleur,T1);
    ptrCircuit_Secondaire->maj_P_vapeur();
    ptrCircuit_Secondaire->maj_Debit_eau_2();
    ptrCircuit_Secondaire->maj_D_condenseur();
    ptrCircuit_Secondaire->maj_Inertie(T1);
    ptrCircuit_Secondaire->maj_Radioactivite(E_chaleur,R1);

} 

void centrale::maj_Centrale(){
    maj_Population();
    maj_P_enceinte();
    maj_R_enceinte();
    maj_E_centrale();
    maj_MW();
    degr_E_enceinte();
}

double centrale::get_Evac() const{
    return Evac;
}

int centrale::get_Order() const{
    return Order;
}

void centrale::set_Order(){
    Order = true;
}

double centrale::get_R_air() const{
    return R_air;
}

double centrale::get_R_eau() const{
    return R_eau;
}

int centrale::get_Contamination() const{
    return Contamination;
}

void centrale::maj_Evac(){
    if(Order == true){
        Evac += 0.1*(RND(1.)>=0.6);
    }
}

void centrale::maj_R_air(){

    double E_C2 = ptrCircuit_Secondaire->get_E_circuit();

    /** Peut-être pas utile **/
    if(E_enceinte>0.97){
        R_air = 0.;
    }

    else {
        R_air = (1. - E_enceinte)*R_enceinte + (1. - E_C2)*10;
    }
}

void centrale::maj_R_eau(){

    double E_CD = ptrCircuit_Secondaire->get_E_condenseur();
    double R2 = ptrCircuit_Secondaire->get_Radioactivite();

    if ((E_CD>0.9) || (R2<2)){
        R_eau = 0.;
    }

    else{
        R_eau = (1. - E_CD) * R2 * (0.01);
    }
}

void centrale::maj_Contamination(){

    if (R_enceinte<0.1){
        Contamination -= 5*(R_air>6) - 5*(R_eau>1) - 8*(R_eau>12) - 10*(R_air>12);
    }

    if (R_air>12){
        Contamination += 4 + RND(15);
    }

    if (R_eau>12){
        Contamination += 5 + RND(20);
    }

    if (R_air>20){
        Contamination += 12 + RND(20);
    }

}

void centrale::maj_Population(){
    maj_Contamination();
    maj_R_air();
    maj_R_eau();
    maj_Evac();
}

void centrale::envoie_intervention(int organe) {
    std::array<int,8> Max = {8, 8, 20, 60, 50, 45, 20, 10};
    if (organe<=7 && organe>=0) {
        ptrOuvriers->envoie_intervention(organe,Max[organe]-ptrOuvriers->get_nb_ouvriersEnIntervention(organe));
    }
}

void centrale::maj_Reparation() {
    // on check si des ouvriers sont gueris ou sont blesses
    bool dangereux = (R_enceinte>12 || P_enceinte>3 || ptrCircuit_Secondaire->get_Temperature()>300 || MW>1000);
    ptrOuvriers->maj_ouvriers(dangereux,(ptrCircuit_Primaire->get_E_circuit()<0.2));

    // on verifie chaque sur chaque organe s'il y a une intervention.
    // on repare et on verifie si l'intervention est finie.
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(0)>0) {
        if (ptrCircuit_Primaire->reparation_pompe()) {
            ptrOuvriers->retrait_intervention(0);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(1)>0) {
        if (ptrCircuit_Secondaire->reparation_pompe()) {
            ptrOuvriers->retrait_intervention(1);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(2)>0) {
        if (ptrCircuit_Secondaire->reparation_condenseur()) {
            ptrOuvriers->retrait_intervention(2);
        }
    }
    int ouvrierSurVapeur =ptrOuvriers->get_nb_ouvriersEnIntervention(3);
    if (ouvrierSurVapeur>0) {
        if (ptrCircuit_Secondaire->reparation_vapeur(ouvrierSurVapeur)) {
            ptrOuvriers->retrait_intervention(3);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(4)>0) {
        if (ptrReacteur->repa_E_bore()) {
            ptrOuvriers->retrait_intervention(4);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(5)>0) {
        if (ptrCircuit_Primaire->reparation_circuitPrimaire()) {
            ptrOuvriers->retrait_intervention(5);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(6)>0) {
        if (ptrCircuit_Secondaire->reparation_circuitSecondaire()) {
            ptrOuvriers->retrait_intervention(6);
        }
    }
    if (ptrOuvriers->get_nb_ouvriersEnIntervention(7)>0) {
        if (ptrCircuit_Primaire->reparation_pressuriseurANDresistance()) {
            ptrOuvriers->retrait_intervention(7);
        }
    }
}

std::array<bool,10> centrale::get_clignotements(){
    std::array<bool,10> etat = {0};
    
    if(ptrCircuit_Primaire->get_E_pompe()<0.5){
        etat[0] = 1;
    }

    if(ptrCircuit_Secondaire->get_E_pompe()<0.5){
        etat[1] = 1;
    }

    if(ptrCircuit_Secondaire->get_E_condenseur()<0.5){
        etat[2] = 1;
    }

    if(ptrCircuit_Secondaire->get_E_vapeur()<0.5){
        etat[3] = 1;
    }

    if((ptrReacteur->get_E_bore()<1.) || (ptrReacteur->get_E_barre()<0.5)){
        etat[4] = 1;
    }

    if(ptrCircuit_Primaire->get_E_circuit()<0.5){
        etat[5] = 1;
    }

    if(ptrCircuit_Secondaire->get_E_circuit()<0.5){
        etat[6] = 1;
    }

    if(ptrCircuit_Primaire->get_E_pressuriseur()<0.5){
        etat[7] = 1;
    }

    if(ptrCircuit_Primaire->get_E_echangeur()<0.5){
        etat[8] = 1;
    }

    if(get_E_enceinte()<0.5){
        etat[9] = 1;
    }
    
    return(etat);

}

bool centrale::arret_urgence(){
    bool urg = false;

    double E_cuve = ptrReacteur->get_E_cuve();
    double E_canaux = ptrReacteur->get_E_canaux();
    double E_barre = ptrReacteur->get_E_barre();

    if(RND(1.)<=0.7*E_cuve*E_canaux*E_barre+0.15){
        ptrReacteur->set_graphite(0.);
    }

    else{
        urg = true;
    }

    return urg;
}

void centrale::envoie_pompeCircuitPrimaire() {
    ptrOuvriers->envoie_intervention(0,8);
}

void centrale::envoie_pompeCircuitSecondaire() {
    ptrOuvriers->envoie_intervention(1,8);
}

void centrale::envoie_condenseur() {
    ptrOuvriers->envoie_intervention(2,20);
}

void centrale::envoie_generateurVapeur() {
    ptrOuvriers->envoie_intervention(3,60);
}

void centrale::envoie_injecteurBore() {
    ptrOuvriers->envoie_intervention(4,5);
}

void centrale::envoie_circuitPrimaire() {
    ptrOuvriers->envoie_intervention(5,45);
}

void centrale::envoie_circuitSecondaire() {
    ptrOuvriers->envoie_intervention(6,20);
}

void centrale::envoie_pressuriseur() {
    ptrOuvriers->envoie_intervention(7,10);
}
