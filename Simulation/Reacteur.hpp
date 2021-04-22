#ifndef _REACTEUR_HPP
#define _REACTEUR_HPP


/**
 * @brief    Cette classe décrit le réacteur.
 *
 *  Le réacteur est composé de barres de graphites (contrôle de la proportion de barres immergées et comparaison avec la proportion demandée, 
 *  indicateur d'état des barres), d'une piscine (indicateur radiation et état), d'une cuve (indicateur d'état) et de canaux guidant les barres de graphite
 *  (indicateur d'état des canaux). Il faut aussi pouvoir contrôler le taux de bord dans l'eau du circuit (indicateur proportion actuelle/demandée,
 *  indicateur de l'état des injecteurs d'acide borique).
 *
 *  À chaque pas de temps, si le taux de Bore demandé est différent du taux actuel, l'incrémentation se fait de 0.01 en 0.01.
 *  Le fonctionnement est le même pour la proportion de graphite non-immergée.
 */

class reacteur{


public:
     /**
      * @brief Constructeur par défaut
      *
      * Les paramètres d'etats sont initialisés à 1. Le taux de bore initial est de 0.47 (il varie entre 0 et 0.5 %). Les barres de graphites sont 
      * initialement immergées. 
      *
      */
     reacteur();

     /** 
      * @brief Destructeur par défaut
      *
     */
     ~reacteur() = default;

     
     
     /**
     * @brief Permet d'ajuster le taux de bore 
     * dans l'eau du circuit
     *
     * @param[in] valeur_demandee La valeur demandée, comprise entre 0 et 0.5.
     */
     void set_bore(double valeur_demandee);

     /**
     * @brief Permet d'obtenir le taux de bore
     * dans l'eau du circuit
     *
     * @return taux
     */
     double get_bore();

     /** 
     * @brief Permet d'obtenir l'état des injecteurs
     * d'acide borique
     *
     * @return etat_injecteur
     */
     double get_injecteur();
    
     /**
     * @brief Permet d'ajuster la proportion des barres de graphite
     * hors de l'eau
     *
     * @param[in] valeur_demandee La proportion des barres de graphite à laisser hors de l'eau,
     * qui doit être comprise entre 1 - etat_barre et 1.
     */
     void set_graphite(double valeur_demandee);

     /**
     * @brief Permet d'obtenir la proportion des barres de graphite
     * hors de l'eau
     *
     * @return proportion_graphite
     */
     double get_graphite();

     /**
     * @brief Permet d'obtenir l'état des barres de graphite
     *
     * @return etat_graphite
     */
     double get_barre();

     /**
     * @brief Permet d'obtenir l'état de la cuve
     *
     * @return etat_cuve
     */
     double get_cuve();

     /**
     * @brief Permet d'obtenir l'état de la piscine
     *
     * @return etat_piscine
     */
     double get_piscine();

     /**
     * @brief Permet d'obtenir l'état des canaux
     *
     * @return etat_canaux
     */
     double get_canaux();

     /**
     * @brief Permet d'obtenir les radiations de la piscine
     *
     * @return radiation_piscine
     */
     double get_radiation();


private:
     /** Etat de la cuve **/
     double etat_cuve;
    
     /** Radiation de la piscine [ (1.-Ecuve)*R1 +100 + RND(45) ]**/
     double radiation_piscine;

     /** Etat de la piscine **/
     double etat_piscine;

     /** Etat des canaux **/
     double etat_canaux;

     /** Taux de bore **/
     double taux;

     /** Etat des injecteurs **/
     double etat_injecteur;

     /** Proportion de graphite hors de l'eau **/
     double proportion_graphite;

     /** Etat des barres de graphite **/
     double etat_graphite;
     

};

#endif
