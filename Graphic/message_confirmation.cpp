#include"Graphic_Fonction.hpp"

// A decommenter si besoin de confirmation pour quitter
// penser a l'ajouter dans Graphic_Fonction.hpp
// void quit_confirmation(sdl2::window& fenêtre, centrale& C){
//     sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 20);
//     sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 30);

//     fenêtre << sdl2::rectangle({350, 250}, {600, 120}, {0, 0, 0, 0}, true);
//     fenêtre << sdl2::rectangle({350, 250}, {600, 120}, {0xFF, 0xFF, 0xFF, 0xFF}, false);

//     sdl2::texte titre("Vous vous apprêtez à éteindre la centrale", fonte_titre, fenêtre, {0xFF, 0, 0, 0xFF});
//     titre.at(370, 270);
//     sdl2::texte conseil("(Relâcher la touche S pour ne pas quitter)", fonte_texte, fenêtre, {0xFF, 0, 0, 0xFF});
//     conseil.at(450, 300);

//     fenêtre << titre << conseil;

//     //bool quitting = false;
//     sdl2::event_queue queue;
//     auto events = queue.pull_events();

//     fenêtre << sdl2::flush; 
//     SDL_Delay(3000); 

// }


void message_confirmation(sdl2::window& fenêtre, int choix){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 20);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 30);

    //fenêtre << sdl2::rectangle({350, 260}, {590, 110}, {0, 0, 0, 0}, true);
    //fenêtre << sdl2::rectangle({350, 260}, {590, 110}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
    
    // variable pour tester la fonction -> A retirer 
    //std::string message = "Vous vous apprêtez à retirer des ouvriers";
    std::string message;

    switch (choix) {
        case 0:
            message = "Souhaitez-vous retirer les ouvriers de la pompe circuit primaire ?"s;
            break;
        case 1:
            message = "Souhaitez-vous retirer les ouvriers de la pompe du circuit secondaire ?"s;
            break;
        case 2:
            message = "Souhaitez-vous retirer les ouvriers du condenseur ?"s;
            break;
        case 3:
            message = "Souhaitez-vous retirer les ouvriers du générateur de vapeur ?"s;
            break;
        case 4:
            message = "Souhaitez-vous retirer les ouvriers de l'injecteur d'acide borique ?"s;
            break;
        case 5:
            message = "Souhaitez-vous retirer les ouvriers du circuit primaire ?"s;
            break;
        case 6:
            message = "Souhaitez-vous retirer les ouvriers du circuit secondaire ?"s;
            break;
        case 7:
            message = "Souhaitez-vous retirer les ouvriers du pressuriseur ?"s;
            break;
        case 8:
            message = "Tentative d'arret d'urgence ! Risque de dégradations"s;
            break;
        case 9:
            message = "Souhaitez vous donner l'ordre d'évacuation de la population ?"s;
            break;
        case 10:
            message = "Fin de session ?"s;
            break;
    }
    
    sdl2::texte titre(message, fonte_titre, fenêtre, {0xFF, 0, 0, 0xFF});

    switch (choix) {
    case 0:
        titre.at(200,250);
        fenêtre << titre << sdl2::rectangle({180, 240}, {900, 130}, {0, 0, 0, 0})<< sdl2::rectangle({180, 240}, {900, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 1:
        titre.at(200,250);
        fenêtre << titre << sdl2::rectangle({180, 240}, {960, 130}, {0, 0, 0, 0}) << sdl2::rectangle({180, 240}, {960, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 2:
        titre.at(310,250);
        fenêtre << titre << sdl2::rectangle({260, 240}, {780, 130}, {0, 0, 0, 0}) << sdl2::rectangle({260, 240}, {780, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 3:
        titre.at(250,250);
        fenêtre << titre << sdl2::rectangle({232, 240}, {840, 130}, {0, 0, 0, 0})<< sdl2::rectangle({232, 240}, {840, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 4:
        titre.at(220,250);
        fenêtre << titre << sdl2::rectangle({200, 240}, {900, 130}, {0, 0, 0, 0})<< sdl2::rectangle({200, 240}, {900, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 5:
        titre.at(280,250);
        fenêtre << titre << sdl2::rectangle({260, 240}, {770, 130}, {0, 0, 0, 0}) << sdl2::rectangle({260, 240}, {770, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 6:
        titre.at(280,250);
        fenêtre << titre << sdl2::rectangle({260, 240}, {800, 130}, {0, 0, 0, 0}) << sdl2::rectangle({260, 240}, {800, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 7:
        titre.at(310,250);
        fenêtre << titre << sdl2::rectangle({260, 240}, {780, 130}, {0, 0, 0, 0}) << sdl2::rectangle({260, 240}, {780, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 8:
        titre.at(300,250);
        fenêtre << titre << sdl2::rectangle({260, 200}, {780, 170}, {0, 0, 0, 0}) << sdl2::rectangle({260, 200}, {780, 170}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 9:
        titre.at(260,250);
        fenêtre << titre << sdl2::rectangle({240, 240}, {850, 130}, {0, 0, 0, 0})<< sdl2::rectangle({240, 240}, {850, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    case 10:
        titre.at(550,250);
        fenêtre << titre << sdl2::rectangle({520, 240}, {260, 130}, {0, 0, 0, 0})<< sdl2::rectangle({520, 240}, {260, 130}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
        break;
    }
    
    sdl2::texte Y("(Y)"s, fonte_titre, fenêtre, {0xFF, 0, 0, 0xFF});
    Y.at(570, 320);
    sdl2::texte N("(N)"s, fonte_titre, fenêtre, {0xFF, 0, 0, 0xFF});
    N.at(690, 320);
    fenêtre << titre << Y << N;

    

    // // Commande pour tester la fonction 
    // sdl2::event_queue queue;
    // auto events = queue.pull_events();


    // SDL_Delay(3000); 
}
