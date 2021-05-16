#include"niveaux.hpp"
#include<iostream>

void BilanJeu(sdl2::window& fenetre, centrale&C, double prod){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 20);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 24);

    sdl2::texte Bilan("Bilan", fonte_titre, fenetre, {0xFF, 0, 0, 0xFF});
    Bilan.at(600, 10);

    sdl2::texte Etat_centrale("Etat de la centrale", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    Etat_centrale.at(100, 100);

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

    //Production électrique
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

    double moy_prim = C.get_Circuit_Primaire().get_E_pressuriseur()+C.get_Circuit_Primaire().get_E_resistance()+C.get_Circuit_Primaire().get_E_echangeur()+C.get_Circuit_Primaire().get_E_pompe();
    moy_prim/=4;
    double moy_sec = C.get_Circuit_Secondaire().get_E_pompe()+C.get_Circuit_Secondaire().get_E_condenseur()+C.get_Circuit_Secondaire().get_E_vapeur();
    moy_sec/=3;
    sdl2::texte moy_circprim(std::to_string(moy_prim), fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    moy_circprim.at(800, 300);
    sdl2::texte moy_circsec(std::to_string(moy_sec), fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    moy_circsec.at(800, 400);
    sdl2::texte texte_prim("Etat moyen du circuit primaire : ", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    sdl2::texte texte_sec("Etat moyen du circuit secondaire : ", fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    texte_prim.at(100, 300);
    texte_sec.at(100, 400);

    sdl2::texte remerciements("Merci d'avoir joué ;) Appuyez sur 'Escape' pour quitter le jeu", fonte_titre, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    remerciements.at(300, 550);
    fenetre << remerciements << Bilan << texte_prim << texte_sec<< Etat_centrale << titre_MW << moy_circprim << moy_circsec<< sdl2::flush;
    sdl2::event_queue queue;
    auto events = queue.pull_events();

    SDL_Delay(3000);
}

