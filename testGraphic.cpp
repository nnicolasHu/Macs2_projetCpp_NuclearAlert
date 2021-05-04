#include<iostream>
#include"Graphic_Fonction.hpp"
#include"sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);

    sdl2::window fenêtre("Nuclear Alert", {800, 600});

    std::string pseudo = Fenetre_acceuil(&fenêtre); 
    std::cout << pseudo << std::endl;
    int level = Choix_Niveau(&fenêtre);
    if(level == 1) {
        fenêtre.cls({0, 0, 0, 0});
        Niveau1(&fenêtre);
    }

    // SalleDeControle();
    sdl2::finalize();
    return 0;
}