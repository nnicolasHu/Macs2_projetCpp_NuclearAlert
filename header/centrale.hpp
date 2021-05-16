#ifndef _CENTRALE_HPP
#define _CENTRALE_HPP

#include <memory>
#include <array>

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

class centrale 
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
    double get_E_enceinte() const;

    /** 
     * @brief Permet d'obtenir l'état de la centrale
     *
     * @return E_centrale
     */
    double get_E_centrale() const;

    /**
     * @brief Permet d'obtenir la pression subit par l'enceinte
     *
     * @return P_enceinte
     */
    double get_P_enceinte() const;

    /**
     * @brief Permet d'obtenir la production de la centrale
     *
     * @return MW
     */
    double get_MW() const;

    /**
     * @brief Permet d'obtenir la radioactivité à l'intérieur de l'enceinte
     *
     * @return R_enceinte
     */
    double get_R_enceinte() const;

    /** 
     * @brief Permet d'accéder aux méthodes du reacteur
     * 
     */
    reacteur& get_Reacteur() const;

    /** 
     * @brief Permet d'accéder aux méthodes de la classe circuitPrimaire
     * 
     */
    circuitPrimaire& get_Circuit_Primaire() const;

    /** 
     * @brief Permet d'accéder aux méthodes de la classe circuitSecondaire
     * 
     */
    circuitSecondaire& get_Circuit_Secondaire() const;

    /** 
     * @brief Permet d'accéder aux méthodes de la classe ouvriers
     * 
     */
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
    std::string degr_E_enceinte();

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
     */
    void set_Order();

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

    /**
     * @brief Permet d'envoyer des ouvriers en intervention lorsque c'est possible
     * 
     * @param[in] organe Entier correspondant à l'organe que l'on veut réparer
     */
    void envoie_intervention(int organe);

    /**
     * @brief Permet de mettre à jour les réparations effectuées 
     * 
     */
    void maj_Reparation();

    /**
     * @brief Permet de TOUT mettre à jour
     * 
     */
    void maj_General();

    /**
     * @brief Permet d'effectuer TOUTES les dégradations
     * 
     */
    std::string degr_General();

    /**
     * @brief Permet d'obtenir les organes qui se dégradent pour permettre de les faire clignoter
     * 
     * Convention : 
     * 
     * case :
     * 0 = pompe circuit primaire
     * 1 = pompe circuit secondaire
     * 2 = condenseur
     * 3 = générateur de vapeur
     * 4 = injecteur borique
     * 5 = circuit primaire
     * 6 = circuit secondaire
     * 7 = pressuriseur
     * 8 = echangeur de chaleur
     * 9 = enceinte de confinement
     * 
     * état :
     * O = tout se passe bien pour cette organe
     * 1 = l'organe est endommagé
     * 
     */
    std::array<bool,10> get_clignotements();

    /**
     * @brief Permet d'effectuer la tentative d'arrêt d'urgence
     * 
     * @return booléen permettant de savoir si la tenatative d'arrêt d'urgence doit dégrader des éléments du réacteur
     */
    bool arret_urgence();

    /**
     * @brief Permet d'effectuer des réparations sur la pompe du circuit primaire (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_pompeCircuitPrimaire();

    /**
     * @brief Permet d'effectuer des réparations sur la pompe du circuit secondaire (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_pompeCircuitSecondaire();

    /**
     * @brief Permet d'effectuer des réparations sur le condenseur (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_condenseur();

    /**
     * @brief Permet d'effectuer des réparations sur le générateur de vapeur (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_generateurVapeur();

    /**
     * @brief Permet d'effectuer des réparations sur l'injecteur de bore (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_injecteurBore();

    /**
     * @brief Permet d'effectuer des réparations sur le circuit primaire (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_circuitPrimaire();

    /**
     * @brief Permet d'effectuer des réparations sur le circuit secondaire (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_circuitSecondaire();

    /**
     * @brief Permet d'effectuer des réparations sur le pressuriseur (méthode uniquement utilisée dans
     * envoie_intervention(int organe))
     * 
     */
    void envoie_pressuriseur();
    
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
    double MW;

    /** Population evacuée **/
    double Evac;

    /** Ordre evacuation, 0 : pas d'evacuation, 1 : ordre d'évacuer  **/ 
    bool Order;

    /** Radioactivité air **/
    double R_air;

    /** Radioactivité eau **/
    double R_eau;

    /** Contamination **/
    unsigned int Contamination;
    
    
};


#endif
