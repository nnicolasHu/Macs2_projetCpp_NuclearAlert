#include "Graphic_Fonction.hpp"
#include "sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include <iostream>

std::string Fenetre_acceuil(sdl2::window* fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    sdl2::font fonte_pseudo("./Graphic/data/Lato-Heavy.ttf", 24);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Authentification", {800, 600});

    sdl2::texte phrase("Entrez votre pseudo : "s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    phrase.at(580, 330);
    sdl2::texte authentification("Authentification"s, fonte_titre, *fenêtre, {0xFF, 0, 0, 0xFF});
    authentification.at(550, 70);
    sdl2::texte phrase4("Puis appuyez sur 'Entree' une fois terminé. "s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    phrase4.at(470, 600);
    std::string pseudo;

    sdl2::image Alert("Graphic/data/Alert.png", *fenêtre);
    Alert.at(630,140); // Emplacement sur la fenêtre 
    Alert.stretch({150,150}); // Taille 
    Alert.flip(sdl2::image::horizontal);
    Alert.rotate({64,64}, 0);

    bool quitting = false;
    sdl2::event_queue queue;
    int xinput = 560, yinput = 450;

    while(not quitting){
        *fenêtre << sdl2::rectangle({550,400}, {300, 150}, {0,0,0xFF,0xFF}, false);
        *fenêtre << phrase << phrase4 << Alert<< authentification << sdl2::flush;
        *fenêtre << sdl2::rectangle({289, 349}, {199, 74}, {0, 0, 0, 0}, true);
        if (pseudo.size() > 0)
        {   
            sdl2::texte name(pseudo, fonte_pseudo, *fenêtre, {0xFF,0xFF,0xFF,0xFF});
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
                            //fenêtre->cls({0, 0, 0, 0});
                        } 
                        else {
                            pseudo.operator+=(keychar);
                            // fenêtre->cls({0, 0, 0, 0});
                            
                        }
                        
                    }

                }
            }
        }
    }
    std::cout << pseudo << std::endl;
    return pseudo;
}

// int main(int argc, char* args[]){
//     sdl2::init(argc, args);
//     std::cout << Fenetre_acceuil() << std::endl;
//     sdl2::finalize();
//     return 0;
// }