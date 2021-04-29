#include<iostream>
#include"Graphic_Fonction.hpp"
#include"SDL2/sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    // int level = 1;
    // Controle_win(level);
    std::string pseudo = Fenetre_acceuil(); 
    int level = Choix_Niveau();
    if (level == 1){
        Niveau1();
    }
    
    sdl2::finalize();
    return 0;
}