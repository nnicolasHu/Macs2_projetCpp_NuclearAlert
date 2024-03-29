#ifndef _CIRCUIT_PRIMAIRE_HPP_
#define _CIRCUIT_PRIMAIRE_HPP_

#include <iostream>
#include "circuit.hpp"

/**
 * @brief    Cette classe décrit le circuit primaire.
 * 
 *  Le circuit primaire est composé d'un indicateur de l'état global du circuit, d'une pompe (composée d'un indicateur de régime, d'un indicateur de pression,
 *  d'un indicateur du débit), d'un préssuriseur (composé d'un indicateur de l'état de sa résistance, d'un indicateur de température réelle et de température
 *  demandée), d'un échangeur de chaleur, d'un indicateur de l'inertie de la température de l'eau dans le circuit, d'un indicateur de température 
 *  de l'eau dans le circuit, d'un indicateur de la radioactivité dans le circuit.
*/

class circuitPrimaire : public circuit
{

public:
     /** 
      * @brief  Constructeur par défaut
      *
      * Les paramètres d'etats sont initialisés à 1. La température du pressuriseur 
      * et la température de l'eau du circuit sont initialisées à 25°C.
      * La pression est initialisée à 1 bar. Le reste est initialisé à 0.
      *
      */
     circuitPrimaire();

     /**
      * @brief Constructeur de copie
      *
      */
     circuitPrimaire( const circuitPrimaire& C ) = delete;

     /**
      * @brief Constructeur de déplacement
      *
      */
     circuitPrimaire( circuitPrimaire&& C ) = delete;

     /**
      * @brief  Destructeur par défaut
      *
      */
     ~circuitPrimaire() = default;

     /**
      * @brief Permet d'obtenir l'état du pressuriseur
      *
      * @return E_pressuriseur
      */
     double get_E_pressuriseur() const;

     /**
      * @brief Permet d'obtenir l'état de la resistance du pressuriseur
      *
      * @return E_resistance
      */
     double get_E_resistance() const;

     /** 
      * @brief Permet d'obtenir l'état de l'échangeur de chaleur
      *
      * @return E_echangeur
      */
     double get_E_echangeur() const;

     /**
      * @brief Permet d'obtenir la température du pressuriseur demandée
      *
      * @return T_pressuriseur()
      */
     int get_T_pressuriseur() const;

     /**
      * @brief Permet d'obtenir la température du pressuriseur actuel 
      *
      * @return T_pressuriseur_eff
      */
     int get_T_pressuriseur_eff() const;


     void set_E_pressuriseur(double etat);
     void set_E_resistance(double etat);
     void set_E_echangeur (double etat);

     /** 
      * @brief Permet d'ajuster la température du pressuriseur demandée
      *
      * @param[in] valeur_demandee La valeur demandée, comprise entre 25
      * et 100*(etat_pressuriseur + etat_resistance)
      */
     void set_T_pressuriseur(int temperature);


     /**
      * @brief Permet de mettre à jour la pression du circuit Primaire
      *
      */
     void maj_Pression();

     /**
      * @brief Permet de mettre à jour le débit d'eau du circuit Primaire
      *
      * @param[in] E_cuve etat cuve reacteur
      */
     void maj_Debit_eau_1(double E_cuve);

     /**
      * @brief Permet de mettre à jour l'inertie du circuit Primaire
      *
      * @param[in] TBore_eff taux de bore réel
      * @param[in] TGraphite_eff taux de graphite réel
      * @param[in] T_vapeur température vapeur (circuit secondaire)
      */
     void maj_Inertie(double TBore_eff, double TGraphite_eff, double T_vapeur);

     /**
      * @brief Permet de mettre à jour la température du circuit Primaire
      *
      * @param[in] TBore_eff taux de bore réel
      * @param[in] TGraphite_eff taux de graphite réel
      */
     void maj_Temperature(double TBore_eff, double TGraphite_eff);

     /**
      * @brief Permet de mettre à jour la radioactivité du circuit Primaire
      *
      * @param[in] TBore_eff taux de bore réel
      * @param[in] MW production 
      */
     void maj_Radioactivite(double TBore_eff, unsigned int MW);

     void maj_T_pressuriseur_eff();
     void incr_T_pressuriseur();
     void decr_T_pressuriseur();


     /**
      * @brief Permet de simuler les dégradations de l'état du circuit
      *
      */
     std::string degr_E_circuit(double E_enceinte);

     /**
      * @brief Permet de simuler les dégradations de l'état de la pompe
      *
      */
     std::string degr_E_pompe();

     /**
      * @brief Permet de simuler les dégradations de l'état du pressuriseur
      *
      */
     std::string degr_E_pressuriseur(double E_enceinte);

     /**
      * @brief Permet de simuler les dégradations de l'état de la resistance du pressuriseur
      *
      */
     std::string degr_E_resistance(double E_enceinte);

     /**
      * @brief Permet de simuler les dégradations de l'état de l'échangeur de chaleur
      *
      */
     std::string degr_E_echangeur();

     /**
     * @brief Permet de réparer le circuit primaire
     * 
     * @return booléen, 1 si le circuit primaire est complètement réparé, 0 s'il est encore endommagé
     */
    bool reparation_circuitPrimaire();

    /**
     * @brief Permet de réparer le pressuriseur et la resistance
     * 
     * @return booléen, 1 si le pressuriseur et la resistance sont complètement réparés, 0 s'ils sont encore endommagés
     */
    bool reparation_pressuriseurANDresistance();

private:
     
     /** Etat du pressuriseur **/
     double E_pressuriseur;

     /** Etat resistance pressuriseur **/
     double E_resistance;

     /** Etat de l'échangeur **/
     double E_echangeur;

     /** Température du pressuriseur demandé **/
     int T_pressuriseur;

     /** Température  du pressuriseur actuel **/
     int T_pressuriseur_eff;

};

#endif