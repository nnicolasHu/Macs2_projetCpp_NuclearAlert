#include<iostream>
#include"Graphic_Fonction.hpp"
#include"sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);

    int dim_x = 1200, dim_y = 1000;

    sdl2::window fenêtre("Nuclear Alert", {dim_x, dim_y});

    std::string pseudo = Fenetre_acceuil(&fenêtre, &dim_x, &dim_y); 
    //Radioprotection_win(1);
    // std::cout << pseudo << std::endl;
    // int level = Choix_Niveau(&fenêtre);
    // if(level == 1) {
    //     fenêtre.cls({0, 0, 0, 0});
    //     Niveau1(&fenêtre);
    // }

    // SalleDeControle();
    sdl2::finalize();
    return 0;
}