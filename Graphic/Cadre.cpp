
#include"Graphic_Fonction.hpp"

using namespace std::string_literals;

void SalleDeControle(){//centrale* C
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 14);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 18);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    sdl2::window fenêtre("Nuclear Alert : Cadres", {800, 600});

    //Cadre circuit primaire 
    sdl2::texte titre("Circuit Primaire", fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(140, 60);
    sdl2::texte rendement("Rendement : ", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rendement.at(60, 90);
    sdl2::texte pourcentage("%", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pourcentage.at(330, 90);
    sdl2::texte temperature("Température dans le circuit", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    temperature.at(60, 110);
    sdl2::texte degre("C", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    degre.at(330, 110);
    sdl2::texte debit("Débit d'eau : ", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    debit.at(60, 130);
    sdl2::texte mcube("m^3/s", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    mcube.at(310, 130);
    sdl2::texte pression("Pression : ", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pression.at(60, 150);
    sdl2::texte bar("bar", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bar.at(320, 150);
    sdl2::texte radioactivite("Radioactivité : ", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    radioactivite.at(60, 170);
    sdl2::texte bec("becquerel", fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bec.at(280, 170);


    bool quitting = false;
    sdl2::event_queue queue;

        fenêtre << pression << bar << radioactivite << bec << debit << mcube << degre<< temperature << titre << rendement << pourcentage << sdl2::rectangle({50, 50}, {300, 150}, {0xAD, 0xFF, 0x2F, 0}, false)<< sdl2::flush;
        auto events = queue.pull_events();
        for(const auto& e : events){
            if(e->kind_of_event() == sdl2::event::quit) quitting = true;
            if(e->kind_of_event() == sdl2::event::key){
                auto& key = dynamic_cast<sdl2::event_keyboard&>(*e);
                if(key.state() == sdl2::event_keyboard::pressed){
                    char keychar = key.ascci_code();
                    if(keychar == 27) quitting = true;
                }
                
            }
        }

    SDL_Delay(3000);
    //
}