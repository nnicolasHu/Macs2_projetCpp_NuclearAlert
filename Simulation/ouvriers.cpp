#include "ouvriers.hpp"

ouvriers::ouvriers() {
    std::fill(intervention.begin(), intervention.end(),10);
    blesses = {0};
    compteur_jour = {0};
    nb_ouvriersEnIntervention = {0};
    nb_blesses = 0;
    nb_disponible = 145;
}


int ouvriers::get_intervention(int i) const {
    return intervention[i];
}
bool ouvriers::get_blesses(int i) const {
    return blesses[i];
}
int ouvriers::get_compteur_jour(int i) const {
    return compteur_jour[i];
}

int ouvriers::get_nb_ouvriersEnIntervention(int organe) const {
    return nb_ouvriersEnIntervention[organe];
}

int ouvriers::get_nb_blesses() const {
    return nb_blesses;
}

int ouvriers::get_nb_disponible() const {
    return nb_disponible;
}

//test
void ouvriers::set_intervention(int i, int organe) {
    intervention[i] = organe;
}
void ouvriers::set_blesses(int i, bool isHurt) {
    blesses[i] = isHurt;
}
void ouvriers::set_compteur_jour(int i, int jour) {
    compteur_jour[i] = jour;
}
void ouvriers::set_nb_ouvriersEnIntervention(int organe, int nbOuvrier) {
    nb_ouvriersEnIntervention[organe] = nbOuvrier;
}
void ouvriers::set_nb_blesses(int nb) {
    nb_blesses = nb;
}
void ouvriers::set_nb_disponible(int nb) {
    nb_disponible = nb;
}

void ouvriers::envoie_intervention(int organe,int nbOuvrier) {
    if (nbOuvrier <= nb_disponible) {
        int curseur = 0;
        for (int i=0; i<nbOuvrier; i++) {
            while (intervention[curseur]!=10) {
                curseur++;
            }
            intervention[curseur]=organe;
        }
        nb_disponible += -nbOuvrier;
        nb_ouvriersEnIntervention[organe] = nbOuvrier;
    }
}

void ouvriers::retrait_intervention(int organe) {
    int curseur = 0;
    for (int i=0; i<nb_ouvriersEnIntervention[organe]; i++) {
        while(intervention[curseur]!=organe) {
            curseur++;
        }
        intervention[curseur] = 10;
    }
    nb_disponible += nb_ouvriersEnIntervention[organe];
    nb_ouvriersEnIntervention[organe] = 0;
}

void ouvriers::maj_ouvriers(bool dangereux, bool dangereux_circuitPrimaire) {
    for (int i=0; i<145; i++) {
        //gestion : est ce que l'ouvrier guéri?
        compteur_jour[i] += blesses[i];
        if (compteur_jour[i]==8) {
            compteur_jour[i]=0;
            if (RND(1.0)<0.4) {
                blesses[i] = 0;
                nb_disponible += 1;
                nb_blesses += -1;
            }
        }
        // gestion : est ce que l'ouvrier est blessé?
        if (dangereux) {
            for (int i=0; i<145; i++) {
                if (intervention[i]!=-1 && intervention[i]!=10) {
                    intervention[i] = -1;
                    blesses[i] = 1;
                    nb_blesses++;
                }
            }
            std::fill(nb_ouvriersEnIntervention.begin(),nb_ouvriersEnIntervention.end(),0);
        }
        else {
            if (intervention[i]==3) { //ouvrier sur le générateur de vapeur
                if (compteur_jour[i]==5) {
                    if (RND(1.)<0.1) {
                        intervention[i] = -1;
                        blesses[i] = 1;
                        nb_blesses +=1;
                        nb_ouvriersEnIntervention[3] += -1;
                    }
                    compteur_jour[i] = 0;
                }
                else {
                    compteur_jour[i]++;
                }
            }
            if (dangereux_circuitPrimaire && intervention[i]==5) { //quand le circuit primaire est dangereux
                intervention[i] = -1;
                blesses[i] = 1;
                nb_blesses++;
                nb_ouvriersEnIntervention[5] += -1;
            }
        }
    }
}