#include"Graphic_Fonction.hpp"


void SalleDeControle(sdl2::window& fenêtre, centrale& C){//centrale* C
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 24);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Salle de controle", {800, 600});
    fenêtre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true) << sdl2::flush;

    sdl2::texte help("Appuyez sur 'h' pour voir les commandes disponibles", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(50, 10);
    //Cadre circuit primaire 
    sdl2::texte titre("Circuit Primaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(140, 60);
    sdl2::texte rendement("Rendement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement.at(60, 90);
    sdl2::texte pourcentage(arrondi((C.get_Circuit_Primaire().get_F_pompe())*100, 0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage.at(300, 90);
    sdl2::texte temperature("Température : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature.at(60, 110);
    sdl2::texte degre(arrondi(C.get_Circuit_Primaire().get_Temperature(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre.at(300, 110);
    sdl2::texte debit("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit.at(60, 130);
    sdl2::texte mcube(arrondi(C.get_Circuit_Primaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube.at(280, 130);
    sdl2::texte pression("Pression : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression.at(60, 150);
    sdl2::texte bar(arrondi(C.get_Circuit_Primaire().get_Pression(),0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar.at(300, 150);
    sdl2::texte radioactivite("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite.at(60, 170);
    sdl2::texte bec(arrondi(C.get_Circuit_Primaire().get_Radioactivite(),0) + " Bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec.at(300, 170);
    fenêtre  << pression << bar << radioactivite << bec << debit << mcube << degre<< temperature << titre << rendement << pourcentage << sdl2::rectangle({50, 50}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre Circuit secondaire
    sdl2::texte circuit_secondaire("Circuit Secondaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    circuit_secondaire.at(140, 230);
    sdl2::texte rendement2("Rendement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement2.at(60, 260);
    sdl2::texte pourcentage2(arrondi(C.get_Circuit_Secondaire().get_F_pompe(),0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage2.at(300, 260);
    sdl2::texte temperature2("Température : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature2.at(60, 280);
    sdl2::texte degre2(arrondi(C.get_Circuit_Secondaire().get_Temperature(),0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre2.at(300, 280);
    sdl2::texte debit2("Débit d'eau : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit2.at(60, 300);
    sdl2::texte mcube2(arrondi(C.get_Circuit_Secondaire().get_Debit_eau(),0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube2.at(280, 300);
    sdl2::texte pression2("Pression : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression2.at(60, 320);
    sdl2::texte bar2(arrondi(C.get_Circuit_Secondaire().get_Pression(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar2.at(300, 320);
    sdl2::texte radioactivite2("Radioactivité : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite2.at(60, 340);
    sdl2::texte bec2(arrondi(C.get_Circuit_Secondaire().get_Radioactivite(), 0) + " bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec2.at(300, 340);
    fenêtre << rendement2 << pourcentage2 << temperature2 << degre2 << debit2 << mcube2 << pression2 << bar2 << radioactivite2 << bec2<< circuit_secondaire << sdl2::rectangle({50, 220}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre production electrique
    sdl2::texte production("Production électrique"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    production.at(120, 400);
    sdl2::texte MW(arrondi(C.get_MW(), 0) + " MW"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    MW.at(300, 440);
    fenêtre << production << MW << sdl2::rectangle({50, 390}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre qui affiche la pression subit par l'enceinte de confinement
    sdl2::texte press_subit_c("Pression subit"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press_subit_c.at(140, 520);
    sdl2::texte bar3(arrondi(C.get_P_enceinte(), 0) + " bar"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar3.at(300, 560);
    fenêtre << press_subit_c << bar3 << sdl2::rectangle({50, 510}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //Cadre Système de Refroidissement
    sdl2::texte sys_froid("Système de refroidissement : "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    sys_froid.at(460, 60);
    sdl2::texte Rend_Cond("Rendement du condenseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Rend_Cond.at(430, 100);
    sdl2::texte pourcentage3(arrondi(C.get_Circuit_Secondaire().get_F_condenseur(), 0) + " %"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage3.at(730, 100);

    sdl2::texte debit_cond("Débit du condenseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_cond.at(430, 130);

    sdl2::texte mcube3(arrondi(C.get_Circuit_Secondaire().get_D_condenseur(), 0) + " m^3/s"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube3.at(710, 130);

    sdl2::texte differ_temp("Différence de température : "s, fonte_texte, fenêtre,{0xAD, 0xFF, 0x2F, 0});
    differ_temp.at(430, 160);
    sdl2::texte diff_temperature(arrondi(C.get_Circuit_Secondaire().get_Delta_ES(), 0) + " °C"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    diff_temperature.at(730, 160);
    fenêtre << Rend_Cond << sys_froid << pourcentage3 << debit_cond << mcube3 << differ_temp << diff_temperature << sdl2::rectangle({420, 50}, {400, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre barre de graphite
    sdl2::texte barre_graph("Etat des barres de Graphite"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    barre_graph.at(460, 230);
    sdl2::texte pourcentage4(arrondi(C.get_Reacteur().get_E_barre(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage4.at(730, 270);
    fenêtre << barre_graph << pourcentage4 << sdl2::rectangle({420, 220}, {400, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre affichant le taux de bore dans la piscine
    sdl2::texte TxBorePiscine("Taux Bore"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    TxBorePiscine.at(570, 350);
    sdl2::texte pourcentage5(arrondi(C.get_Reacteur().get_TBore_eff(), 0) + " %"s,fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage5.at(730, 390);
    fenêtre << TxBorePiscine << pourcentage5 << sdl2::rectangle({420, 340}, {400, 100}, {0xAD, 0xFF, 0x2F, 0}, false);


    //Cadre systeme de sécurité
    sdl2::texte ordre_disp("Ordres "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ordre_disp.at(580, 470);
    fenêtre << ordre_disp << sdl2::rectangle({420, 460}, {400, 170}, {0xAD, 0xFF, 0x2F, 0}, false);


    //cadre ordre 
    sdl2::texte Sys_secur("Système de sécutité "s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Sys_secur.at(940, 50);
    fenêtre << Sys_secur << sdl2::rectangle({840, 40},{390, 600}, {0xAD, 0xFF, 0x2F, 0}, false );

    bool quitting = false;
    sdl2::event_queue queue;
    fenêtre << help << sdl2::flush;
    auto events = queue.pull_events();
    for(const auto& e : events){
        if(e->kind_of_event() == sdl2::event::quit) quitting = true;
        if(e->kind_of_event() == sdl2::event::key){
            auto& key = dynamic_cast<sdl2::event_keyboard&>(*e);
            if(key.state() == sdl2::event_keyboard::pressed){
                char keychar = key.ascci_code();
                if(keychar == 27) quitting = true;
            }
        }
    }
    SDL_Delay(3000);
    
}
