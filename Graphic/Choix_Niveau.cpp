#include "Graphic_Fonction.hpp"
#include "sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include <string>
#include<iostream>

int Choix_Niveau(sdl2::window* fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Black.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Choix Niveau", {800, 600});
    int level = 0;

    sdl2::texte bvn("Bienvenue"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    bvn.at(650, 50);
    sdl2::texte titre2("Veuillez choisir un niveau "s, fonte_titre, *fenêtre, {0xFF, 0, 0, 0xFF});
    titre2.at(500, 100);
    sdl2::texte niveau1("Niveau 1"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    niveau1.at(660, 250);
    niveau1.stretch({100, 75});
    sdl2::texte niveau2("Niveau 2"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    niveau2.at(660, 400);
    niveau2.stretch({100, 75});
    sdl2::texte niveau3("Niveau 3"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    niveau3.at(660, 550);
    niveau3.stretch({100, 75});

    bool quitting = false;
    sdl2::event_queue queue;
    while(not quitting){
        *fenêtre<< sdl2::rectangle({0, 0}, {1400, 800}, {0, 0, 0, 0}, true);
        *fenêtre << sdl2::rectangle({610, 240}, {200, 100}, {0,0,0xFF,0xFF}, true);
        *fenêtre << sdl2::rectangle({610, 390}, {200, 100}, {0, 0, 0xFF, 0xFF}, true);
        *fenêtre << sdl2::rectangle({610, 540}, {200, 100}, {0, 0, 0xFF, 0xFF}, true);
        *fenêtre << niveau1 << niveau2 <<  bvn << niveau3 << titre2 << sdl2::flush;
        auto events =queue.pull_events();
        for(const auto& e : events){
            if (e->kind_of_event() == sdl2::event::quit) quitting = true;
            if(e->kind_of_event() == sdl2::event::mouse_button){
                auto& boutton = dynamic_cast<sdl2::event_mouse_button&>(*e);
                if(boutton.button() == sdl2::event_mouse_button::left){
                    auto[px, py] = boutton.position();
                    if(boutton.state() == sdl2::event_mouse_button::released){
                        if((px>=325 && px<=475) & (py>=170 && py<=270)){
                            //std::cout << "Niveau 1" << std::endl;
                            level = 1;
                            quitting = true;
                        }
                        else if((px>=325 && px<=475) & (py>=290 && py<=390)){
                            //std::cout << "Niveau 2"<<std::endl;
                            level = 2;
                            quitting = true;
                        }
                        else if((px>=325 && px<=475) & (py>=410 && py<=510)){
                            //std::cout << "Niveau 3" << std::endl;
                            level = 3;
                            quitting = true;
                        }
                        else std::cout << "Aucun niveau sélectionné !" << std::endl;
                        // std::cout << "px = " << px <<" et py = "<< py << std::endl;
                        
                    }
                }
            }
        }
    }
    return level;
}

// int main(int argc, char* args[]){
//     sdl2::init(argc, args);
//     int level = Choix_Niveau(); 
//     sdl2::finalize();
//     return 0;
// }
