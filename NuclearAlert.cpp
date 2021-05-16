#include "niveaux.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    sdl2::window fenêtre("Nuclear Alert", {1250, 650});
    std::string pseudo;
    int level;

    pseudo = Fenetre_acceuil(fenêtre);
    do {
        level = Choix_Niveau(fenêtre);
    } while (level!=1);

    switch (level)
    {
    case 1:
        Niveau1(fenêtre, pseudo);
        break;
    case 2:
        std::cout << "pas implémenté" << std::endl;
        break;
    case 3:
        std::cout << "pas implémenté" << std::endl;
        break;
    }
    



    sdl2::finalize();
    return EXIT_SUCCESS;
}

