#ifndef _OUVRIERS_HPP
#define _OUVRIERS_HPP

#include <array>
#include <algorithm>
#include "RND.hpp"

class ouvriers {
    public :
        ouvriers();
        ~ouvriers()=default;
        
        int get_intervention(int i) const;
        bool get_blesses(int i) const;
        int get_compteur_jour(int i) const;

        int get_nb_ouvriersEnIntervention(int organe) const;
        int get_nb_blesses() const;
        int get_nb_disponible() const;

        //test
        void set_intervention(int i, int organe);
        void set_blesses(int i, bool isHurt);
        void set_compteur_jour(int i, int jour);
        void set_nb_ouvriersEnIntervention(int organe, int nbOuvrier);
        void set_nb_blesses(int nb);
        void set_nb_disponible(int nb);

        void envoie_intervention(int organe, int nbOuvrier);
        void retrait_intervention(int organe);

        void maj_ouvriers(bool dangereux, bool dangereux_circuitPrimaire);



    private :
        std::array<int,145> intervention;
        std::array<bool,145> blesses;
        std::array<int, 145> compteur_jour;

        std::array<int,8> nb_ouvriersEnIntervention;
        int nb_blesses;
        int nb_disponible;
    

};



#endif