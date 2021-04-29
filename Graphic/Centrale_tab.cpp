#include "Graphic_Fonction.hpp"
#include "SDL2/sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include<iostream>

void Centrale_tab(){
    sdl2::font fonte_texte("./data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./data/Lato-Bold.ttf", 28);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    sdl2::window fenêtre("Nuclear Alert : Schéma de la centrale", {800, 600});

    sdl2::image centrale("data/sch├®ma_centrale.png", fenêtre);
    centrale.at(100, 100);

    sdl2::texte echap("Appuyez sur echap pour revenir à la fenêtre précédente", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    echap.at(200, 500);
    sdl2::texte circuit_prim("Circuit primaire", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_prim.at(70, 430);
    sdl2::texte circuit_sec("Circuit secondaire", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_sec.at(230, 430);
    sdl2::texte circuit_refroid("Circuit de refroidissement", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_refroid.at(400, 430);
    sdl2::texte vapeur("Vapeur d'eau", fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    vapeur.at(550, 160);
    
    bool quitting = false;
    sdl2::event_queue queue;

        fenêtre << centrale << echap << circuit_prim << circuit_sec << circuit_refroid << vapeur << sdl2::rectangle({200, 300}, {100, 70}, {0xFF, 0, 0, 0xFF}, false)<< sdl2::flush;
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
    
}