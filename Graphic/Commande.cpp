#include "Graphic_Fonction.hpp"
#include "sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<cmath> 

void Commande(sdl2::window * fenêtre){
    

    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Schéma de la centrale"s, {*dim_x, *dim_y});

    sdl2::texte titre("COMMANDES"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    titre.at(650, 50);
    
    sdl2::texte command1("1 : Rendement de la pompe du circuit primaire"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command1.at(350, 150);
    
    sdl2::texte command2("2 : Rendement de la pompe du circuit secondaire"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command2.at(350, 210);
    
    sdl2::texte commandB("B : Action sur les barres de contrôle (100% = totalement levées, 0%=totalement baissées)"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandB.at(350, 270);
    
    sdl2::texte commandT("T : Action sur le taux d'acide borique"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandT.at(350, 330);
    sdl2::texte commandP("P : Rendement pressuriseur"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandP.at(350, 390);
    sdl2::texte commandR("R : Rendement pompe condenseur"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandR.at(350, 450);
    sdl2::texte commandU1("U : Autorise en cas d'urgence l'enfoncement rapide des barres dans le réacteur."s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandU1.at(350, 510);
    sdl2::texte commandU2("(Cette procédure comporte des risques de dégradation.)"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandU2.at(350, 570);
    sdl2::texte commandTab("Tab : Affiche le schéma de la centrale"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandTab.at(350, 630);
    sdl2::texte commandE("Espace : Passage en poste sécurité radioprotection"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandE.at(350, 690);

    bool quitting = false;
    sdl2::event_queue queue;

    
    *fenêtre  << titre << command1 << command2 << commandB << commandT << commandP << commandR << commandU1 << commandU2 << commandTab << commandE << sdl2::flush;
    auto events = queue.pull_events();
    for(const auto& e : events){
        if(e->kind_of_event() == sdl2::event::quit) quitting = true;
        if(e->kind_of_event() == sdl2::event::key){
            auto& key = dynamic_cast<sdl2::event_keyboard&>(*e); // obliger quand tu cree une dynamique class
            if(key.state() == sdl2::event_keyboard::pressed){
                char keychar = key.ascci_code(); // code ascii
                if(keychar == 27) quitting = true; //27 touche echap
            }
                
        }
    }
    
    SDL_Delay(8000);

}
