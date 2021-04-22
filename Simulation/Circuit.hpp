#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_
#include "Pompe.hpp"


/**
 * @brief Cette classe décrit le fonctionnement d'un circuit
 * 
 * 
 */

class circuit : public pompe
{

public : 

    /**
     * @brief Constructeur par défaut du circuit
     * 
     * L'état est initialement fixé à 1. La radioactivité, le débit, et l'inertie sont fixés à 0.
     */
    circuit();

    /**
     * @brief   Destructeur par défaut
     *
     */
    ~circuit() = default;

    /**
     * @brief Permet d'obtenir l'état du circuit
     * 
     * @return etat
     */
    double get_etat_circuit() const;

    /**
     * @brief Permet d'obtenir l'inertie température
     * 
     * @return inertie_temp
     */
    double get_inertie() const;

    /**
     * @brief Permet d'obtenir le débit
     * 
     * @return debit
     */
    double get_debit() const;

    /**
     * @brief Permet d'obtenir la radioactivité
     * 
     * @return radioactivité
     */
    double get_radioactivite() const;

private : 
    /** Etat du circuit **/
    double etat;

    /** Pompe **/
    pompe p;

    /** Inertie température eau circuit **/
    double inertie_temp;

    /** Débit **/
    double debit;

    /** Radioactivité **/
    double radioactivité;
};

#endif