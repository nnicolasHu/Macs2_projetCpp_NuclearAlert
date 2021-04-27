#include<iostream>
#include"Graphic_Fonction.hpp"
#include"SDL2/sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    std::cout << Fenetre_acceuil() << std::endl;
    std::cout << Choix_Niveau() << std::endl;
    sdl2::finalize();
    return 0;
}