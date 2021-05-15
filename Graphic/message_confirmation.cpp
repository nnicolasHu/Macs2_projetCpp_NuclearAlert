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


void message_confirmation(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 20);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 30);

    fenêtre << sdl2::rectangle({350, 260}, {590, 110}, {0, 0, 0, 0}, true);
    fenêtre << sdl2::rectangle({350, 260}, {590, 110}, {0xFF, 0xFF, 0xFF, 0xFF}, false);
    
    // variable pour tester la fonction -> A retirer 
    //std::string message = "Vous vous apprêtez à retirer des ouvriers";
    std::string message = "Attention, Arrêt d'urgence, êtes-vous sur ?";
    
    sdl2::texte titre(message, fonte_titre, fenêtre, {0xFF, 0, 0, 0xFF});
    titre.at(370, 270);
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
