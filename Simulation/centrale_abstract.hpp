#ifndef _CENTRALE_ABSTRACT_HPP_
#define _CENTRALE_ABSTRACT_HPP_

class centrale_abstract{

public : 
    /** 
     * @brief Permet d'obtenir l'état de l'enceinte 
     *
     * @return etat_enceinte
     */
    virtual double get_etat_enceinte() const = 0;

    /** 
     * @brief Permet d'obtenir l'état de la centrale
     *
     * @return etat_centrale
     */
    virtual double get_etat_centrale() const = 0;

    /**
     * @brief Permet d'obtenir la pression subit par l'enceinte
     *
     * @return pression_enceinte
     */
    virtual double get_pression() const = 0;

    /**
     * @brief Permet d'obtenir la production de la centrale
     *
     * @return production
     */
    virtual double get_production() const = 0;

    /**
     * @brief Permet d'obtenir la radioactivité à l'intérieur de l'enceinte
     *
     * @return radioactivité
     */
    virtual double get_radioactivite() const = 0;
}

#endif