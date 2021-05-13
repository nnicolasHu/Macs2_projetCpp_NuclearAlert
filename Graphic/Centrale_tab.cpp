#include "Graphic_Fonction.hpp"


void Centrale_tab(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Schéma de la centrale", {800, 600});

    sdl2::image centrale("Graphic/data/sch├®ma_centrale.png", fenêtre);
    centrale.at(120, 100);
    centrale.stretch({1100, 500});

    // Stan by : on verra comment on va le gerer 
    // sdl2::texte echap("Appuyez sur echap pour revenir à la fenêtre précédente"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    // echap.at(200, 500); 

    sdl2::texte circuit_prim("Circuit primaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_prim.at(130, 550);
    sdl2::texte circuit_sec("Circuit secondaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_sec.at(390, 550);
    sdl2::texte circuit_refroid("Circuit de refroidissement"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_refroid.at(700, 550);
    sdl2::texte vapeur("Vapeur d'eau"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    vapeur.at(910, 180);
    
    bool quitting = false;
    sdl2::event_queue queue;

        fenêtre << centrale << circuit_prim << circuit_sec << circuit_refroid << vapeur << sdl2::flush;
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
