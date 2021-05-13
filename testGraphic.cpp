#include<iostream>
#include"niveaux.hpp"
#include"sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);

    sdl2::window fenêtre("Nuclear Alert", {1250, 650});
    centrale C;

    Niveau1(fenêtre); 
    //Radioprotection_win(1);
    // std::cout << pseudo << std::endl;
    // int level = Choix_Niveau(fenêtre);
    // if(level == 1) {
    //     fenêtre.cls({0, 0, 0, 0});
    //     Niveau1(fenêtre);
    // }

    // SalleDeControle();
    //Commande2(fenêtre);
    sdl2::finalize();
    return 0;
}