#include "Graphic_Fonction.hpp"
#include "sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include <iostream>

std::string Fenetre_acceuil(sdl2::window* fenêtre, int* dim_x, int* dim_y){
    double a = (*dim_x)/800.;
    double b = (*dim_y)/600.;
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Authentification", {800, 600});

    sdl2::texte phrase("Entrez votre pseudo : "s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    phrase.at(310*a, 310*b);
    sdl2::texte authentification("Authentification"s, fonte_titre, *fenêtre, {0xFF, 0, 0, 0xFF});
    authentification.at(290, 70);
    sdl2::texte phrase4("Puis appuyez sur 'Entree' une fois terminé. "s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    phrase4.at(250, 450);
    std::string pseudo;

    sdl2::image Alert("Graphic/data/Alert.png", *fenêtre);
    Alert.at(320,110); // Emplacement sur la fenêtre 
    Alert.stretch({128,128}); // Taille 
    Alert.flip(sdl2::image::horizontal);
    Alert.rotate({64,64}, 0);
    bool quitting = false;
    sdl2::event_queue queue;
    int xinput = 300, yinput = 400;
    
    while(not quitting){
        *fenêtre << sdl2::rectangle({290,350}, {200, 75}, {0,0,0xFF,0xFF}, false);
        *fenêtre << phrase << phrase4 << Alert<< authentification << sdl2::flush;
        *fenêtre << sdl2::rectangle({289, 349}, {199, 74}, {0, 0, 0, 0}, true);
        if (pseudo.size() > 0)
        {   
            sdl2::texte name(pseudo, fonte_texte, *fenêtre, {0xFF,0xFF,0xFF,0xFF});
            name.at(xinput,yinput);
            *fenêtre << name ; 
        }
        
        auto events = queue.pull_events();
        for(const auto& e : events){
            if(e->kind_of_event() == sdl2::event::quit) quitting = true;
            if(e->kind_of_event() == sdl2::event::key){
                auto& key = dynamic_cast<sdl2::event_keyboard&>(*e);
                if(key.state() == sdl2::event_keyboard::pressed){
                    char keychar = key.ascci_code();
                    if(keychar == 13) quitting = true;
                    if(pseudo.size() < 254){
                        if(keychar == 8){

                            pseudo.pop_back();
                            
                        } 
                        else {
                            pseudo.operator+=(keychar);
                            
                        }
                        
                    }

                }
            }
        }
    }
    return pseudo;
}

// int main(int argc, char* args[]){
//     sdl2::init(argc, args);
//     std::cout << Fenetre_acceuil() << std::endl;
//     sdl2::finalize();
//     return 0;
// }

