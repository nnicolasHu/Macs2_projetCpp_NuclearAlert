#include<iostream>
#include"sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include "Graphic_Fonction.hpp"

void Radioprotection_win(int level){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    
    sdl2::window fenêtre("Nuclear Alert : Poste de sécurité Radioprotection"s, {800, 600});

    //Titre fenêtre
    sdl2::texte gdtitre("POSTE DE SECURITE RADIOPROTECTION"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gdtitre.at(125, 13);

    sdl2::rectangle GD({30,10}, {740,45}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << GD << gdtitre; 

    //Cadre Activité
    sdl2::texte titre("Activité"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(220, 65);
    //piscine
    sdl2::texte piscine("Piscine"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    piscine.at(45, 115);
    sdl2::texte unitp("becq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitp.at(435, 115);
    //enceinte
    sdl2::texte enceinte("Enceinte"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    enceinte.at(45, 150);
    sdl2::texte unitenc("rem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitenc.at(435, 150);
    //rejets atmo
    sdl2::texte atmo("Rejets atmosphériques"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    atmo.at(45, 185);
    sdl2::texte unitatmo("mrem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitatmo.at(435, 185);
    //rejets eau
    sdl2::texte eau("Rejets atmosphériques"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    eau.at(45, 220);
    sdl2::texte uniteau("mrem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    uniteau.at(435, 220);

    sdl2::rectangle Activité({30,65}, {480,200}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Activité << titre << piscine << unitp << enceinte << unitenc << atmo << unitatmo << eau << uniteau;

    //Cadre Effectif
    sdl2::texte titreeff("Effectif"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreeff.at(610, 65);
    //total
    sdl2::texte disp("disp."s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    disp.at(555, 115);
    
    //occup
    sdl2::texte occup("occup."s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    occup.at(555, 150);
    
    //blessés
    sdl2::texte bles("bles."s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bles.at(555, 185);
    

    sdl2::rectangle Effectif({540,65}, {230,200}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Effectif << titreeff << disp << occup << bles;

    bool quitting = false;
    sdl2::event_queue queue;

        fenêtre << sdl2::flush;
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

