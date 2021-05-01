#include<iostream>
#include"Graphic_Fonction.hpp"
#include"sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    std::string pseudo = Fenetre_acceuil(); 
    std::cout << pseudo << std::endl;
    int level = Choix_Niveau();
    if(level == 1) Niveau1();
    sdl2::finalize();
    return 0;
}