#ifndef _REACTEUR_HPP
#define _REACTEUR_HPP

#include <memory>
#include <string>
using namespace std::string_literals; 


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
      * @brief Constructeur de copie
      * 
      */
     reacteur( const reacteur& R ) = delete; // Interdiction de copier

     /**
      * @brief Constructeur de déplacement
      * 
      */
     reacteur( reacteur&& R ) = delete; // Interdiction de déplacer

     /** 
      * @brief Destructeur par défaut
      *
     */
     ~reacteur() = default;
 
     /**
     * @brief Permet d'obtenir la proportion des barres de graphite
     * hors de l'eau demandée
     *
     * @return Tx_graphite
     */
     double get_Tx_graphite() const;  

     /**
     * @brief Permet d'obtenir la proportion des barres de graphite
     * hors de l'eau effective
     *
     * @return TGraphite_eff
     */
     double get_TGraphite_eff() const;
     
     /**
     * @brief Permet d'obtenir le taux de bore demandée
     * dans l'eau du circuit 
     *
     * @return Tx_bore
     */
     double get_Tx_bore() const;

     /**
     * @brief Permet d'obtenir le taux de bore effective
     * dans l'eau du circuit 
     *
     * @return TBore_eff
     */
     double get_TBore_eff() const;

     /** 
     * @brief Permet d'obtenir l'état des injecteurs
     * d'acide borique
     *
     * @return E_bore
     */
     double get_E_bore() const;


     /**
     * @brief Permet d'obtenir l'état des barres de graphite
     *
     * @return E_barre
     */
     double get_E_barre() const;

     /**
     * @brief Permet d'obtenir l'état de la cuve
     *
     * @return E_cuve
     */
     double get_E_cuve() const;

     /**
     * @brief Permet d'obtenir l'état de la piscine
     *
     * @return E_piscine
     */
     double get_E_piscine() const;

     /**
     * @brief Permet d'obtenir l'état des canaux
     *
     * @return E_canaux
     */
     double get_E_canaux() const;

     /**
     * @brief Permet d'obtenir les radiations de la piscine
     *
     * @return R_piscine
     */
     double get_R_piscine() const;

     /**
     * @brief Permet d'incrémenter le Tx_bore
     *
     */
     void incr_bore();

     /**
     * @brief Permet de décrémenter le Tx_bore
     *
     */
     void decr_bore();

     /**
     * @brief Permet de mettre à jour le TBore_eff en fonction du Tx_bore
     *
     */
     void maj_bore();
    
     /**
     * @brief Permet d'ajuster la proportion des barres de graphite
     * hors de l'eau (ne sert que pour la tentative d'arrêt d'urgence)
     *
     * @param[in] valeur_demandee La proportion des barres de graphite à laisser hors de l'eau,
     * qui doit être comprise entre 1 - etat_barre et 1.
     */
     void set_graphite(double valeur_demandee);

     /**
     * @brief Permet d'incrémenter le Tx_bore
     *
     */
     void incr_graphite();

     /**
     * @brief Permet de décrémenter le Tx_bore
     *
     */
     void decr_graphite();

     /**
     * @brief Permet de mettre à jour le TBore_eff en fonction du Tx_bore
     *
     */
     void maj_graphite();

     /**
     * @brief Permet de mettre à jour les radiations de la piscine
     *
     * @param[in] R1 Radiation circuit primaire
     */
     void maj_R_piscine(double R1);

     /**
     * @brief Permet de simuler les dégradations sur l'état de la cuve
     *
     * @param[in] T1 Temperature circuit primaire
     * @param[in] E_circuit_primaire Etat circuit primaire
     * @param[in] E_enceinte Etat enceinte
     */
     std::string degr_E_cuve(double T1, double E_circuit_primaire, double E_enceinte);

     /**
     * @brief Permet de simuler les dégradations sur l'état de la piscine
     *
     * @param[in] T1 Temperature circuit primaire
     * @param[in] E_circuit_primaire Etat circuit primaire
     * @param[in] E_enceinte Etat enceinte
     */
     std::string degr_E_piscine(double T1, double E_circuit_primaire,double E_enceinte);

     /**
     * @brief Permet de simuler les dégradations sur l'état des
     * barres de graphite
     *
     * @param[in] T1 Temperature circuit primaire
     */
     std::string degr_E_barre(double T1);

     /**
     * @brief Permet de simuler les dégradations sur l'état des
     * canaux
     *
     * @param[in] T1 Temperature circuit primaire
     */
     std::string degr_E_canaux(double T1);

     /**
     * @brief Permet de simuler les dégradations sur l'état des
     * injecteurs boriques
     *
     * @param[in] T1 Temperature circuit primaire
     * @param[in] E_circuit_primaire Etat circuit primaire
     */
     std::string degr_E_bore(double T1, double E_circuit_primaire);

     /**
      * @brief Permet d'effectuer les réparations sur l'injecteur borique
      * 
      * @return booléen, 1 si l'injecteur est complètement réparé, 0 s'il est encore endommagé
      */
     bool repa_E_bore();

     /**
     * @brief Permet d'effectuer la tentative d'arrêt d'urgence
     * 
     * @return booléen permettant de savoir si la tenatative d'arrêt d'urgence doit dégrader des éléments du réacteur
     */
     bool arret_urgence();


private:

     /** Taux de graphite hors de l'eau demandé **/
     double Tx_graphite;

     /** Taux de graphite hors de l'eau actuel **/
     double TGraphite_eff;

     /** Taux de bore demandé **/
     double Tx_bore;

     /** Taux de bore actuel **/
     double TBore_eff;

     /** Etat de la cuve **/
     double E_cuve;

     /** Radiation piscine **/
     double R_piscine;

     /** Etat piscine **/
     double E_piscine;

     /** Etat barre **/
     double E_barre;

     /** Etat canaux **/
     double E_canaux;

     /** Etat bore **/
     double E_bore;

     /** Variable booléenne tentative d'arrêt urgence **/
     bool urg;
     

};

#endif
