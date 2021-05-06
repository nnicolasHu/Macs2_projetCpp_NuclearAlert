
#include"Graphic_Fonction.hpp"

using namespace std::string_literals;

void SalleDeControle(sdl2::window* fenêtre, centrale* C){//centrale* C
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 24);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Salle de controle", {800, 600});

    //Cadre circuit primaire 
    sdl2::texte titre("Circuit Primaire"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(140, 60);
    sdl2::texte rendement("Rendement : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement.at(60, 90);
    sdl2::texte pourcentage("%"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage.at(350, 90);
    sdl2::texte temperature("Température dans le circuit"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature.at(60, 110);
    sdl2::texte degre("°C"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre.at(350, 110);
    sdl2::texte debit("Débit d'eau : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit.at(60, 130);
    sdl2::texte mcube("m^3/s"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube.at(330, 130);
    sdl2::texte pression("Pression : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression.at(60, 150);
    sdl2::texte bar("bar"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar.at(350, 150);
    sdl2::texte radioactivite("Radioactivité : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite.at(60, 170);
    sdl2::texte bec("Bq"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec.at(350, 170);
    *fenêtre  << pression << bar << radioactivite << bec << debit << mcube << degre<< temperature << titre << rendement << pourcentage << sdl2::rectangle({50, 50}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre Circuit secondaire
    sdl2::texte circuit_secondaire("Circuit Secondaire"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    circuit_secondaire.at(140, 230);
    sdl2::texte rendement2("Rendement : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement2.at(60, 260);
    sdl2::texte pourcentage2("%"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage2.at(350, 260);
    sdl2::texte temperature2("Température dans le circuit"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature2.at(60, 280);
    sdl2::texte degre2("°C"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre2.at(350, 280);
    sdl2::texte debit2("Débit d'eau : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit2.at(60, 300);
    sdl2::texte mcube2("m^3/s"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube2.at(330, 300);
    sdl2::texte pression2("Pression : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression2.at(60, 320);
    sdl2::texte bar2("bar"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar2.at(350, 320);
    sdl2::texte radioactivite2("Radioactivité : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite2.at(60, 340);
    sdl2::texte bec2("bq"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec2.at(350, 340);
    *fenêtre << rendement2 << pourcentage2 << temperature2 << degre2 << debit2 << mcube2 << pression2 << bar2 << radioactivite2 << bec2<< circuit_secondaire << sdl2::rectangle({50, 220}, {340, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre production electrique
    sdl2::texte production("Production électrique"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    production.at(120, 400);
    sdl2::texte MW("MW"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    MW.at(340, 440);
    *fenêtre << production << MW << sdl2::rectangle({50, 390}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre qui affiche la pression subit par l'enceinte de confinement
    sdl2::texte press_subit_c("Pression subit"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press_subit_c.at(140, 520);
    *fenêtre << press_subit_c << sdl2::rectangle({50, 510}, {340, 100}, {0xAD, 0xFF, 0x2F, 0}, false);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //Cadre Système de Refroidissement
    sdl2::texte sys_froid("Système de refroidissement"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    sys_froid.at(460, 60);
    sdl2::texte Rend_Cond("Rendement du condenseur"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Rend_Cond.at(430, 100);
    sdl2::texte pourcentage3("%"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage3.at(780, 100);
    sdl2::texte debit_cond("Débit du condenseur"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit_cond.at(430, 130);
    sdl2::texte mcube3("m^3/s"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube3.at(760, 130);
    sdl2::texte differ_temp("Différence de température"s, fonte_texte, *fenêtre,{0xAD, 0xFF, 0x2F, 0});
    differ_temp.at(430, 160);
    sdl2::texte diff_temperature("°C"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    diff_temperature.at(780, 160);
    *fenêtre << Rend_Cond << sys_froid << pourcentage3 << debit_cond << mcube3 << differ_temp << diff_temperature << sdl2::rectangle({420, 50}, {400, 150}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre barre de graphite
    sdl2::texte barre_graph("Etat des barres de Graphite"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    barre_graph.at(460, 230);
    *fenêtre << barre_graph << sdl2::rectangle({420, 220}, {400, 100}, {0xAD, 0xFF, 0x2F, 0}, false);

    //Cadre systeme de sécurité
    sdl2::texte Sys_secur("Ordres "s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    Sys_secur.at(570, 350);
    *fenêtre << Sys_secur << sdl2::rectangle({420, 340}, {400, 270}, {0xAD, 0xFF, 0x2F, 0}, false);

    //cadre ordre 
    sdl2::texte ordre_disp("Système de sécutité "s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ordre_disp.at(940, 50);
    *fenêtre << ordre_disp << sdl2::rectangle({840, 40},{390, 600}, {0xAD, 0xFF, 0x2F, 0}, false );

    //Cadre affichant le taux de bore dans la piscine
    // sdl2::texte TxBorePiscine("Taux Bore"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    // TxBorePiscine.at(380, 50);
    // *fenêtre << TxBorePiscine << sdl2::rectangle({360, 40}, {120, 120}, {0xAD, 0xFF, 0x2F, 0}, false);

    bool quitting = false;
    sdl2::event_queue queue;
    *fenêtre << sdl2::flush;
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
