#include"Graphic_Fonction.hpp"


void SalleDeControle(sdl2::window& fenêtre, centrale& C){//centrale* C
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 15);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 22);

    fenêtre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::texte titre_g("Salle de contrôle", fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre_g.at(350, 45);
    fenêtre << sdl2::rectangle({10, 40}, {820, 40}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Affiche la possibilité de press touch H pour acceder à la page commande
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    sdl2::texte help("Appuyez sur 'h' pour voir les commandes disponibles", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(50, 10);
    fenêtre << titre_g << help ;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre circuit primaire 
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({10, 90}, {380, 210}, {0xFF, 0xFF, 0xFF, 0xFF}, false); //Affichage rectangle

    sdl2::texte circuit_primaire("Circuit Primaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    circuit_primaire.at(90, 100);
    fenêtre << circuit_primaire;

    sdl2::texte rendement("Rendement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement.at(20, 130);
    sdl2::texte pourcentage(arrondi((C.get_Circuit_Primaire().get_F_pompe())*100, 0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage.at(340, 130);
    fenêtre << rendement << pourcentage; //affichage 

    sdl2::texte temperature_press_C1("Température préssuriseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature_press_C1.at(20, 150);
    sdl2::texte degre_press_C1(arrondi(C.get_Circuit_Primaire().get_T_pressuriseur(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre_press_C1.at(340, 150);
    fenêtre << temperature_press_C1 << degre_press_C1; //affichage 

    sdl2::texte temperature_eff_C1("Température préssuriseur effective : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature_eff_C1.at(20, 170);
    sdl2::texte degre_eff_C1(arrondi(C.get_Circuit_Primaire().get_T_pressuriseur_eff(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre_eff_C1.at(340, 170);
    fenêtre << temperature_eff_C1 << degre_eff_C1; //affichage 
    
    sdl2::texte debit_eau_C1("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_eau_C1.at(20, 190);
    sdl2::texte val_debit_eau_C1(arrondi(C.get_Circuit_Primaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_debit_eau_C1.at(330, 190);
    fenêtre << debit_eau_C1 << val_debit_eau_C1; //affichage 

    sdl2::texte pression_C1("Pression : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression_C1.at(20, 210);
    sdl2::texte val_pression_C1(arrondi(C.get_Circuit_Primaire().get_Pression(),0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_pression_C1.at(340, 210);
    fenêtre << pression_C1 << val_pression_C1; //affichage 

    sdl2::texte inertieC1("Inertie : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    inertieC1.at(20, 230);
    sdl2::texte val_inertieC1(arrondi(C.get_Circuit_Primaire().get_Inertie(),0), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_inertieC1.at(340, 230);
    fenêtre << inertieC1 << val_inertieC1; //affichage 

    sdl2::texte temperature_eau_C1("Température eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature_eau_C1.at(20, 250);
    sdl2::texte deg_temp_eau_C1(arrondi(C.get_Circuit_Primaire().get_Temperature(),0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    deg_temp_eau_C1.at(340, 250);
    fenêtre << temperature_eau_C1 << deg_temp_eau_C1; //affichage 

    sdl2::texte radioactivite_C1("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite_C1.at(20, 270);
    sdl2::texte val_rad_C1(arrondi(C.get_Circuit_Primaire().get_Radioactivite(),0) + " Bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_rad_C1.at(340, 270);
    fenêtre << radioactivite_C1 << val_rad_C1; //affichage 

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre Circuit secondaire
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({10, 310}, {380, 330}, {0xFF, 0xFF, 0xFF, 0xFF}, false); //Affichage du rectangle

    sdl2::texte circuit_secondaire("Circuit Secondaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    circuit_secondaire.at(90, 320);
    fenêtre << circuit_secondaire;

    sdl2::texte rendement_circuit_C2("Rendement pompe circuit : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement_circuit_C2.at(20, 350);
    sdl2::texte val_circuit_C2(arrondi((C.get_Circuit_Secondaire().get_F_pompe())*100,0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_circuit_C2.at(340, 350);
    fenêtre << rendement_circuit_C2 << val_circuit_C2; //affichage 

    sdl2::texte temperature_vapeur_C2("Température vapeur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature_vapeur_C2.at(20, 370);
    sdl2::texte degre_vapeur_C2(arrondi(C.get_Circuit_Secondaire().get_T_vapeur(),0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre_vapeur_C2.at(340, 370);
    fenêtre << temperature_vapeur_C2 << degre_vapeur_C2; //affichage 

    sdl2::texte debit_eau_C2("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_eau_C2.at(20, 390);
    sdl2::texte val_debit_eau_C2(arrondi(C.get_Circuit_Secondaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_debit_eau_C2.at(330, 390);
    fenêtre << debit_eau_C2 << val_debit_eau_C2; //affichage 

    sdl2::texte pression_vapeur_C2("Pression vapeur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression_vapeur_C2.at(20, 410);
    sdl2::texte val_vapeur_C2(arrondi(C.get_Circuit_Secondaire().get_P_vapeur(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_vapeur_C2.at(340, 410);
    fenêtre << pression_vapeur_C2 << val_vapeur_C2; //affichage 

    sdl2::texte inertieC2("Inertie chaleur de l’eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    inertieC2.at(20, 430);
    sdl2::texte val_inertieC2(arrondi(C.get_Circuit_Secondaire().get_Inertie(), 0), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_inertieC2.at(340, 430);
    fenêtre << inertieC2 << val_inertieC2;

    sdl2::texte radioactivite_C2("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite_C2.at(20, 450);
    sdl2::texte val_rad_C2(arrondi(C.get_Circuit_Secondaire().get_Radioactivite(), 0) + " Bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_rad_C2.at(340, 450);
    fenêtre << radioactivite_C2 << val_rad_C2;

    //Systeme de refroidissement 
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    sdl2::texte sys_refroidissement("Systeme de refroidissement"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    sys_refroidissement.at(60, 500);
    fenêtre << sys_refroidissement;

    sdl2::texte rendement_cond_C2("Rendement pompe condensateur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement_cond_C2.at(20, 540);
    sdl2::texte pourcentage_cond_C2(arrondi((C.get_Circuit_Secondaire().get_F_condenseur())*100,0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage_cond_C2.at(340, 540);
    fenêtre << rendement_cond_C2 << pourcentage_cond_C2; //affichage 

    sdl2::texte debit_cond_C2("Debit condensateur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_cond_C2.at(20, 570);
    sdl2::texte val_debit_cond_C2(arrondi(C.get_Circuit_Secondaire().get_D_condenseur(), 0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_debit_cond_C2.at(330, 570);
    fenêtre << debit_cond_C2 << val_debit_cond_C2; //affichage 

    sdl2::texte diff_chaleur_C2("Différence de chaleur in/out condensateur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    diff_chaleur_C2.at(20, 600);
    sdl2::texte val_diff_chal_C2(arrondi(C.get_Circuit_Secondaire().get_Delta_ES(), 0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_diff_chal_C2.at(330, 600);
    fenêtre << diff_chaleur_C2 << val_diff_chal_C2;

    //////////////////////////////////////////////////////////////////////////////////////////////////
    // Cadre production electrique
    //////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({400, 90}, {430, 70}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

    sdl2::texte production("Production électrique"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    production.at(500, 100);
    fenêtre << production;

    sdl2::texte MW(arrondi(C.get_MW(), 0) + " MW"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    MW.at(600, 130);
    fenêtre << MW;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre qui affiche la pression subit par l'enceinte de confinement
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({400, 170}, {430, 70}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

    sdl2::texte press_subit_c("Pression subit par l'enceinte"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press_subit_c.at(500, 180);
    
    sdl2::texte bar3(arrondi(C.get_P_enceinte(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar3.at(600, 210);
    fenêtre << press_subit_c << bar3 ;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre barre de graphite
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({400, 250}, {430, 70}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

    sdl2::texte barre_graphite("Etat des barres de Graphite"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    barre_graphite.at(490, 260);
    sdl2::texte val_barre_reacteur(arrondi(C.get_Reacteur().get_E_barre(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_barre_reacteur.at(600, 290);
    fenêtre << barre_graphite << val_barre_reacteur;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre affichant le taux de bore dans la piscine
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({400, 330}, {430, 70}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

    sdl2::texte TxBorePiscine("Taux Bore"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    TxBorePiscine.at(550, 340);

    sdl2::texte val_tx_bore_react(arrondi(C.get_Reacteur().get_TBore_eff(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    val_tx_bore_react.at(600, 370);
    fenêtre << TxBorePiscine << val_tx_bore_react;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //cadre ordre
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({400, 410}, {430, 230}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

    sdl2::texte ordre("Ordres "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ordre.at(580, 420);
    fenêtre << ordre;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //Cadre systeme de sécurité
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    fenêtre << sdl2::rectangle({840, 40},{390, 600}, {0xFF, 0xFF, 0xFF, 0xFF}, false ); //Affichage rectangle

    sdl2::texte Sys_secur("Système de sécutité "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Sys_secur.at(940, 50);
    fenêtre << Sys_secur;


    //Affichage complet 
    fenêtre << sdl2::flush; 
}
