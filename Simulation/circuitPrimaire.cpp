#include "circuitPrimaire.hpp"
#include "RND.hpp"

/** Constructeur(s) **/

circuitPrimaire::circuitPrimaire() {
    circuit();
    E_pressuriseur = 1.;
    E_resistance = 1.;
    E_echangeur = 1.;
    T_pressuriseur = 25;
    T_pressuriseur_eff = 25;
}

// commentaire pour push

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

int circuitPrimaire::get_T_pressuriseur() const{
    return T_pressuriseur;
}

int circuitPrimaire::get_T_pressuriseur_eff() const{
    return T_pressuriseur_eff;
}


// les setters
void circuitPrimaire::set_E_pressuriseur(double etat) {
    if (etat>=0 && etat<=1) E_pressuriseur=etat;
}

void circuitPrimaire::set_E_resistance(double etat) {
    if (etat>=0 && etat<=1) E_resistance=etat;
}

void circuitPrimaire::set_E_echangeur(double etat) {
    if (etat>=0 && etat<=1) E_echangeur=etat;
}

void circuitPrimaire::set_T_pressuriseur(int temperature) {
    if (temperature>=25 && temperature<=100*(E_pressuriseur + E_resistance)) T_pressuriseur=temperature;
}



// les mises a jour
void circuitPrimaire::maj_Pression() {
    Pression = std::max((T_pressuriseur_eff - 25.)/3.24 + (Temperature - 100.)/83.3 * (E_circuit + 0.1)*(E_echangeur + 0.1), 1.);
}

void circuitPrimaire::maj_Debit_eau_1(double E_cuve){
    Debit_eau = E_circuit * E_cuve * F_pompe * 90;
}

void circuitPrimaire::maj_Inertie(double TBore_eff, double TGraphite_eff, double T_vapeur) {
    // T_vapeur, c'est Temperature dans circuitSecondaire
    if (E_echangeur<50 && TBore_eff<25 && TGraphite_eff<50) {
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

//les dégradations
std::string circuitPrimaire::degr_E_circuit(double E_enceinte) {
    std::string alerte;

    if (Temperature>=420) {
        E_circuit += -RND(0.02);
        alerte += "Risque important de dégradation du circuit primaire dû à la température\n"s;
    }
    else if (Temperature>400) {
        alerte += "Température trop élevée dans le circuit primaire\n"s;
    }
    if (Temperature>=40*Pression) {
        E_circuit += -RND(0.03);
        alerte += "Risque important de dégradation du circuit primaire dû à la formation de vapeur\n"s;
    }
    if (Temperature>=50 && Pression>10) {
        E_circuit += -RND(0.02)*(RND(1.)<0.2);
        alerte += "Risque faible de dégradation du circuit primaire dû à une pression trop forte\n"s;
    }
    if (Temperature>=50 && E_echangeur<0.6) {
        E_circuit += -RND(0.015)*(RND(1.)<0.3);
        alerte += "Risque faible de dégradation faible du circuit primaire\n"s;
    }
    if (E_enceinte == 0.){ //faire une méthode pour la déstruction totale?
        E_circuit -= (0.1 + RND(0.1))*(RND(1.)>=0.2);
    }
    
    if (E_circuit <=0.){
        E_circuit = 0.;
    }

    return alerte;
}

std::string circuitPrimaire::degr_E_pompe() {
    std::string messageErreur = "";
    if (E_pompe>0.){
        if (Temperature>=50 && E_circuit<0.58) {
            messageErreur += "Risque important de dégradation de la pompe du circuit primaire \n"s;
            E_pompe += -RND(0.03)*(RND(1.)<0.5);
        }
    }

    if (E_pompe <=0.){
        E_pompe = 0.;
    }
    return messageErreur;
}

std::string circuitPrimaire::degr_E_pressuriseur(double E_enceinte){
    std::string messageErreur = "";
    if (E_pressuriseur>0.){
        if(Temperature>=420){
            messageErreur += "Dégradation possible du pressuriseur \n"s;
            E_pressuriseur -= (RND(0.02))*(RND(1.)<0.3);
        }
        if (Temperature>=40*Pression) {
            messageErreur += "Risque important de dégradation du pressuriseur dû à la formation de vapeur dans le circuit primaire \n"s;
            E_pressuriseur -= RND(0.02);
        }
        if (E_enceinte == 0.){
            E_pressuriseur -= (0.1)*(RND(1.)>=0.2);
        }
    }

    if(E_pressuriseur<=0.){
        E_pressuriseur = 0.;
    }
    return messageErreur;
}

std::string circuitPrimaire::degr_E_resistance(double E_enceinte){
    std::string messageErreur = "";
    if (E_resistance>0.){
        if(Temperature>=420){
            messageErreur += "Dégradation possible du pressuriseur \n"s;
            E_resistance -= (RND(0.02))*(RND(1.)<0.3);
        }
        if (Temperature>=40*Pression) {
            messageErreur += "Risque important de dégradation du circuit primaire dû à la formation de vapeur dans le circuit primaire \n"s;
            E_resistance -= RND(0.02)*(RND(1.)<0.3);
        }
        if ((Temperature>=50) && (E_pressuriseur<0.5)) {
            messageErreur += "Risque très important de dégradation de la résistance du pressuriseur \n"s;
            E_resistance -= RND(0.03)*(RND(1.)<0.8);
        }
        if ((E_enceinte == 0.) && (E_pressuriseur<0.9)){
            messageErreur += "Affiche détérioration importante du circuit primaire et du pressuriseur \n"s;
            E_resistance -= (RND(0.1))*(RND(1.)>=0.2);
        }
    }

    if(E_resistance<=0.){
        E_resistance = 0.;
    }
    return messageErreur;
}

std::string circuitPrimaire::degr_E_echangeur(){
    std::string messageErreur = "";
    if (E_echangeur>0.){
        if((Temperature>=50) && (E_circuit<0.5)){
            messageErreur += "Risque important de dégradation de l’échangeur de chaleur \n"s;
            E_echangeur -= RND(0.04)*(RND(1.)<0.4);
        }
    }

    if(E_echangeur<=0.){
        E_echangeur = 0.;
    }
    return messageErreur;
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

bool circuitPrimaire::reparation_circuitPrimaire(){
    bool reparation_reussie = false;

    if (RND(1.0) <= 0.3){ // lancer des 30% 
        if (this->get_E_circuit() < 0.80){ // E_circuit < 0.80 est le seul cas où on répare
            double reparation = RND(0.02);
            this->set_E_circuit(this->get_E_circuit() + reparation);
        }
    }

    if (this->get_E_circuit() >= 0.8){
        reparation_reussie = 1;
    }
    return reparation_reussie;
}

bool circuitPrimaire::reparation_pressuriseurANDresistance(){
    bool reparation_reussie = false;

    if (RND(1.0) <= 0.3){ // lancer des 30% 
        if(this->get_E_pressuriseur() < 0.97){
            double reparation_pres = RND(0.03);
            double reparation_resis = RND(0.04);
            this->set_E_pressuriseur(this->get_E_pressuriseur() + reparation_pres);
            if (this->get_E_resistance() + reparation_resis > this->get_E_pressuriseur()){
                this->set_E_resistance(this->get_E_pressuriseur()); 
            }
            else{
                this->set_E_pressuriseur(this->get_E_resistance() + reparation_resis);
            }
        } 
        else{
            this->set_E_pressuriseur(1);
            this->set_E_resistance(1);
        }
    }

    if ( (this->get_E_pressuriseur() == 1) && (this->get_E_resistance() == 1) ){
        reparation_reussie = 1;
    }

    return reparation_reussie;
}