#include "Graphic_Fonction.hpp"


void InterventionO(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    fenêtre<< sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::texte titre("Intervention des ouvriers"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    titre.at(500, 20);
    
    sdl2::texte command1("1 : La pompe du circuit primaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command1.at(100, 90);
    
    sdl2::texte command2("2 : La pompe du circuit secondaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command2.at(100, 150);
    
    sdl2::texte commandC("C : Le condenseur"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandC.at(100, 210);
    
    sdl2::texte commandG("G : Le générateur de vapeur"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandG.at(100, 270);

    sdl2::texte commandB("B : L’injecteur d’acide borique"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandB.at(100, 330);

    sdl2::texte commandI("I : Le circuit primaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandI.at(100, 390);

    sdl2::texte commandR("R : Le circuit secondaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandR.at(100, 450);

    sdl2::texte commandP("P : Le pressuriseur"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandP.at(100, 510);


    //bool quitting = false;
    //sdl2::event_queue queue;
    fenêtre  << titre << command1 << command2 << commandC << commandG << commandB << commandI << commandR << commandP << sdl2::flush;
    /* auto events = queue.pull_events();
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
    
    SDL_Delay(3000); */

}