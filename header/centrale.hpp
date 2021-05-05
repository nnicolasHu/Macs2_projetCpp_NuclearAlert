#ifndef _CENTRALE_HPP
#define _CENTRALE_HPP

#include <memory>

#include "reacteur.hpp"
#include "circuitPrimaire.hpp"
#include "circuitSecondaire.hpp"
#include "ouvriers.hpp"

/**
 * @brief    Cette classe décrit la centrale dans sa globalité.
 * 
 * La centrale est composée d'une enceinte de confinement (comportant des indices de pression et de radioactivité à l'intérieur). 
 * Elle aussi caractérisée par son état et sa production.
 * En plus de ça, elle est composée d'un reacteur, d'un circuit primaire et secondaire.
 * 
*/

class centrale : public centrale_abstract
{

public:
    // Design pattern : Singleton
    static centrale& get();

    /**
     * @brief Constructeur par défaut.
     *
     * Les paramètres d'état sont initialisés à 1. La pression au coeur de l'enceinte
     * est initialiséé à 1 bar. La production est initialement nulle. 
     * La radioactivité à l'intérieur de l'enceinte est de 0.00002 rem/h.
     */
    centrale();

    /**
      * @brief Constructeur de copie
      * 
      */
    centrale( const centrale& C ) = delete; 

    /**
      * @brief Constructeur de déplacement
      * 
      */
    centrale( centrale&& C ) = delete; 

    /** 
     * @brief  Destructeur par défaut.
     *
     */
    ~centrale() = default;

    /** 
     * @brief Permet d'obtenir l'état de l'enceinte 
     *
     * @return E_enceinte
     */
    double get_E_enceinte() const override;

    /** 
     * @brief Permet d'obtenir l'état de la centrale
     *
     * @return E_centrale
     */
    double get_E_centrale() const override;

    /**
     * @brief Permet d'obtenir la pression subit par l'enceinte
     *
     * @return P_enceinte
     */
    double get_P_enceinte() const override;

    /**
     * @brief Permet d'obtenir la production de la centrale
     *
     * @return MW
     */
    double get_MW() const override;

    /**
     * @brief Permet d'obtenir la radioactivité à l'intérieur de l'enceinte
     *
     * @return R_enceinte
     */
    double get_R_enceinte() const override;

    std::unique_ptr<reacteur> get_Reacteur() const;
    circuitPrimaire& get_Circuit_Primaire() const;
    circuitSecondaire& get_Circuit_Secondaire() const;
    ouvriers& get_Ouvriers() const;

    /** Test **/
    void set_E_enceinte(double val);
    void set_P_enceinte(double val);
    void set_R_enceinte(double val);
    void set_E_centrale(double val);
    void set_MW(int val);
    void set_Evac(double val);
    void set_R_air(double val);
    void set_R_eau(double val);
    void set_Contamination(int val);




    /**
     * @brief Permet de mettre à jour la pression de l'enceinte
     * 
     */
    void maj_P_enceinte();

    /**
     * @brief Permet de mettre à jour la radioactivité de l'enceinte
     * 
     */
    void maj_R_enceinte();

    /**
     * @brief Permet de mettre à jour l'état de la centrale
     * 
     */
    void maj_E_centrale();

    /**
     * @brief Permet de mettre à jour la production
     * 
     */
    void maj_MW();

    /**
     * @brief Permet de simuler les dégradations sur l'enceinte de
     * confinement
     *
     */
    void degr_E_enceinte();

    /**
     * @brief Maj de toutes les maj et degradations du reacteur
     * 
     */
    void maj_Reacteur();
    
    /**
     * @brief Maj de toutes les maj et degradations du circuit primaire
     * 
     */
    void maj_Circuit_Primaire(); 

    /**
     * @brief Maj de toutes les maj et degradations du circuit secondaire
     * 
     */
    void maj_Circuit_Secondaire(); 

    /**
     * @brief Maj de toutes les maj et degradations de la centrale
     * 
     * ON FAIT AUSSI, EN APPELANT maj_Centrale(), UNE MAJ SUR LE POPULATION (maj_Centrale() fait appel à maj_Population())
     * 
     */
    void maj_Centrale(); 

    /**
     * @brief Renvoie la variable Evac
     * 
     * @return Evac
     */
    double get_Evac() const;

    /**
     * @brief Renvoie la variable Order
     * 
     * @return Order
     */
    int get_Order() const;

    /**
     * @brief Permet de donner l'ordre d'évacuer
     * 
     * @param[in] entier soit 0 soit 1.
     */
    void set_Order(int entier);

    /**
     * @brief Renvoie la radioactivité de l'air 
     * 
     * @return R_air
     */
    double get_R_air() const;

    /**
     * @brief Renvoie la radioactivité de l'eau 
     * 
     * @return R_eau
     */
    double get_R_eau() const;

    /**
     * @brief Renvoie la contamination 
     * 
     * @return Contamination
     */
    int get_Contamination() const;

    /**
     * @brief Mise à jour de l'évacuation
     * 
     * @return Evac
     */
    void maj_Evac();

    /**
     * @brief Mise à jour de la radioactivité de l'air
     * 
     * @return R_air
     */
    void maj_R_air();

    /**
     * @brief Mise à jour de la radioactivité de l'eau
     * 
     * @return R_eau
     */
    void maj_R_eau();

    /**
     * @brief Mise à jour de la contamination
     * 
     * @return Contamination
     */
    void maj_Contamination();

    /**
     * @brief Mise à jour des variables liées à la population
     * 
     * @return Contamination
     */
    void maj_Population();

    void envoie_intervention(int organe);
    void maj_Reparation();

private:
    static centrale* la_centrale;
    
    /** Reacteur **/
    std::unique_ptr<reacteur> ptrReacteur;

    /** Circuit Primaire **/
    std::unique_ptr<circuitPrimaire> ptrCircuit_Primaire;

    /** Circuit Secondaire **/
    std::unique_ptr<circuitSecondaire> ptrCircuit_Secondaire;

    /** Classe des ouvriers **/
    std::unique_ptr<ouvriers> ptrOuvriers;

    /** Etat de l'enceinte **/
    double E_enceinte;

    /** Pression subit par l'enceinte de confinement **/
    double P_enceinte;

    /** Radioactivité à l'intérieur de l'enceinte **/
    double R_enceinte;

    /** Etat général de la centrale **/
    double E_centrale;

    /** Production de la centrale **/
    unsigned int MW;

    /** Population evacuée **/
    double Evac;

    /** Ordre evacuation, 0 : pas d'evacuation, 1 : ordre d'évacuer  **/ 
    int Order;

    /** Radioactivité air **/
    double R_air;

    /** Radioactivité eau **/
    double R_eau;

    /** Contamination **/
    unsigned int Contamination;
    
    
};


#endif
