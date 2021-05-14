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

    sdl2::image cuve("./Graphic/data/Cuve.png", fenetre);
    cuve.at(207, 343);
    cuve.stretch({105, 105});

    sdl2::image press("./Graphic/data/Pressuriseur.png", fenetre);
    press.at(278, 292);
    press.stretch({100, 100});

    sdl2::image circ_prim("./Graphic/data/circ_prim.png", fenetre);
    circ_prim.at(170, 335);
    circ_prim.stretch({260, 162});

    sdl2::image circ_sec("./Graphic/data/circ_sec.png", fenetre);
    circ_sec.at(516, 377);
    circ_sec.stretch({168, 73});

    sdl2::image gene_vap("./Graphic/data/Gene_vap.png", fenetre);
    gene_vap.at(316, 260);
    gene_vap.stretch({124, 130});

    sdl2::image condens("./Graphic/data/Condenseur.png", fenetre);
    condens.at(495, 354);
    condens.stretch({217, 93});
    
    sdl2::image echan("./Graphic/data/Echangeur.png", fenetre);
    echan.at(838, 358);
    echan.stretch({253, 100});

    sdl2::image pompe1("./Graphic/data/Pompe1.png", fenetre);
    pompe1.at(326, 428);
    pompe1.stretch({55, 60});

    sdl2::image pompe2("./Graphic/data/Pompe2.png", fenetre);
    pompe2.at(482, 390);
    pompe2.stretch({73, 50});

    sdl2::image enceinte("./Graphic/data/Enceinte.png", fenetre);
    enceinte.at(187, 187);
    enceinte.stretch({241, 300});

    sdl2::texte circuit_prim("Circuit primaire"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_prim.at(130, 550);
    sdl2::texte circuit_sec("Circuit secondaire"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_sec.at(390, 550);
    sdl2::texte circuit_refroid("Circuit de refroidissement"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_refroid.at(700, 550);
    sdl2::texte vapeur("Vapeur d'eau"s, fonte_texte, fenetre, {0xFF, 0xFF, 0xFF, 0xFF});
    vapeur.at(910, 180);

    fenetre <<  centrale << circuit_prim << circuit_sec << circuit_refroid << vapeur ;
    if(clignotement == 0) fenetre << sdl2::flush;
    else{
        //Condenseur en rouge
        sdl2::texte condenseurR("Condenseur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        condenseurR.at(672, 384);
        fenetre << condenseurR << condens;

        //Circuit secondaire en rouge
        sdl2::texte circuit_secR("Circuit secondaire"s, fonte_texte, fenetre, {0xFF, 0, 0, 0xFF});
        circuit_secR.at(390, 550);
        fenetre << circuit_secR << circ_sec;

        //Pompe circuit secondaire
        fenetre << pompe2;

        //Circuit primaire en rouge
        sdl2::texte circuit_primR("Circuit primaire"s, fonte_texte, fenetre, {0xFF, 0, 0, 0xFF});
        circuit_primR.at(130, 550);
        fenetre << circuit_primR << circ_prim;

        //Pompe circuit primaire en rouge 
        sdl2::texte pompe("Pompe", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        pompe.at(320, 428);
        fenetre << pompe << pompe1;

        //Pressuriseur rouge 
        sdl2::texte pressuriseur("Pressuriseur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        pressuriseur.at(230, 282);
        fenetre << pressuriseur;

        //Cuve rouge
        sdl2::texte cuve1("Cuve  du", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        cuve1.at(223, 317);
        sdl2::texte cuve2("reacteur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        cuve2.at(224, 334);
        fenetre << cuve << cuve1 << cuve2;

        //Générateur de vapeur
        sdl2::texte gen("Générateur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        gen.at(322, 228);
        sdl2::texte gen1("de  vapeur", fonte_test, fenetre, {0xFF, 0, 0, 0xFF});
        gen1.at(326, 243);
        fenetre << gen << gen1 << gene_vap;

        //Echangeur
        fenetre << echan;

        //Enceinte 
        fenetre << enceinte;

        fenetre << press<< sdl2::flush;
    }
    
    
}
