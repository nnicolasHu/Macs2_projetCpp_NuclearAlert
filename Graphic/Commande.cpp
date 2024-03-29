#include "Graphic_Fonction.hpp"


void Commande1(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    fenêtre<< sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::texte titre("COMMANDES"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    titre.at(550, 20);
    
    sdl2::texte command1("1 : Modifie le rendement de la pompe du circuit primaire : utiliser les flèches du clavier"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command1.at(100, 90);
    
    sdl2::texte command2("2 : Modifie le rendement de la pompe du circuit secondaire : utiliser les flèches du clavier"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    command2.at(100, 150);
    
    sdl2::texte commandB("B : Modife l'action sur les barres de contrôle (100% = totalement levées, 0%=totalement baissées) : use arrows"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandB.at(100, 210);
    
    sdl2::texte commandT("T : Modifie l'action sur le taux d'acide borique : utiliser les flèches du clavier"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandT.at(100, 270);
    sdl2::texte commandP("P : Modifie la temperature pressuriseur : utiliser les flèches du clavier"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandP.at(100, 330);
    sdl2::texte commandR("R : Modifie le rendement pompe condenseur : utiliser les flèches du clavier"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandR.at(100, 390);
    sdl2::texte commandU1("U : Autorise en cas d'urgence l'enfoncement rapide des barres dans le réacteur."s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandU1.at(100, 450);
    sdl2::texte commandU2("(Cette procédure comporte des risques de dégradation.)"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandU2.at(100, 490);
    sdl2::texte commandTab("Tab : Affiche le schéma de la centrale"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandTab.at(100, 550);
    sdl2::texte commandE("Espace : Passage en poste sécurité radioprotection"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandE.at(100, 610);

    //bool quitting = false;
    //sdl2::event_queue queue;

    
    fenêtre  << titre << command1 << command2 << commandB << commandT << commandP << commandR << commandU1 << commandU2 << commandTab << commandE;
/*     auto events = queue.pull_events();
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
    
    SDL_Delay(8000); */

}


void Commande2(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 40);
    fenêtre<< sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::texte titre("COMMANDES"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    titre.at(550, 20);
    
    sdl2::texte commandTab("Tab : Affiche le schéma de la centrale"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandTab.at(100, 150);
    
    sdl2::texte commandE("Espace : Retour à la salle de controle"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandE.at(100, 210);
    
    sdl2::texte commandP("P : Demande l'évacuation de la population après confirmation"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandP.at(100, 270);
    
    sdl2::texte commandB("B : Bilan de l'activité ouvrière"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandB.at(100, 330);

    sdl2::texte commandO("O : Gestion de l'activité ouvrière"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    commandO.at(100, 390);

    //bool quitting = false;
    //sdl2::event_queue queue;
    fenêtre  << titre << commandTab << commandE << commandP << commandB << commandP << commandO;
/*     auto events = queue.pull_events();
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
    
    SDL_Delay(8000); */

}
