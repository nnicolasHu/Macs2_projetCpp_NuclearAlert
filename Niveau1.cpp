#include<iostream>
#include"Graphic_Fonction.hpp"
#include"sdl2.hpp"
#include<SDL2/SDL_ttf.h>

void Niveau1(sdl2::window* fenêtre){
    bool quitting = false;
    
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);

    sdl2::texte niveau1("Niveau 1", fonte_titre, *fenêtre, {0xFF, 0xFF, 0xFF});
    niveau1.at(325, 50);
    sdl2::texte help("Appuyer sur h pour afficher les commandes", fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(10, 10);
    sdl2::event_queue queue;

    while(not(quitting)){
        *fenêtre << niveau1 << help << sdl2::flush;
        std::cout << "je suis la" << std::endl;
        auto events = queue.pull_events();
        for(const auto& e : events){
            if(e->kind_of_event() == sdl2::event::quit) quitting = true;
            if(e->kind_of_event() == sdl2::event::key){
                auto& key = dynamic_cast<sdl2::event_keyboard&>(*e);
                char keychar = key.ascci_code();
               
            }
        }
    }

}