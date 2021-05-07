#include <iostream>
#include "sdl2.hpp"
#include <SDL2/SDL_ttf.h>

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    sdl2::window fenêtre("Nuclear Alert", {1250, 650});
    
    //sdl2::flush;

    bool quitting = false;
    bool espace = false;
    //Vaut 0 si on est sur la salle de contrôle et 1 si on est sur le poste de sécurité

    int affichage = 0;
    bool iskey_down = false;

    bool un_selected = false;
    bool deux_selected = false;
    bool B_selected = false;
    bool T_selected = false;
    bool P_selected = false; 
    bool R_selected = false;
    bool tab_selected = false;

    bool S_pressed = false;
    
    int t1,t2,t3,t4;
    sdl2::event_queue queue;

    while (not quitting) {
        t1 = SDL_GetTicks();
        // maj de la centrale



        
        t2 = SDL_GetTicks();
        while (t2-t1 < 1000) {
            //Affichage

            //gestion des touches
            auto events = queue.pull_events();
            for ( const auto& e : events) {
                if (e->kind_of_event() == sdl2::event::quit) {
                    quitting = true;
                }
                if ( (e->kind_of_event() == sdl2::event::key_down) || 
                (e->kind_of_event() == sdl2::event::key_up) ) {
                    auto& key_ev = dynamic_cast<sdl2::event_keyboard&>(*e);
                    if ( (key_ev.type_of_event() == sdl2::event::key_down) &&  (iskey_down == false) ) {
                        char keychar = key_ev.ascci_code();
                        std::cout << int(keychar) << std::endl;
                        //touche espace
                        if ((keychar==32) && (iskey_down==0) ) {
                            espace = 1 - espace;
                            affichage = espace;
                            std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                            std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                            std::cout << "la touche B vaut : " << B_selected << std::endl;
                            std::cout << "la touche T vaut : " << T_selected << std::endl;
                            std::cout << "la touche P vaut : " << P_selected << std::endl;
                            std::cout << "la touche R vaut : " << R_selected << std::endl;
                            std::cout << "la touche espace vaut : " << espace << std::endl;
                        }

                        //touche tab
                        if ((keychar==9) && (iskey_down==0) ) {
                            tab_selected = 1 - tab_selected;
                            if (tab_selected) affichage=3;
                            else affichage = espace; 

                        }

                        if (affichage == 0) {
                            //touche S
                            if ((keychar==115)  && (iskey_down==0) ) {
                                t3 = SDL_GetTicks();
                                S_pressed = 1;
                                un_selected=0; deux_selected=0; B_selected=0; T_selected=0; P_selected=0; R_selected=0;
                            }

                            //touche 1
                            if ((keychar==49) && (iskey_down==0) ) {
                                un_selected = 1 - un_selected;
                                deux_selected=0; B_selected=0; T_selected=0; P_selected=0; R_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            //touche 2
                            if ((keychar==50) && (iskey_down==0) ) {
                                deux_selected = 1 - deux_selected;
                                un_selected=0; B_selected=0; T_selected=0; P_selected=0; R_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            //touche B
                            if ((keychar==98) && (iskey_down==0) ) {
                                B_selected = 1 - B_selected;
                                un_selected=0; deux_selected=0; T_selected=0; P_selected=0; R_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            //touche T
                            if ((keychar==116) && (iskey_down==0) ) {
                                T_selected = 1 - T_selected;
                                un_selected=0; deux_selected=0; B_selected=0; P_selected=0; R_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            //touche P
                            if ((keychar==112) && (iskey_down==0) ) {
                                P_selected = 1 - P_selected;
                                un_selected=0; deux_selected=0; B_selected=0; T_selected=0; R_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            //touche R
                            if ((keychar==114) && (iskey_down==0) ) {
                                R_selected = 1 - R_selected;
                                un_selected=0; deux_selected=0; B_selected=0; T_selected=0; P_selected=0;
                                std::cout << "la touche 1 vaut : " << un_selected << std::endl;
                                std::cout << "la touche 2 vaut : " << deux_selected << std::endl;
                                std::cout << "la touche B vaut : " << B_selected << std::endl;
                                std::cout << "la touche T vaut : " << T_selected << std::endl;
                                std::cout << "la touche P vaut : " << P_selected << std::endl;
                                std::cout << "la touche R vaut : " << R_selected << std::endl;
                                std::cout << "la touche espace vaut : " << espace << std::endl;
                            }

                            
                        }





                        iskey_down = true;
                    }

                    if (key_ev.type_of_event() == sdl2::event::key_up) {
                        if (S_pressed == 1) {
                            S_pressed = 0;
                            t4 = SDL_GetTicks();
                            if (t4-t3>3000) quitting = true;
                        }
                        iskey_down = false;
                    }
                }
            }
            t2 = SDL_GetTicks();
            fenêtre << sdl2::flush;
        }








    }
    

    
    
    
    /*
    int t1 = espace;
    std::cout << t1 << std::endl;
    
    sdl2::event_queue queue;
    t1 = SDL_GetTicks();
    SDL_Delay(5000);
    t2 = SDL_GetTicks();    
    std::cout << t2-t1 << std::endl;
    */
    sdl2::finalize();
    return EXIT_SUCCESS;
}


