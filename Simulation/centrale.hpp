#ifndef _CENTRALE_HPP
#define _CENTRALE_HPP

#include <memory>

#include "centrale_abstract.hpp"
#include "reacteur.hpp"
#include "circuitPrimaire.hpp"
#include "circuitSecondaire.hpp"

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

    /**
     * @brief Permet de mettre à jour la pression de l'enceinte
     * 
     */
    void maj_pression_enceinte();

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
     * @brief Maj de toutes les maj et degradations du circuit primaire
     * 
     */
    void maj_Circuit_Secondaire();


private:
    static centrale* la_centrale;
    
    /** Reacteur **/
    std::unique_ptr<reacteur> Reacteur;

    /** Circuit Primaire **/
    std::unique_ptr<circuitPrimaire> Circuit_Primaire;

    /** Circuit Primaire **/
    std::unique_ptr<circuitSecondaire> Circuit_Secondaire;

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
    
    
};


#endif
