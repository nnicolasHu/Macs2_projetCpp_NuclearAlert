#include<iostream>
#include"sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include "Graphic_Fonction.hpp"
#include <string>

using namespace std;

void Bilanactiviteouvriere(sdl2::window* fenêtre,centrale* C){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 14);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 20);

        /////////        Titre fenêtre      ////////
    sdl2::texte gdtitre("BILAN ACTIVITE OUVIERE"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gdtitre.at(495, 53);

    sdl2::rectangle GD({30,40}, {1190,50}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << GD << gdtitre; 

    /// Organes ///
    sdl2::texte organes("Organe"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    organes.at(260, 120);

    sdl2::texte pompe_cp("Pompe circuit primaire"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe_cp.at(45, 170);

    sdl2::texte pompe_cs("Pompe circuit secondaire"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe_cs.at(45, 205);

    sdl2::texte cond("Condenseur"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cond.at(45, 240);

    sdl2::texte gen_vap("Générateur de vapeur"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gen_vap.at(45, 275);

    sdl2::texte inject("Injecteur borique"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    inject.at(45, 310);

    sdl2::texte cp("Circuit primaire"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cp.at(45, 345);

    sdl2::texte cs("Circuit secondaire"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cs.at(45, 380);

    sdl2::texte press("Pressuriseur"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press.at(45, 415);

    *fenêtre << organes << pompe_cp << pompe_cs << cond << gen_vap << inject << cp << cs << press; 

    /// Statut réparartion ///
    sdl2::texte statut("Statut réparation"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    statut.at(750, 120);

    *fenêtre << statut; 

    /// En cours ///
    sdl2::texte en_cours("En cours"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    en_cours.at(1070, 120);

    *fenêtre << en_cours;

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

    SDL_Delay(5000);
}