#include "circuitPrimaire.hpp"
#include "RND.hpp"

/** Constructeur(s) **/

circuitPrimaire::circuitPrimaire() {
    circuit();
    E_pressuriseur = 1.;
    E_resistance = 1.;
    E_echangeur = 1.;
    T_pressuriseur = 25.;
    T_pressuriseur_eff = 25.;
}


/** Méthodes **/

// les getters
double circuitPrimaire::get_E_pressuriseur() const{
    return E_pressuriseur;
}

double circuitPrimaire::get_E_resistance() const{
    return E_resistance;
}

double circuitPrimaire::get_E_echangeur() const{
    return E_echangeur;
}

double circuitPrimaire::get_T_pressuriseur() const{
    return T_pressuriseur;
}

double circuitPrimaire::get_T_pressuriseur_eff() const{
    return T_pressuriseur_eff;
}


// les setters
void circuitPrimaire::set_E_pressuriseur(double etat) {
    if (etat>=0 & etat<=1) E_pressuriseur=etat;
}

void circuitPrimaire::set_E_resistance(double etat) {
    if (etat>=0 & etat<=1) E_resistance=etat;
}

void circuitPrimaire::set_E_echangeur(double etat) {
    if (etat>=0 & etat<=1) E_echangeur=etat;
}

void circuitPrimaire::set_T_pressuriseur(double temperature) {
    if (temperature>=25 & temperature<=100*(E_pressuriseur + E_resistance)) T_pressuriseur=temperature;
}



// les mises a jour
void circuitPrimaire::maj_Pression() {
    Pression = std::max((T_pressuriseur_eff - 25.)/3.24 + (Temperature - 100.)/83.3 * (E_circuit + 0.1)*(E_echangeur + 0.1), 1.);
}

void circuitPrimaire::maj_Debit_eau(double E_cuve) {
    Debit_eau = E_circuit * E_cuve * F_pompe * 90;
}

void circuitPrimaire::maj_Inertie(double TBore_eff, double TGraphite_eff, double T_vapeur) {
    // T_vapeur, c'est Temperature dans circuitSecondaire
    if (E_echangeur<50 & TBore_eff<25 & TGraphite_eff<50) {
        Inertie += RND(26.);
    }
    if (T_vapeur<Temperature) {
        Inertie += (T_vapeur-Temperature)/3.;
    }
    else {
        Inertie = std::max(0.,Inertie-RND(16.));
    }
}

void circuitPrimaire::maj_Temperature(double TBore_eff, double TGraphite_eff) {
    Temperature = std::max(25., 2*(0.5-TBore_eff)*(645*TGraphite_eff - 140*Debit_eau/90. + 2*Pression) + 26 + Inertie);
}

void circuitPrimaire::maj_Radioactivite(double TBore_eff, unsigned int MW) {
    Radioactivite = 98*(Debit_eau+1) + RND(90.) + (0.5-TBore_eff)*(MW+0.1)*6.54;
}

void circuitPrimaire::maj_T_pressuriseur_eff() {
    T_pressuriseur_eff += (T_pressuriseur_eff<T_pressuriseur) - (T_pressuriseur_eff>T_pressuriseur);
}


// les incréments et décréments
void circuitPrimaire::incr_T_pressuriseur() {
    if (T_pressuriseur<= (100*(E_pressuriseur+E_resistance)-1) ) T_pressuriseur +=1;
}

void circuitPrimaire::decr_T_pressuriseur() {
    if (T_pressuriseur>= 26) T_pressuriseur += -1;
}

void circuitPrimaire::incr_F_pompe() {
    if (F_pompe <= E_pompe - 0.05) F_pompe += 0.05;
}

void circuitPrimaire::decr_F_pompe() {
    if (F_pompe >= 0.05) F_pompe += -0.05;
}

//les dégradations
void circuitPrimaire::degr_E_circuit() {
    double E_enceinte = Centrale->get_E_enceinte();

    if (E_circuit>0.){

        if (Temperature>=420) {
            E_circuit += -RND(0.02);
        }
        if (Temperature>=40*Pression) {
            E_circuit += -RND(0.03);
        }
        if (Temperature>=50 & Pression>10) {
            E_circuit += -RND(0.02)*(RND(1.)<0.2);
        }
        if (Temperature>=50 & E_echangeur<0.6) {
            E_circuit += -RND(0.015)*(RND(1.)<0.3);
        }
        if (E_enceinte == 0.){
            E_circuit -= (0.1 + RND(0.1))*(RND(1.)>=0.2);
        }
    }
    if (E_circuit <=0.){
        E_circuit = 0.;
    }
}

void circuitPrimaire::degr_E_pompe() {
    if (E_pompe>0.){
        if (Temperature>=50 & E_circuit<0.58) {
            E_pompe += -RND(0.03)*(RND(1.)<0.5);
        }
    }

    if (E_pompe <=0.){
        E_pompe = 0.;
    }

}

void circuitPrimaire::degr_E_pressuriseur(){
    double E_enceinte = Centrale->get_E_enceinte();

    if (E_pressuriseur>0.){
        if(Temperature>=420){
            E_pressuriseur -= (RND(0.02))*(RND(1.)<0.3);
        }
        if (Temperature>=40*Pression) {
            E_pressuriseur -= RND(0.02);
        }
        if (E_enceinte == 0.){
            E_pressuriseur -= (0.1)*(RND(1.)>=0.2);
        }
    }

    if(E_pressuriseur<=0.){
        E_pressuriseur = 0.;
    }
}

void circuitPrimaire::degr_E_resistance(){
    double E_enceinte = Centrale->get_E_enceinte();

    if (E_resistance>0.){
        if(Temperature>=420){
            E_resistance -= (RND(0.02))*(RND(1.)<0.3);
        }
        if (Temperature>=40*Pression) {
            E_resistance -= RND(0.02)*(RND(1.)<0.3);
        }
        if ((Temperature>=50) && (E_pressuriseur<0.5)) {
            E_resistance -= RND(0.03)*(RND(1.)<0.8);
        }
        if ((E_enceinte == 0.) && (E_pressuriseur<0.9)){
            E_resistance -= (RND(0.1))*(RND(1.)>=0.2);
        }
    }

    if(E_resistance<=0.){
        E_resistance = 0.;
    }
}

void circuitPrimaire::degr_E_echangeur(){
    if (E_echangeur>0.){
        if((Temperature>=50) && (E_circuit<0.5)){
            E_echangeur -= RND(0.04)*(RND(1.)<0.4);
        }
    }

    if(E_echangeur<=0.){
        E_echangeur = 0.;
    }
}

/*
void circuitPrimaire::set_temp_pressuriseur(double valeur_demandee){

    double etat_p = get_etat_pressuriseur();
    double etat_r = get_etat_resistance(); 

    if((valeur_demandee>=25.)&&(valeur_demandee<=(etat_p + etat_r)*100)){
        temperature_press = valeur_demandee;
    }

    else{
        std::cout << " Erreur sur la température demandée pour le pressuriseur ! " << 
        std::endl;
    }
    
}
*/

