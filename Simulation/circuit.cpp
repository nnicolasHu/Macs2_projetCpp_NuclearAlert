#include "circuit.hpp"
#include "RND.hpp"


/** Constructeur **/

circuit::circuit() {
    E_circuit = 1.;
    Pression = 1.;
    Debit_eau = 0.;
    Inertie = 0.;
    Temperature = 25.;
    Radioactivite = 0.;
    E_pompe = 1.;
    F_pompe = 0.;
}

/** Méthodes **/

// les getters
double circuit::get_E_circuit() const {
    return E_circuit;
}

double circuit::get_Pression() const {
    return Pression;
}

double circuit::get_Debit_eau() const {
    return Debit_eau;
}

double circuit::get_Inertie() const {
    return Inertie;
}

double circuit::get_Temperature() const {
    return Temperature;
}

double circuit::get_Radioactivite() const {
    return Radioactivite;
}

double circuit::get_E_pompe() const {
    return E_pompe;
}

double circuit::get_F_pompe() const {
    return F_pompe;
}


// les setters
void circuit::set_E_circuit(double etat) {
    if (etat>=0 && etat<=1) E_circuit=etat;
}

void circuit::set_E_pompe(double etat) {
    if (etat>=0 && etat<=1) E_pompe=etat;
}

void circuit::set_F_pompe(double regime) {
    if (regime>=0 && regime<=this->E_pompe) F_pompe=regime;
}

// les incréments et décréments
void circuit::incr_F_pompe() {
    if (F_pompe < E_pompe) F_pompe += 0.05;
}

void circuit::decr_F_pompe() {
    if (F_pompe > 0.02) F_pompe += -0.05;
}

bool ::circuit::reparation_pompe(){
    double reparation_reussi = false; 

    if (RND(1.0) <= 0.3){ // lancer des 30% 

        double reparation = RND(0.03); // tirage de réparation
        this->set_E_pompe(this->get_E_pompe() + reparation);

        if (this->get_E_pompe() > 0.97){
            this->set_E_pompe(1);
            reparation_reussi = true;
        }
    }

    return (reparation_reussi);  // soit c'est réparé, soit non 
}

void circuit::maj_Debit_eau(){
    std::cout << "méthode virtuel" << std::endl;
}