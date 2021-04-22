#ifndef _CENTRALE_HPP
#define _CENTRALE_HPP

/**
 * @brief    Cette classe décrit la centrale du point de vue de son état.
 * 
 * La centrale est composée d'une enceinte de confinement (comportant des indices de pression et de radioactivité à l'intérieur). 
 * Elle aussi caractérisée par son état et sa production.
*/
class centrale{

public:

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
     * @return etat_enceinte
     */
    double get_etat_enceinte();

    /** 
     * @brief Permet d'obtenir l'état de la centrale
     *
     * @return etat_centrale
     */
    double get_etat_centrale();

    /**
     * @brief Permet d'obtenir la pression subit par l'enceinte
     *
     * @return pression_enceinte
     */
    double get_pression();

    /**
     * @brief Permet d'obtenir la production de la centrale
     *
     * @return production
     */
    double get_production();

    /**
     * @brief Permet d'obtenir la radioactivité à l'intérieur de l'enceinte
     *
     * @return radioactivité
     */
    double get_radioactivite();


private:

    /** Etat de l'enceinte **/
    double etat_enceinte;

    /** Pression subit par l'enceinte de confinement **/
    double pression_enceinte;

    /** Radioactivité à l'intérieur de l'enceinte **/
    double radioactivité;

    /** Etat général de la centrale **/
    double etat_centrale;

    /** Production de la centrale **/
    double production;
    
    
};


#endif