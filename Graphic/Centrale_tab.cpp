#include "Graphic_Fonction.hpp"
#include<array>

void Centrale_tab(sdl2::window& fenetre, centrale& C, int clignotement){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    sdl2::font fonte_test("./Graphic/data/Lato-Black.ttf", 17);
    // Créer une fenetre avec un titre et la résolution de la fenetre (ici 800 x 600 pixels )
    //sdl2::window fenetre("Nuclear Alert : Schéma de la centrale", {800, 600});
    fenetre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::image centrale("Graphic/data/sch├®ma_centrale.png", fenetre);
    centrale.at(120, 100);
    centrale.stretch({1100, 500});

    // sdl2::image cuve("./Graphic/data/Cuve.png", fenetre);
    // cuve.at(200, 100);
    sdl2::texte circuit_prim("Circuit primaire"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_prim.at(130, 550);
    sdl2::texte circuit_sec("Circuit secondaire"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_sec.at(390, 550);
    sdl2::texte circuit_refroid("Circuit de refroidissement"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_refroid.at(700, 550);
    sdl2::texte vapeur("Vapeur d'eau"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    vapeur.at(910, 180);

    fenetre <<  centrale  << circuit_prim << circuit_sec << circuit_refroid << vapeur ;
    if(clignotement == 0) fenetre << sdl2::flush;
    else{
        //Condenseur en rouge
        sdl2::texte condenseurR("Condenseur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        condenseurR.at(672, 384);
        fenetre << condenseurR;

        //Circuit secondaire en rouge
        sdl2::texte circuit_secR("Circuit secondaire"s, fonte_texte, fenetre, {0xFF, 0, 0, 0xFF});
        circuit_secR.at(390, 550);
        fenetre << circuit_secR;

        //Circuit primaire en rouge
        sdl2::texte circuit_primR("Circuit primaire"s, fonte_texte, fenetre, {0xFF, 0, 0, 0xFF});
        circuit_primR.at(130, 550);
        fenetre << circuit_primR;

        //Pompe en rouge 
        sdl2::texte pompe("Pompe", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        pompe.at(320, 428);
        fenetre << pompe;

        //Pressuriseur rouge 
        sdl2::texte pressuriseur("Pressuriseur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        pressuriseur.at(230, 282);
        fenetre << pressuriseur;

        //Cuve rouge
        sdl2::texte cuve("Cuve  du", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        cuve.at(223, 317);
        sdl2::texte cuve1("reacteur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        cuve1.at(224, 334);
        fenetre << cuve << cuve1;

        //Générateur de vapeur
        sdl2::texte gen("Générateur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        gen.at(322, 228);
        sdl2::texte gen1("de  vapeur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        gen1.at(326, 243);
        fenetre << gen << gen1;

        fenetre << sdl2::flush;
    }
    
    
}
