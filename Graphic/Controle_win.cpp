#include<iostream>
#include"SDL2/sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include "Graphic_Fonction.hpp"

void Controle_win(int level){
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    sdl2::window fenêtre("Nuclear Alert : Fenêtre de Controle", {800, 600});
    bool quitting = false;

    sdl2::texte niveau1("Niveau 1", fonte_titre, fenêtre, {0xFF, 0xFF, 0xFF});
    niveau1.at(325, 50);
    sdl2::texte help("Appuyer sur h pour afficher les commandes", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(10, 10);
    sdl2::event_queue queue;
    while(not quitting){
        if(level == 1){
            fenêtre << niveau1 << help << sdl2::flush;
            auto events = queue.pull_events();
            for(const auto& e : events){
                if(e->kind_of_event() == sdl2::event::quit) quitting = true;
                if(e->kind_of_event() == sdl2::event::key){
                    auto& key = dynamic_cast<sdl2::event_keyboard&>(*e);
                    if(key.state() == sdl2::event_keyboard::pressed){
                        char keychar = key.ascci_code();
                        if(keychar == 27) quitting = true;
                        else if(keychar == 'h') Commande();
                    }
                }
            }

        }
    }

}