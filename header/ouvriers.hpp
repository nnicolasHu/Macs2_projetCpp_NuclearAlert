#ifndef _OUVRIERS_HPP
#define _OUVRIERS_HPP

#include <array>
#include <algorithm>
#include "RND.hpp"

class ouvriers {
    public :

        /**
         * @brief Constructeur par défaut
         * 
         * Par défaut le nombre d'ouvriers disponble est de 145 et aucune réparation n'est effectuée.
         */
        ouvriers();

        /**
         * @brief Destructeur par défaut
         * 
         */
        ~ouvriers()=default;

        /**
         * @brief Renvoie la tâche actuelle de l'ouvrier i
         * 
         * @param[in] i Le i-ème ouvrier de la Centrale
         * 
         * @return Entier entre 1 et 7 permettant de connaître l'affectation de l'ouvrier.
         */
        int get_intervention(int i) const;

        /**
         * @brief Renvoie le statut de l'ouvrier i
         * 
         * @param[in] i Le i-ème ouvrier de la Centrale
         * 
         * @return Booléen permettant de savoir si oui ou non l'ouvrier i est apte à intervenir.
         */
        bool get_blesses(int i) const;

        /**
         * @brief Renvoie le nombre de jours de travail de l'ouvrier i
         * 
         * @param[in] i Le i-ème ouvrier de la Centrale
         * 
         * @return Le nombre de jours de travail de l'ouvrier i.
         */
        int get_compteur_jour(int i) const;

        /**
         * @brief Renvoie le nombre d'ouvriers en intervention sur un organe précis
         * 
         * @param[in] organe L'organe sur lequel la réparation a lieu.
         * 
         * @return Le nombre d'ouvriers occupés à réparer l'organe.
         */
        int get_nb_ouvriersEnIntervention(int organe) const;

        /**
         * @brief Renvoie le nombre d'ouvriers en intervention 
         * 
         * @return Le nombre d'ouvriers occupés à réparer divers organes de la Centrale.
         */
        int get_nb_ouvriersEnIntervention_tot() const;

        /**
         * @brief Renvoie le nombre d'ouvriers blessés 
         * 
         * @return Le nombre d'ouvriers blessés.
         */
        int get_nb_blesses() const;

        /**
         * @brief Renvoie le nombre d'ouvriers disponible 
         * 
         * @return Le nombre d'ouvriers disponible.
         */
        int get_nb_disponible() const;

        //test
        void set_intervention(int i, int organe);
        void set_blesses(int i, bool isHurt);
        void set_compteur_jour(int i, int jour);
        void set_nb_ouvriersEnIntervention(int organe, int nbOuvrier);
        void set_nb_blesses(int nb);
        void set_nb_disponible(int nb);

        /**
         * @brief Permet d'effectuer des réparations sur un organe.
         * 
         * @param[in] organe L'organe sur lequel on veut effectuer une réparation.
         * @param[in] nbOuvrier Le nombre d'ouvriers que l'on veut envoyer pour la réparation.
         */
        void envoie_intervention(int organe, int nbOuvrier);

        /**
         * @brief Permet d'arrêter les réparations sur un organe.
         * 
         * @param[in] organe L'organe sur lequel on veut arrêter la réparation.
         */
        void retrait_intervention(int organe);

        /**
         * @brief Permet de mettre à jour les données de la classe ouvriers
         * 
         * @param[in] dangereux Booléen permettant de savoir s'il y a danger ou non.
         * @param[in] dangereux_circuitPrimaire Booléen permettant de savoir s'il y a danger ou non dans le circuit primaire.
         */
        void maj_ouvriers(bool dangereux, bool dangereux_circuitPrimaire);



    private :

        /** Intervention **/
        std::array<int,145> intervention;

        /** Blessés **/
        std::array<bool,145> blesses;

        /** Jour d'activité **/
        std::array<int, 145> compteur_jour;

        /** Ouvriers en intervention par organe **/
        std::array<int,8> nb_ouvriersEnIntervention;

        /** Nombre de blessés **/
        int nb_blesses;

        /** Nombre d'ouvriers disponibles **/
        int nb_disponible;
    

};



#endif