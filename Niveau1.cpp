#include"niveaux.hpp"

void Niveau1(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);

    centrale C;
    bool quitting = false;
    bool espace = false;
    //Vaut 0 si on est sur la salle de contrôle et 1 si on est sur le poste de sécurité

    int affichage = 0;
    /*
    affichage vaut :    0 quand on veut afficher la salle de contrôle
                        1 quand on veut afficher le poste de sécurité
                        2 quand on veut afficher la carte
                        3 quand on veut afficher bilan ouvrier
                        4 interface ouvrier?
                        5 commande1
                        6 commande2

    */

    int selected_controle = 0;
    /*
    selected_controle vaut :    0 si rien n'est selectionné
                                1 pour le rendrement de la pompe du circuit primaire
                                2 pour le rendrement de la pompe du circuit secondaire
                                3 pour les barres de Graphite
                                4 pour le taux de Bore
                                5 pour le rendement du pressuriseur
                                6 pour le rendement pompe condenseur
    */
    bool iskey_down = false;
   
    bool tab_selected = false;
    bool O_selected = false;

    bool S_pressed = false;
    bool B_pressed = false;

    bool demande_ArretUrgence = false;
    bool evacuation = false;
    bool demande_evacuation = false;
    
    
    int loopBegin,loopEnd,stopBegin,stopEnd;
    sdl2::event_queue queue;

    while (not quitting) {
        loopBegin = SDL_GetTicks();
        // maj de la centrale



        
        loopEnd = SDL_GetTicks();
        while ((not quitting) && (loopEnd-loopBegin < 1000)) {
            //Affichage
            
            switch (affichage) {
            case 0:
                SalleDeControle(fenêtre,C);
                //std::cout << "on affiche salle de controle" << std::endl;
                break;
            case 1:
                Radioprotection_win(fenêtre,C);
                //std::cout << "on affiche poste de sécurité" << std::endl;
                break;
            case 2:
                std::cout << "on affiche carte" << std::endl;
                break;
            case 3:
                std::cout << "on affiche bilan ouvrier" << std::endl;
                break;
            case 4:
                std::cout << "on affiche interface ouvrier" << std::endl;
                break;
            case 5:
                std::cout << "on affiche commande de salle de controle" << std::endl;
                break;
            case 6:
                std::cout << "on affiche commande de poste sécurité" << std::endl;
                break;
            }
            
            //gestion des touches
            auto events = queue.pull_events();
            for ( const auto& e : events) {
                if (e->kind_of_event() == sdl2::event::quit) {
                    quitting = true;
                }
                if ( (e->kind_of_event() == sdl2::event::key_down) || 
                (e->kind_of_event() == sdl2::event::key_up) ) {
                    auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e);

                    //quand on appuie sur une touche
                    if ( (key_ev.type_of_event() == sdl2::event::key_down) &&  (iskey_down == false) ) {
                        char keychar = key_ev.ascci_code();
                        std::cout << int(keychar) << std::endl; // à enlever
                        //touche espace
                        if ((keychar==32) && (iskey_down==0) ) {
                            espace = 1 - espace;
                            affichage = espace;
                            selected_controle = 0;
                            O_selected = 0;
                            
                            std::cout << "la touche espace vaut : " << espace << std::endl;
                            std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                        }

                        //touche tab
                        if ((keychar==9) && (iskey_down==0) ) {
                            tab_selected = 1 - tab_selected;
                            if (tab_selected) affichage=2;
                            else affichage = espace;
                            selected_controle = 0;
                            O_selected = 0;
                            std::cout << "on affiche : " << affichage << std::endl;

                        }
                        //touche S
                        if ((keychar==115)  && (iskey_down==0) ) {
                            stopBegin = SDL_GetTicks();
                            S_pressed = 1;
                            selected_controle = 0;
                            O_selected = 0;
                        }

                        //commande depuis la salle de contrôle
                        if (espace == 0) {                             

                            //touche 1
                            if ((keychar==49) && (iskey_down==0) ) {
                                if (selected_controle==1) selected_controle=0;
                                else selected_controle=1;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            //touche 2
                            if ((keychar==50) && (iskey_down==0) ) {
                                if (selected_controle==2) selected_controle=0;
                                else selected_controle=2;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            //touche B
                            if ((keychar==98) && (iskey_down==0) ) {
                                if (selected_controle==3) selected_controle=0;
                                else selected_controle=3;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            //touche T
                            if ((keychar==116) && (iskey_down==0) ) {
                                if (selected_controle==4) selected_controle=0;
                                else selected_controle=4;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            //touche P
                            if ((keychar==112) && (iskey_down==0) ) {
                                if (selected_controle==5) selected_controle=0;
                                else selected_controle=5;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            //touche R
                            if ((keychar==114) && (iskey_down==0) ) {
                                if (selected_controle==6) selected_controle=0;
                                else selected_controle=6;
                                std::cout << "selected_controle vaut : " << selected_controle << std::endl;
                                
                            }

                            if (key_ev.code() == sdl2::event_keyboard::up) {
                                switch (selected_controle) {
                                case 1:
                                    // on augmente le rendement de la pompe circuit primaire
                                    std::cout << "on augmente le rendement de la pompe circuit primaire" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "on augmente le rendement de la pompe circuit secondaire" << std::endl;
                                    break;
                                case 3:
                                    std::cout << "on augmente TxGraphite" << std::endl;
                                    break;
                                case 4:
                                    std::cout << "on augmente TxBore" << std::endl;
                                    break;
                                case 5:
                                    std::cout << "on augmente rendement pressuriseur" << std::endl;
                                    break;
                                case 6:
                                    std::cout << "on augmente rendement pompe condenseur" << std::endl;
                                    break;
                                }
                            }

                            if (key_ev.code() == sdl2::event_keyboard::down) {
                                switch (selected_controle) {
                                case 1:
                                    // on augmente le rendement de la pompe circuit primaire
                                    std::cout << "on baisse le rendement de la pompe circuit primaire" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "on baisse le rendement de la pompe circuit secondaire" << std::endl;
                                    break;
                                case 3:
                                    std::cout << "on baisse TxGraphite" << std::endl;
                                    break;
                                case 4:
                                    std::cout << "on baisse TxBore" << std::endl;
                                    break;
                                case 5:
                                    std::cout << "on baisse rendement pressuriseur" << std::endl;
                                    break;
                                case 6:
                                    std::cout << "on baisse rendement pompe condenseur" << std::endl;
                                    break;
                                }
                            }

                            //touche U
                            if ((keychar==117) && (iskey_down==0) ) {
                                demande_ArretUrgence = 1;
                                selected_controle = 0;
                            }

                            if (demande_ArretUrgence) {
                                std::cout << "arrêt d'urgence?" << std::endl;
                                if ((keychar==121) && (iskey_down==0) ) { //appuie sur Y
                                    //tentative d'arrêt d'urgence
                                    std::cout << "tentative d'arrêt d'urgence" << std::endl;
                                    demande_ArretUrgence = 0;
                                }
                                if ((keychar==110) && (iskey_down==0) ) { //appuie sur N
                                    std::cout << "annulation tentative arrêt d'urgence" << std::endl;
                                    demande_ArretUrgence = 0;
                                }

                            }





                            
                        }

                        //commande depuis le poste de sécurité
                        if (espace == 1) { 
                            //touche P
                            if ((keychar==112) && (iskey_down==0) && (evacuation==0) && (not O_selected)) {
                                demande_evacuation = 1;
                                std::cout << "demande évacuation" << std::endl;
                            }

                            if (demande_evacuation) {
                                std::cout << "evacuation?" << std::endl;
                                if ((keychar==121) && (iskey_down==0) ) { //appuie sur Y
                                    //évacuation de la population
                                    evacuation = 1;
                                    demande_evacuation = 0;
                                    std::cout << "on évacue" << std::endl;                                   
                                }
                                
                                if ((keychar==110) && (iskey_down==0) ) { //appuie sur N
                                    demande_evacuation = 0;
                                    std::cout << "annulation de l'évacuation" << std::endl;
                                }
                            }

                            //touche B
                            if ((keychar==98) && (iskey_down==0)) {
                                B_pressed = 1;
                                affichage = 3;
                                std::cout << "on appuie sur B" << std::endl;
                            }

                            //touche O
                            if ((keychar==111) && (iskey_down==0)) {
                                O_selected = 1-O_selected;
                                std::cout << "O_selected vaut : " << O_selected << std::endl;
                            }

                            if (O_selected) {
                                if ((keychar==49) && (iskey_down==0)) {
                                    std::cout << "on envoie vers 1" << std::endl;
                                }
                                if ((keychar==50) && (iskey_down==0)) {
                                    std::cout << "on envoie vers atchoum" << std::endl;
                                }
                                if ((keychar==99) && (iskey_down==0)) {
                                    std::cout << "on envoie vers C" << std::endl;
                                }  
                                if ((keychar==103) && (iskey_down==0)) {
                                    std::cout << "on envoie vers G" << std::endl;
                                } 
                                if ((keychar==98) && (iskey_down==0)) {
                                    std::cout << "on envoie vers B" << std::endl;
                                }
                                if ((keychar==105) && (iskey_down==0)) {
                                    std::cout << "on envoie vers I" << std::endl;
                                }
                                if ((keychar==114) && (iskey_down==0)) {
                                    std::cout << "on envoie vers R" << std::endl;
                                }
                                if ((keychar==112) && (iskey_down==0)) {
                                    std::cout << "on envoie vers P" << std::endl;
                                }
                            }



                        }





                        iskey_down = true;
                    }

                    //quand on soulève une touche
                    if (key_ev.type_of_event() == sdl2::event::key_up) {
                        if (B_pressed) {
                            B_pressed = 0;
                            affichage = 1; //on revient au poste de sécurité
                            //std::cout << "on affiche 1" << std::endl; 
                        }
                        S_pressed = 0;                        
                        iskey_down = false;
                    }
                }
                if (S_pressed) {
                    stopEnd = SDL_GetTicks();
                    if (stopEnd-stopBegin>3000) quitting = true;
                }
            }
            
            loopEnd = SDL_GetTicks();
            fenêtre << sdl2::flush; //à enlever?
        }
    }



}