#include "Graphic_Fonction.hpp"


void Centrale_tab(sdl2::window& fenêtre){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 24);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    sdl2::font fonte_test("./Graphic/data/Lato-Black.ttf", 17);
    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    //sdl2::window fenêtre("Nuclear Alert : Schéma de la centrale", {800, 600});
    fenêtre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

    sdl2::image centrale("Graphic/data/sch├®ma_centrale.png", fenêtre);
    centrale.at(120, 100);
    centrale.stretch({1100, 500});

    // Stan by : on verra comment on va le gerer 
    // sdl2::texte echap("Appuyez sur echap pour revenir à la fenêtre précédente"s, fonte_texte, *fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    // echap.at(200, 500); 

    sdl2::texte circuit_prim("Circuit primaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_prim.at(130, 550);
    sdl2::texte circuit_sec("Circuit secondaire"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_sec.at(390, 550);
    sdl2::texte circuit_refroid("Circuit de refroidissement"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    circuit_refroid.at(700, 550);
    sdl2::texte vapeur("Vapeur d'eau"s, fonte_texte, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    vapeur.at(910, 180);

    fenêtre << centrale << circuit_prim << circuit_sec << circuit_refroid << vapeur ;

    //Condenseur en rouge
    sdl2::texte condenseurR("Condenseur", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    condenseurR.at(672, 384);
    fenêtre << condenseurR;

    //Circuit secondaire en rouge
    sdl2::texte circuit_secR("Circuit secondaire"s, fonte_texte, fenêtre, {0xFF, 0, 0, 0xFF});
    circuit_secR.at(390, 550);
    fenêtre << circuit_secR;

    //Circuit primaire en rouge
    sdl2::texte circuit_primR("Circuit primaire"s, fonte_texte, fenêtre, {0xFF, 0, 0, 0xFF});
    circuit_primR.at(130, 550);
    fenêtre << circuit_primR;

    //Pompe en rouge 
    sdl2::texte pompe("Pompe", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    pompe.at(320, 428);
    fenêtre << pompe;

    //Pressuriseur rouge 
    sdl2::texte pressuriseur("Pressuriseur", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    pressuriseur.at(230, 282);
    fenêtre << pressuriseur;

    //Cuve rouge
    sdl2::texte cuve("Cuve  du", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    cuve.at(223, 317);
    sdl2::texte cuve1("reacteur", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    cuve1.at(224, 334);
    fenêtre << cuve << cuve1;

    //Générateur de vapeur
    sdl2::texte gen("Générateur", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    gen.at(322, 228);
    sdl2::texte gen1("de  vapeur", fonte_test, fenêtre, {0xFF, 0, 0, 0xFF});
    gen1.at(326, 243);
    fenêtre << gen << gen1;

    fenêtre << sdl2::flush;
    
}
