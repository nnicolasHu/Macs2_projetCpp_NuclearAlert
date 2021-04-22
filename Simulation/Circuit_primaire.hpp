#ifndef _CIRCUIT_PRIMAIRE_HPP
#define _CIRCUIT_PRIMAIRE_HPP

#include "Circuit.hpp"

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
      * @brief  Destructeur par défaut
      *
      */
     ~circuitPrimaire() = default;

     /** 
      * @brief Permet d'ajuster la température du pressuriseur
      *
      * @param[in] valeur_demandee La valeur demandée, comprise entre 25
      * et 100*(etat_pressuriseur - etat_resistance)
      */
     void set_temp_pressuriseur(double valeur_demandee);

     /**
      * @brief Permet d'obtenir la température du pressuriseur
      *
      * @return temperature_press
      */
     double get_temp_pressuriseur() const;

     /**
      * @brief Permet d'obtenir l'état du pressuriseur
      *
      * @return etat_pressuriseur
      */
     double get_etat_pressuriseur() const;

     /**
      * @brief Permet d'obtenir l'état de la resistance du pressuriseur
      *
      * @return etat_resistance
      */
     double get_etat_resistance() const;

     /** 
      * @brief Permet d'obtenir l'état de l'échangeur de chaleur
      *
      * @return etat_echangeur
      */
     double get_etat_echangeur() const;

     /** 
      * @brief Permet d'obtenir la pression 
      *
      * @return pression
      */
     double get_pression() const;

     /**
      * @brief Permet d'obtenir la température de l'eau dans 
      * le circuit
      *
      * @return temperature
      */
     double get_temperature() const;

private:
     /** circuit **/
     circuit Cp;

     /** Etat du pressuriseur **/
     double etat_pressuriseur;

     /** Etat resistance pressuriseur **/
     double etat_resistance;

     /** Etat de l'échangeur **/
     double etat_echangeur;

     /** Température pressuriseur **/
     double temperature_press;

     /** Pression **/
     double pression;

     /** Température eau circuit **/
     double temperature;

};

#endif