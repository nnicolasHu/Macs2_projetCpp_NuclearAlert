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
    int O_selected = 1;
    /* O_selected vaut 4 quand on veut afficher l'interfaces pour l'intervention des ouvriers
        et vaut 1 si on ne l'affiche pas
    */
    int commande1_selected = 0; 
    /* commande1_selected vaut 5 quand on veut afficher les commandes pour salle de controle
        et vaut 0 si on ne l'affiche pas
    */
    int commande2_selected = 1;
    /* commande2_selected vaut 6 quand on veut afficher les commandes pour salle de controle
        et vaut 1 si on ne l'affiche pas
    */

    bool S_pressed = false;
    bool B_pressed = false;
    int B_memoire = 0;

    bool demande_ArretUrgence = false;
    bool evacuation = false;
    bool demande_evacuation = false;

    int clignotement;
    
    
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
                break;
            case 1:
                Radioprotection_win(fenêtre,C);
                break;
            case 2:
                Centrale_tab(fenêtre,C,clignotement);
                break;
            case 3:
                Bilanactiviteouvriere(fenêtre,C);
                break;
            case 4:
                InterventionO(fenêtre);
                break;
            case 5:
                Commande1(fenêtre);
                break;
            case 6:
                Commande2(fenêtre);
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
                        //touche espace
                        if ((keychar==32) && (iskey_down==0) ) {
                            espace = 1 - espace;
                            affichage = espace;
                            selected_controle = 0;
                            O_selected = 1;
                            commande1_selected = 0;
                            commande2_selected = 1;
                        }

                        //touche tab
                        if ((keychar==9) && (iskey_down==0) ) {
                            tab_selected = 1 - tab_selected;
                            if (tab_selected) affichage=2;
                            else affichage = espace;
                            selected_controle = 0;
                            O_selected = 1;
                            commande1_selected = 0;
                            commande2_selected = 1;
                        }
                        //touche S
                        if ((keychar==115)  && (iskey_down==0) ) {
                            stopBegin = SDL_GetTicks();
                            S_pressed = 1;
                            selected_controle = 0;
                            O_selected = 1;
                            commande1_selected = 0;
                            commande2_selected = 1;
                        }

                        //commande depuis la salle de contrôle
                        if (espace == 0) {
                            //touche h
                            if ((keychar==104) && (iskey_down==0) ) {
                                commande1_selected = 5 - commande1_selected;
                                affichage = commande1_selected;
                                tab_selected = 0;
                            }                             

                            //touche 1
                            if ((keychar==49) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==1) selected_controle=0;
                                else selected_controle=1;
                                
                            }

                            //touche 2
                            if ((keychar==50) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==2) selected_controle=0;
                                else selected_controle=2;
                                
                            }

                            //touche B
                            if ((keychar==98) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==3) selected_controle=0;
                                else selected_controle=3;
                                
                            }

                            //touche T
                            if ((keychar==116) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==4) selected_controle=0;
                                else selected_controle=4;
                                
                            }

                            //touche P
                            if ((keychar==112) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==5) selected_controle=0;
                                else selected_controle=5;
                                
                            }

                            //touche R
                            if ((keychar==114) && (iskey_down==0) ) {
                                affichage = 0;
                                commande1_selected = 0;
                                if (selected_controle==6) selected_controle=0;
                                else selected_controle=6;
                                
                            }

                            if (key_ev.code() == sdl2::event_keyboard::up) {
                                switch (selected_controle) {
                                case 1:
                                    // on augmente le rendement de la pompe circuit primaire
                                    C.get_Circuit_Primaire().incr_F_pompe();
                                    std::cout << "on augmente le rendement de la pompe circuit primaire" << std::endl;
                                    break;
                                case 2:
                                    // on augmente le rendement de la pompe circuit secondaire
                                    C.get_Circuit_Secondaire().incr_F_pompe(); //problème?
                                    std::cout << C.get_Circuit_Secondaire().get_F_pompe() << std::endl;
                                    std::cout << "on augmente le rendement de la pompe circuit secondaire" << std::endl;
                                    break;
                                case 3:
                                    // on sort les barres de graphite hors de l'eau
                                    std::cout << "on augmente TxGraphite" << std::endl;
                                    break;
                                case 4:
                                    // on augmente le taux de bore dans l'eau
                                    std::cout << "on augmente TxBore" << std::endl;
                                    break;
                                case 5:
                                    // on augmente la température du pressuriseur
                                    C.get_Circuit_Primaire().incr_T_pressuriseur();
                                    std::cout << C.get_Circuit_Primaire().get_T_pressuriseur() << std::endl;
                                    std::cout << "on augmente rendement pressuriseur" << std::endl;
                                    break;
                                case 6:
                                    // on augmente le rendement de la pompe condenseur
                                    std::cout << "on augmente rendement pompe condenseur" << std::endl;
                                    break;
                                }
                            }

                            if (key_ev.code() == sdl2::event_keyboard::down) {
                                switch (selected_controle) {
                                case 1:
                                    // on augmente le rendement de la pompe circuit primaire
                                    C.get_Circuit_Primaire().decr_F_pompe();
                                    break;
                                case 2:
                                    // on baisse le rendement de la pompe circuit secondaire
                                    C.get_Circuit_Secondaire().decr_F_pompe();
                                    std::cout << "on baisse le rendement de la pompe circuit secondaire" << std::endl;
                                    break;
                                case 3:
                                    // on plonge les barres de graphite dans l'eau
                                    std::cout << "on baisse TxGraphite" << std::endl;
                                    break;
                                case 4:
                                    // on baisse le taux de bore dans l'eau
                                    std::cout << "on baisse TxBore" << std::endl;
                                    break;
                                case 5:
                                    // on baisse la température du pressuriseur
                                    C.get_Circuit_Primaire().decr_T_pressuriseur();
                                    std::cout << "on baisse rendement pressuriseur" << std::endl;
                                    break;
                                case 6:
                                    // on baisse le rendement de la pompe condenseur
                                    std::cout << "on baisse rendement pompe condenseur" << std::endl;
                                    break;
                                }
                            }

                            //touche U
                            if ((keychar==117) && (iskey_down==0) ) {
                                demande_ArretUrgence = 1;
                                affichage = 0;
                                selected_controle = 0;
                                commande1_selected = 0;
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
                            //touche h
                            if ((keychar==104) && (iskey_down==0) ) {
                                commande2_selected = 6 - commande2_selected + 1; //varie entre 1 et 6
                                affichage = commande2_selected;
                                tab_selected = 0;
                                O_selected = 1;
                            }

                            //touche P
                            if ((keychar==112) && (iskey_down==0) && (evacuation==0) && (O_selected!=4)) {
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
                                B_memoire = affichage;
                                affichage = 3;
                            }

                            //touche O
                            if ((keychar==111) && (iskey_down==0)) {
                                O_selected = 4 - O_selected +1; //varie entre 1 et 4 
                                commande2_selected = 1;
                                affichage = O_selected;
                            }

                            if (O_selected==4) {
                                if ((keychar==49) && (iskey_down==0)) {
                                    std::cout << "on envoie vers 1" << std::endl;
                                }
                                if ((keychar==50) && (iskey_down==0)) {
                                    std::cout << "on envoie vers 2" << std::endl;
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
                            commande2_selected = 1;
                            affichage = B_memoire; //on revient à ce qu'il y avait avant
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
        }
    }



}