#include"niveaux.hpp"
#include<iostream>

void BilanJeu(sdl2::window& fenetre, centrale&C, int nb_point){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 20);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 24);

    sdl2::texte Bilan("Bilan", fonte_titre, fenetre, {0xFF, 0, 0, 0xFF});
    Bilan.at(600, 10);

    sdl2::texte Etat_centrale("Etat de la centrale", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    Etat_centrale.at(100, 100);

    sdl2::texte nbpoint("Performance du dispatching", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    nbpoint.at(100, 150);

    //// Etat de la centrale ////
    double central_ok = C.get_E_centrale();
    if(central_ok>0.80){
        sdl2::texte Centrale_bon("La centrale est en bon état", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        Centrale_bon.at(800, 100);
        fenetre << Centrale_bon;
    }
    else if((central_ok <=0.80) & (central_ok > 0.5) ){
        sdl2::texte Centrale_bon("La centrale est assez endommagée", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        Centrale_bon.at(800, 100);
        fenetre << Centrale_bon;
    }
    else if ((central_ok <=0.5) & (central_ok > 0.2)){
        sdl2::texte Centrale_bon("La centrale est en bon état", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        Centrale_bon.at(800, 100);
        fenetre << Centrale_bon;
    }
    else if(central_ok <= 0.2){
        sdl2::texte Centrale_bon("La centrale est en bon état", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        Centrale_bon.at(800, 100);
        fenetre << Centrale_bon;
    }

    //// Nombre de points
    if(nb_point>8){
        sdl2::texte perf("Performances correctes, en route pour une augmentation", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        perf.at(700, 150);
        fenetre << perf;
    }
    else if((nb_point>5) & (nb_point<=8)){
        sdl2::texte perf("Performances moyennes, tu peux faire mieux ...", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        perf.at(800, 150);
        fenetre << perf;
    }
    else{
        sdl2::texte perf("Performances décevantes, le boss veut te voir !", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        perf.at(800, 150);
        fenetre << perf;
    }

    //Production électrique
    double prod = C.get_MW();
    sdl2::texte titre_MW("Production électrique", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    titre_MW.at(100, 200);

    if(prod<300){
        sdl2::texte conso("Faible production électrique", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        conso.at(800, 200);
        fenetre << conso;
    }
    else if((prod>=300) & (prod<900)){
        sdl2::texte conso("Production électrqiue peu rentable", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        conso.at(800, 200);
        fenetre << conso;
    }
    else if((prod>=900) & (prod<1200)){
        sdl2::texte conso("Production électrique correcte", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        conso.at(800, 200);
        fenetre << conso;
    }
    else if((prod >= 1200) & (prod<1400)){
        sdl2::texte conso("Production excellente", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        conso.at(800, 200);
        fenetre << conso;
    }
    else{
        sdl2::texte conso("Production hors norme !", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
        conso.at(800, 200);
        fenetre << conso;
    }


    sdl2::event_queue queue;
    fenetre << Bilan << Etat_centrale << nbpoint << titre_MW<< sdl2::flush;
    auto events = queue.pull_events();

    SDL_Delay(3000);
}

