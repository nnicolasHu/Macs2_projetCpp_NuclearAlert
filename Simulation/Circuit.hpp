#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_



/**
 * @brief Cette classe décrit le fonctionnement d'un circuit. 
 * 
 * Classe mère des classes circuit primaire et circuit secondaire
 */

class Circuit {

public : 

    /**
     * @brief Constructeur par défaut du circuit
     * 
     * L'état est initialement fixé à 1. La radioactivité, le débit, et l'inertie sont fixés à 0.
     */
    Circuit();

    Circuit( const Circuit& C ) = delete; // Interdiction de copier
    Circuit( Circuit&& C ) = delete; // Interdiction de déplacer

    /**
     * @brief   Destructeur par défaut
     *
     */
    ~Circuit() = default;

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
    double E_circuit;

    /** Pression **/
    double Pression;

    /** Débit **/
    double Debit_eau;

    /** Inertie température eau circuit **/
    double Inertie;

    /** Température de l'eau/vapeur **/
    double Temperature;

    /** Radioactivité **/
    double Radioactivite;

    /** Etat de la pompe **/
    double Etat_pompe;
    
    /** Régime de fonctionnement **/
    double Regime;
};


/*
public:
**
* @brief Constructeur par défaut de la pompe
* 
* L'état est initialement fixé à 1. Le régime au départ est nul.
*


    **
     * @brief Permet d'obtenir l'état de la pompe
     * 
     * @return etat_pompe
     *
    double get_etat_pompe() const;

    **
     * @brief Permet d'obtenir le régime de la pompe
     * 
     * @return regime
     *
    double get_regime() const;

    **
     * @brief Permet de modifier le régime de la pompe
     * 
     * @param[in] valeur La valeur doit être comprise entre 0 et l'état de la pompe
     *
    void set_regime(double valeur);

*/



#endif