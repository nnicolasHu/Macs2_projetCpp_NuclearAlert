#include "Graphic_Fonction.hpp"

#include <string>

using namespace std;


void InterventionO(sdl2::window& fenêtre, centrale& C){
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

    /// En cours ///
    sdl2::texte en_cours("Intervention en cours"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    en_cours.at(1000, 20);

    //En cours pompe circuitPrimaire
    string cpcp = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(0) != 0)){
        cpcp = "Oui";
    }
    sdl2::texte cours_pcp(cpcp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_pcp.at(1015, 90);

    //En cours pompe circuitSecondaire
    string cpcs = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(1) != 0)){
        cpcs = "Oui";
    }
    sdl2::texte cours_pcs(cpcs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_pcs.at(1015, 150);

    //En cours condenseur
    string ccond = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(2) != 0)){
        ccond = "Oui";
    }
    sdl2::texte cours_cond(ccond, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cond.at(1015, 210);

    //En cours généréteur de vapeur
    string cgenvap = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(3) != 0)){
        cgenvap = "Oui";
    }
    sdl2::texte cours_gen_vap(cgenvap, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_gen_vap.at(1015, 270);

    //En cours injecteur
    string cinject = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(4) != 0)){
        cinject = "Oui";
    }
    sdl2::texte cours_inject(cinject, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_inject.at(1015, 330);

    //En cours circuitPrimaire
    string ccp = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(5) != 0)){
        ccp = "Oui";
    }
    sdl2::texte cours_cp(ccp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cp.at(1015, 390);

    //En cours circuitSecondaire
    string ccs = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(6) != 0)){
        ccs = "Oui";
    }
    sdl2::texte cours_cs(ccs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cs.at(1015, 450);

    //En cours pressuriseur
    string cpress = "Non";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(7) != 0)){
        cpress = "Oui";
    }
    sdl2::texte cours_press(cpress, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_press.at(1015, 510);
    

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
    }*/
    
    SDL_Delay(3000); 

}