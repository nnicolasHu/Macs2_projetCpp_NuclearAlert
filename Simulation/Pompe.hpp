#ifndef _POMPE_HPP_
#define _POMPE_HPP_

/** 
 * @brief Cette classe définit le fonctionnement d'une pompe
 * 
 */

class pompe{

public:
    /**
     * @brief Constructeur par défaut de la pompe
     * 
     * L'état est initialement fixé à 1. Le régime au départ est nul.
     */
    pompe();

    /**
     * @brief   Destructeur par défaut
     *
     */
    ~pompe() = default;

    /**
     * @brief Permet d'obtenir l'état de la pompe
     * 
     * @return etat_pompe
     */
    double get_etat_pompe() const;

    /**
     * @brief Permet d'obtenir le régime de la pompe
     * 
     * @return regime
     */
    double get_regime() const;

    /**
     * @brief Permet de modifier le régime de la pompe
     * 
     * @param[in] valeur La valeur doit être comprise entre 0 et l'état de la pompe
     */
    void set_regime(double valeur);

private:
    /** Etat de la pompe **/
    double etat_pompe;
    
    /** Régime de fonctionnement **/
    double regime;

};

#endif 