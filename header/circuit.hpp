#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include <memory>
#include <string>
using namespace std::string_literals; 


/**
 * @brief Cette classe décrit le fonctionnement d'un circuit. 
 * 
 * Classe mère des classes circuit primaire et circuit secondaire
 */

class circuit {

public : 

    /**
     * @brief Constructeur par défaut du circuit
     * 
     * L'état est initialement fixé à 1. La radioactivité, le débit, et l'inertie sont fixés à 0.
     */
    circuit();

    /**
     * @brief Constructeur de copie
     * 
     */
    circuit( const circuit& C ) = delete; // Interdiction de copier

    /**
     * @brief Constructeur de déplacement
     * 
     */
    circuit( circuit&& C ) = delete; // Interdiction de déplacer

    /**
     * @brief   Destructeur par défaut
     *
     */
    ~circuit() = default;



    /**
     * @brief Permet d'obtenir l'état du circuit
     * 
     * @return E_circuit
     */
    double get_E_circuit() const;

    /**
    * @brief Permet d'obbtenir la pression exercée par l'eau ou la vapeur
    *
    * @return Pression
    */
    double get_Pression() const;

    /**
     * @brief Permet d'obtenir le débit
     * 
     * @return Debit_eau
     */
    double get_Debit_eau() const;

    /**
     * @brief Permet d'obtenir l'inertie chaleur de l'eau circuit
     * 
     * @return Inertie
     */
    double get_Inertie() const;
 
    /**
     * @brief Permet d'obtenir la température de l'eau dans le circuit
     * 
     * @return Temperature
     */
    double get_Temperature() const;

    /**
     * @brief Permet d'obtenir la radioactivité
     * 
     * @return Radioactivité
     */
    double get_Radioactivite() const;

    /** @brief Permet d'obtenir l'état de la pompe
     * 
     * @return E_pompe
     */
    double get_E_pompe() const;

    /**
     * @brief Permet d'obtenir le régime de la pompe
     * 
     * @return F_pompe
     */
    double get_F_pompe() const;



    /**
     * @brief Permet de modifier l'état du circuit
     * 
     * @param[in] valeur La valeur doit être comprise entre 0 et 1
     */
    void set_E_circuit(double etat);
    
    /**
     * @brief Permet de modifier l'état de la pompe
     * 
     * @param[in] valeur La valeur doit être comprise entre 0 et 1
     */
    void set_E_pompe(double etat);

    /**
     * @brief Permet de modifier le régime de la pompe
     * 
     * @param[in] valeur La valeur doit être comprise entre 0 et l'état de la pompe
     */
    void set_F_pompe(double regime);

    void incr_F_pompe();
    void decr_F_pompe();

    /**
     * @brief Permet de réparer la pompe
     * 
     * @return booléen, 1 si la pompe est complètement réparée, 0 si elle est encore endommagée
     */
    bool reparation_pompe();

    /**
     * @brief met à jour le débit d'eau (méthode virtuel)
     * 
     * 
     */
    virtual void maj_Debit_eau();


protected : 
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
    double E_pompe;
    
    /** Régime de fonctionnement **/
    double F_pompe;
};

#endif