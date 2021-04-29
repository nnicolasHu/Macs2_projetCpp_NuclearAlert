#ifndef _CIRCUIT_PRIMAIRE_HPP_
#define _CIRCUIT_PRIMAIRE_HPP_

#include <iostream>
#include "circuit.hpp"
#include "RND.hpp"

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

     circuitPrimaire( const circuitPrimaire& C ) = delete; // Interdiction de copier
     circuitPrimaire( circuitPrimaire&& C ) = delete; // Interdiction de déplacer

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
     double get_T_pressuriseur() const;

     /**
      * @brief Permet d'obtenir la température du pressuriseur actuel 
      *
      * @return T_pressuriseur_eff
      */
     double get_T_pressuriseur_eff() const;


     //////////////////////////////////////////////////////////////////////////////////////
     // comment doxygen à faire
     ////////////////////////////////////////////////////////////////////////////////////
     void set_E_pressuriseur(double etat);
     void set_E_resistance(double etat);
     void set_E_echangeur (double etat);

     /** 
      * @brief Permet d'ajuster la température du pressuriseur demandée
      *
      * @param[in] valeur_demandee La valeur demandée, comprise entre 25
      * et 100*(etat_pressuriseur + etat_resistance)
      */
     void set_T_pressuriseur(double temperature);



     void maj_Pression();
     void maj_Debit_eau(double E_cuve);
     void maj_Inertie(double TBore_eff, double TGraphite_eff, double T_vapeur);
     void maj_Temperature(double TBore_eff, double TGraphite_eff);
     void maj_Radioactivite(double TBore_eff, unsigned int MW);

     void maj_T_pressuriseur_eff();
     void incr_T_pressuriseur();
     void decr_T_pressuriseur();

     void incr_F_pompe();
     void decr_F_pompe();


     void degr_E_circuit();
     void degr_E_pompe();

private:
     /** Etat du pressuriseur **/
     double E_pressuriseur;

     /** Etat resistance pressuriseur **/
     double E_resistance;

     /** Etat de l'échangeur **/
     double E_echangeur;

     /** Température du pressuriseur demandé **/
     double T_pressuriseur;

     /** Température  du pressuriseur actuel **/
     double T_pressuriseur_eff;

};

#endif