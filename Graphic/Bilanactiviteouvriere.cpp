#include "Graphic_Fonction.hpp"

using namespace std;

void Bilanactiviteouvriere(sdl2::window& fenêtre,centrale& C){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 14);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 20);

    fenêtre << sdl2::rectangle({0, 0}, {1250, 650}, {0, 0, 0, 0}, true);

        /////////        Titre fenêtre      ////////
    sdl2::texte gdtitre("BILAN ACTIVITE OUVIERE"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gdtitre.at(495, 53);

    sdl2::rectangle GD({30,40}, {1190,50}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << GD << gdtitre; 

    /// Organes ///
    sdl2::texte organes("Organe"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    organes.at(290, 120);

    sdl2::texte pompe_cp(" - Pompe circuit primaire"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe_cp.at(45, 170);

    sdl2::texte pompe_cs(" - Pompe circuit secondaire"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe_cs.at(45, 205);

    sdl2::texte cond(" - Condenseur"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cond.at(45, 240);

    sdl2::texte gen_vap(" - Générateur de vapeur"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gen_vap.at(45, 275);

    sdl2::texte inject(" - Injecteur borique"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    inject.at(45, 310);

    sdl2::texte cp(" - Circuit primaire"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cp.at(45, 345);

    sdl2::texte cs(" - Circuit secondaire"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cs.at(45, 380);

    sdl2::texte press(" - Pressuriseur"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    press.at(45, 415);

    sdl2::rectangle organes_cadre({30,95}, {590,540}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << organes_cadre << organes << pompe_cp << pompe_cs << cond << gen_vap << inject << cp << cs << press; 

    /// Statut réparartion ///
    sdl2::texte statut("Statut réparation"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    statut.at(740, 120);

    string rpcp = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=8) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(0) == 0)){
        rpcp = "POS";
    }
    sdl2::texte rep_pompe_cp(rpcp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_pompe_cp.at(795, 170);

    string rpcs = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=8) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(1) == 0)){
        rpcs = "POS";
    }
    sdl2::texte rep_pompe_cs(rpcs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_pompe_cs.at(795, 205);

    string rcond = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=20) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(2) == 0)){
        rcond = "POS";
    }
    sdl2::texte rep_cond(rcond, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_cond.at(795, 240);

    string rgenvap = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=60) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(3) == 0)){
        rgenvap = "POS";
    }
    sdl2::texte rep_gen_vap(rgenvap, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_gen_vap.at(795, 275);

    string rinj = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=5) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(4) == 0)){
        rinj = "POS";
    }
    sdl2::texte rep_inject(rinj, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_inject.at(795, 310);

    string rcp = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=45) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(5) == 0)){
        rcp = "POS";
    }
    sdl2::texte rep_cp(rcp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_cp.at(795, 345);

    string rcs = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=20) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(6) == 0)){
        rcs = "POS";
    }
    sdl2::texte rep_cs(rcs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_cs.at(795, 380);

    string rpress = "IMP";
    if ((C.get_Ouvriers().get_nb_disponible()>=10) && (C.get_Ouvriers().get_nb_ouvriersEnIntervention(7) == 0)){
        rpress = "POS";
    }
    sdl2::texte rep_press(rpress, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    rep_press.at(795, 415);

    sdl2::texte leg1("POS : Réparation possible"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    leg1.at(665, 500);

    sdl2::texte leg2("IMP : Réparation impossible"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    leg2.at(665, 535);

    sdl2::rectangle statut_cadre({630,95}, {360,540}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << statut_cadre << statut << rep_pompe_cp << rep_pompe_cs << rep_cond << rep_gen_vap << rep_inject << rep_cp << rep_cs << rep_press << leg1 << leg2; 

    /// En cours ///
    sdl2::texte en_cours("Ouvrier sur place"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    en_cours.at(1030, 120);

    string cpcp = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(0) != 0)){
        cpcp = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(0));
    }
    sdl2::texte cours_pcp(cpcp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_pcp.at(1105, 170);

    string cpcs = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(1) != 0)){
        cpcs = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(1));
    }
    sdl2::texte cours_pcs(cpcs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_pcs.at(1105, 205);

    string ccond = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(2) != 0)){
        ccond = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(2));
    }
    sdl2::texte cours_cond(ccond, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cond.at(1105, 240);

    string cgvap = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(3) != 0)){
        cgvap = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(3));
    }
    sdl2::texte cours_gen_vap(cgvap, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_gen_vap.at(1105, 275);

    string cinj = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(4) != 0)){
        cinj = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(4));
    }
    sdl2::texte cours_inject(cinj, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_inject.at(1105, 310);

    string ccp = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(5) != 0)){
        ccp = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(5));
    }
    sdl2::texte cours_cp(ccp, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cp.at(1105, 345);

    string ccs = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(6) != 0)){
        ccs = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(6));
    }
    sdl2::texte cours_cs(ccs, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_cs.at(1105, 380);

    string cpress = "0";
    if ((C.get_Ouvriers().get_nb_ouvriersEnIntervention(7) != 0)){
        cpress = to_string(C.get_Ouvriers().get_nb_ouvriersEnIntervention(7));
    }
    sdl2::texte cours_press(cpress, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cours_press.at(1105, 415);

    sdl2::rectangle en_cours_cadre({1000,95}, {220,540}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << en_cours_cadre << en_cours << cours_pcp << cours_pcs << cours_cond << cours_gen_vap << cours_inject << cours_cp << cours_cs << cours_press;


}