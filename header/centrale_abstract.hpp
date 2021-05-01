#ifndef _CENTRALE_ABSTRACT_HPP_
#define _CENTRALE_ABSTRACT_HPP_

class centrale_abstract{

public : 

    virtual ~centrale_abstract() = default;
    
    /** 
     * @brief Permet d'obtenir l'état de l'enceinte 
     *
     * @return E_enceinte
     */
    virtual double get_E_enceinte() const = 0;

    /** 
     * @brief Permet d'obtenir l'état de la centrale
     *
     * @return E_centrale
     */
    virtual double get_E_centrale() const = 0;

    /**
     * @brief Permet d'obtenir la pression subit par l'enceinte
     *
     * @return P_enceinte
     */
    virtual double get_P_enceinte() const = 0;

    /**
     * @brief Permet d'obtenir la production de la centrale
     *
     * @return MW
     */
    virtual double get_MW() const = 0;

    /**
     * @brief Permet d'obtenir la radioactivité à l'intérieur de l'enceinte
     *
     * @return R_enceinte
     */
    virtual double get_R_enceinte() const = 0;
};

#endif