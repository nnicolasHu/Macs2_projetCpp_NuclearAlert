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
    void set_regime_pompe_cond(double valeur_demandee);

    /** 
     * @brief Permet d'obtenir le régime de la pompe du condensateur
     *
     * @return regime_pompe_condensateur
     */
    double get_regime_pompe_cond() const;

    /**
     * @brief Permet d'obtenir l'état du générateur de vapeur
     *
     * @return etat_gen_vapeur
     */
    double get_etat_gen_vapeur() const;

    /** 
     * @brief Permet d'obtenir l'état du condensateur
     *
     * @return etat_condensateur
     */
    double get_etat_condensateur() const;

    /** 
     * @brief Permet d'obtenir la temperature de la vapeur
     *
     * @return temperature_vap
     */
    double get_temp_vapeur() const;

    /**
     * @brief Permet d'obtenir la pression vapeur
     *
     * @return pression_vapeur
     */
    double get_pression_vapeur() const;

    /**
     * @brief Permet d'obtenir le débit d'eau au niveau du condensateur
     *
     * @return debit_cond
     */
    double get_debit_cond() const;

    /**
     * @brief Permet d'obtenir la différence de chaleur entre l'entrée et la sortie du condensateur
     *
     * @return delta_cond
     */
    double get_delta_cond() const;

private:
     /** Circuit **/
     circuit Cs;

     /** Etat du générateur de vapeur **/
     double etat_gen_vapeur;

     /** Etat du condensateur **/
     double etat_condensateur;

     /** Régime pompe condensateur **/
     double regime_pompe_condensateur;

     /** Température vapeur **/
     double temperature_vap;

     /** Pression exercée par la vapeur **/
     double pression_vapeur;

     /** Débit au niveau du condensateur **/
     double debit_cond;

     /** Différence de chaleur entre l'entrée et la sortie du condensateur **/
     double delta_cond;
};

#endif