#ifndef _CIRCUIT_SECONDAIRE_HPP
#define _CIRCUIT_SECONDAIRE_HPP

#include "circuit.hpp"

/**
 *  @brief   Cette classe décrit le circuit secondaire.
 *
 *  Le circuit primaire est composé d'un indicateur de l'état global du circuit, d'une pompe (composée d'un indicateur de régime, d'un indicateur du débit),
 *  d'un générateur de vapeur (composé d'un indicateur de température, d'un indicateur de pression exercée par la vapeur), d'un condensateur 
 *  (composé d'un indcateur de l'état, d'un indicateur du régime de la pompe condensateur, d'un indicateur du différentiel de température entrée/sortie),
 *  d'un indicateur de l'inertie de la température de l'eau dans le circuit, d'un indicateur de la radioactivité dans le circuit.
 *
 */

class circuitSecondaire : public circuit
{

public:
    /** 
      * @brief  Constructeur par défaut
      *
      * Les paramètres d'etats sont initialisés à 1. La température vapeur est initialisée à 25°C.
      * La pression est initialisée à 1 bar. Le reste est initialisé à 0.
      *
      */
    circuitSecondaire();

    /**
     * @brief   Destructeur par défaut
     *
     */
    ~circuitSecondaire() = default;

    /** 
     * @brief Permet d'ajuster le régime de la pompe du condensateur
     *
     * @param[in] valeur_demandee La valeur demandée, comprise entre 0.
     * et l'état du condensateur
     */
    void set_F_condenseur(double valeur_demandee);

    void set_E_vapeur(double valeur_demandee);

    /** 
     * @brief Permet d'obtenir le régime de la pompe du condensateur
     *
     * @return regime_pompe_condensateur
     */
    double get_F_condenseur() const;

    /**
     * @brief Permet d'obtenir l'état du générateur de vapeur
     *
     * @return etat_gen_vapeur
     */
    double get_E_vapeur() const;

    /** 
     * @brief Permet d'obtenir l'état du condensateur
     *
     * @return etat_condensateur
     */
    double get_E_condenseur() const;

    /** 
     * @brief Permet d'obtenir la temperature de la vapeur
     *
     * @return temperature_vap
     */
    double get_T_vapeur() const;

    /**
     * @brief Permet d'obtenir la pression vapeur
     *
     * @return pression_vapeur
     */
    double get_P_vapeur() const;

    /**
     * @brief Permet d'obtenir le débit d'eau au niveau du condensateur
     *
     * @return debit_cond
     */
    double get_D_condenseur() const;

    /**
     * @brief Permet d'obtenir la différence de chaleur entre l'entrée et la sortie du condensateur
     *
     * @return delta_cond
     */
    double get_Delta_ES() const;

    /**
     * @brief met a jour les dégradations de l'état du générateur de vapeur
     */
    void degrad_E_vapeur(double E_chaleur);

    /**
     * @brief met a jour les dégradations de l'état du circuit secondaire
     */
    void degrad_E_circuit();

    /**
     * @brief met a jour les dégradations de l'état de la pompe
     */
    void degrad_E_pompe();

    /**
     * @brief met a jour TOUTES les dégradations du circuit secondaire
     */
    void degrad_all(double E_chaleur);

    /**
     * @brief met a jour les dégradations de l'état de l'échangeur de chaleur (communique avec circuitPrimaire)
     */
    void degrad_E_chaleur(double E_chaleur);

    

private:
    /*
      les attributs suivants sont hérités de circuit :
      - E_circuit | etat circuit
      - E_pompe | etat pompe
      - F_pompe | regime pompe 
      - Debit_eau 
      - Inertiertie | Inertie chaleur de l'eau du circuit
      - Radioactivite | radioactivité du circuit secondaire
    */
   
     /** Etat du générateur de vapeur **/
     double E_vapeur;

     /** Etat du condenseur **/
     double E_condenseur;

     /** Régime pompe condensateur **/
     double F_condenseur;

     /** Température vapeur **/
     double T_vapeur;

     /** Pression exercée par la vapeur **/
     double P_vapeur;

     /** Débit au niveau du condensateur **/
     double D_condenseur;

     /** Différence de chaleur entre l'entrée et la sortie du condensateur **/
     double Delta_ES;
};

#endif