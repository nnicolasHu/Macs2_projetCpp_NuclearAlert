#include"Graphic_Fonction.hpp"


void SalleDeControle(sdl2::window& fenêtre, centrale& C){//centrale* C
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 24);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Salle de controle", {800, 600});
    fenêtre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::texte titre_g("Salle de contrôle", fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre_g.at(350, 45);
    fenêtre << sdl2::rectangle({50, 40}, {770, 40}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
    sdl2::texte help("Appuyez sur 'h' pour voir les commandes disponibles", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(50, 10);
    //Cadre circuit primaire 
    sdl2::texte titre("Circuit Primaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(140, 120);
    sdl2::texte rendement("Rendement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement.at(60, 150);
    sdl2::texte pourcentage(arrondi((C.get_Circuit_Primaire().get_F_pompe())*100, 0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage.at(300, 150);
    sdl2::texte temperature("Température : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature.at(60, 170);
    sdl2::texte degre(arrondi(C.get_Circuit_Primaire().get_Temperature(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre.at(300, 170);
    sdl2::texte debit("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit.at(60, 190);
    sdl2::texte mcube(arrondi(C.get_Circuit_Primaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube.at(280, 190);
    sdl2::texte pression("Pression : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression.at(60, 210);
    sdl2::texte bar(arrondi(C.get_Circuit_Primaire().get_Pression(),0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar.at(300, 210);
    sdl2::texte radioactivite("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite.at(60, 230);
    sdl2::texte bec(arrondi(C.get_Circuit_Primaire().get_Radioactivite(),0) + " Bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec.at(300, 230);
    fenêtre  << pression << bar << radioactivite << bec << debit << mcube << degre<< temperature << titre << rendement << pourcentage << sdl2::rectangle({50, 110}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre Circuit secondaire
    sdl2::texte circuit_secondaire("Circuit Secondaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    circuit_secondaire.at(140, 280);
    sdl2::texte rendement2("Rendement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement2.at(60, 310);
    sdl2::texte pourcentage2(arrondi((C.get_Circuit_Secondaire().get_F_pompe())*100,0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage2.at(300, 310);
    sdl2::texte temperature2("Température : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature2.at(60, 330);
    sdl2::texte degre2(arrondi(C.get_Circuit_Secondaire().get_Temperature(),0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre2.at(300, 330);
    sdl2::texte debit2("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit2.at(60, 350);
    sdl2::texte mcube2(arrondi(C.get_Circuit_Secondaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube2.at(280, 350);
    sdl2::texte pression2("Pression : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression2.at(60, 370);
    sdl2::texte bar2(arrondi(C.get_Circuit_Secondaire().get_Pression(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar2.at(300, 370);
    sdl2::texte radioactivite2("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite2.at(60, 390);
    sdl2::texte bec2(arrondi(C.get_Circuit_Secondaire().get_Radioactivite(), 0) + " bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec2.at(300, 390);
    fenêtre << rendement2 << pourcentage2 << temperature2 << degre2 << debit2 << mcube2 << pression2 << bar2 << radioactivite2 << bec2<< circuit_secondaire << sdl2::rectangle({50, 270}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre production electrique
    sdl2::texte production("Production électrique"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    production.at(120, 440);
    sdl2::texte MW(arrondi(C.get_MW(), 0) + " MW"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    MW.at(300, 480);
    fenêtre << production << MW << sdl2::rectangle({50, 430}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre qui affiche la pression subit par l'enceinte de confinement
    sdl2::texte press_subit_c("Pression subit"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press_subit_c.at(140, 560);
    sdl2::texte bar3(arrondi(C.get_P_enceinte(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar3.at(300, 600);
    fenêtre << press_subit_c << bar3 << sdl2::rectangle({50, 540}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //Cadre Système de Refroidissement
    sdl2::texte sys_froid("Système de refroidissement : "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    sys_froid.at(460, 100);
    sdl2::texte Rend_Cond("Rendement du condenseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Rend_Cond.at(430, 140);
    sdl2::texte pourcentage3(arrondi(C.get_Circuit_Secondaire().get_F_condenseur(), 0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage3.at(730, 140);

    sdl2::texte debit_cond("Débit du condenseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_cond.at(430, 170);

    sdl2::texte mcube3(arrondi(C.get_Circuit_Secondaire().get_D_condenseur(), 0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube3.at(710, 170);

    sdl2::texte differ_temp("Différence de température : "s, fonte_texte, fenêtre,{0xAD, 0xFF, 0x2F, 0});
    differ_temp.at(430, 200);
    sdl2::texte diff_temperature(arrondi(C.get_Circuit_Secondaire().get_Delta_ES(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    diff_temperature.at(730, 200);
    fenêtre << Rend_Cond << sys_froid << pourcentage3 << debit_cond << mcube3 << differ_temp << diff_temperature << sdl2::rectangle({420, 90}, {400, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre barre de graphite
    sdl2::texte barre_graph("Etat des barres de Graphite"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    barre_graph.at(460, 260);
    sdl2::texte pourcentage4(arrondi(C.get_Reacteur().get_E_barre(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage4.at(730, 300);
    fenêtre << barre_graph << pourcentage4 << sdl2::rectangle({420, 250}, {400, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre affichant le taux de bore dans la piscine
    sdl2::texte TxBorePiscine("Taux Bore"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    TxBorePiscine.at(570, 370);
    sdl2::texte pourcentage5(arrondi(C.get_Reacteur().get_TBore_eff(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage5.at(730, 410);
    fenêtre << TxBorePiscine << pourcentage5 << sdl2::rectangle({420, 360}, {400, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

     
    //cadre ordre
    sdl2::texte ordre_disp("Ordres "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ordre_disp.at(580, 480);
    fenêtre << ordre_disp << sdl2::rectangle({420, 470}, {400, 170}, {0xAD, 0xFF, 0x2F, 0}, false);


    //Cadre systeme de sécurité
    sdl2::texte Sys_secur("Système de sécutité "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Sys_secur.at(940, 50);
    fenêtre << Sys_secur << sdl2::rectangle({840, 40},{390, 600}, {0xAD, 0xFF, 0x2F, 0}, false );

    fenêtre << titre_g << help << sdl2::flush;
    
    
}
