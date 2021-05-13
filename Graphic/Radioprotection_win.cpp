#include "Graphic_Fonction.hpp"

using namespace std;


void Radioprotection_win(sdl2::window& fenêtre,centrale& C){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 14);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 20);
    sdl2::font fonte_help("./Graphic/data/Lato-Thin.ttf", 18);
    
    //sdl2::window fenêtre("Nuclear Alert : Poste de sécurité Radioprotection"s, {800, 600});

        /////////        Titre fenêtre      ////////
    sdl2::texte gdtitre("POSTE DE SECURITE RADIOPROTECTION"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gdtitre.at(470, 53);
    sdl2::texte help("Appuyez sur 'h' pour voir les commandes disponibles", fonte_help, fenêtre, {0xFF, 0xFF, 0xFF, 0xFF});
    help.at(30, 10);

    sdl2::rectangle GD({30,40}, {1190,50}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << GD << gdtitre; 

    /////////       Cadre Activité       /////////
    sdl2::texte titre("Activité"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(360, 98);

    //piscine
    double R_piscine = C.get_Reacteur().get_R_piscine();
    sdl2::texte piscine("Piscine : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    piscine.at(45, 125);
    sdl2::texte af_piscine(to_string(R_piscine), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_piscine.at(600, 125);
    sdl2::texte unitp("bq"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitp.at(700, 125);

    //enceinte
    double R_enceinte = C.get_R_enceinte();
    sdl2::texte enceinte("Enceinte : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    enceinte.at(45, 160);
    sdl2::texte af_enceinte(to_string(R_enceinte), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_enceinte.at(600, 160);
    sdl2::texte unitenc("rem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitenc.at(700, 160);

    //rejets atmo
    double R_air = C.get_R_air();
    sdl2::texte atmo("Rejets atmosphériques : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    atmo.at(45, 195);
    sdl2::texte af_air(to_string(R_air), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_air.at(600, 195);
    sdl2::texte unitatmo("mrem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitatmo.at(700, 195);

    //rejets eau
    double R_eau = C.get_R_eau();
    sdl2::texte eau("Rejets aqueux : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    eau.at(45, 230);
    sdl2::texte af_eau(to_string(R_eau), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_eau.at(600, 230);
    sdl2::texte uniteau("mrem/h"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    uniteau.at(700, 230);

    sdl2::rectangle Activité({30,95}, {750,180}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Activité << titre << piscine << af_piscine << unitp << enceinte << af_enceinte << unitenc << atmo << af_air << unitatmo << eau << af_eau << uniteau;

    /////////     Cadre Effectif     ////////
    sdl2::texte titreeff("Effectif"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreeff.at(960, 95);
    //total
    int dispo = C.get_Ouvriers().get_nb_disponible();
    sdl2::texte disp("disp. : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    disp.at(805, 120);
    sdl2::texte af_nb(to_string(dispo), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_nb.at(1170, 120);
    //occup
    int occ = C.get_Ouvriers().get_nb_ouvriersEnIntervention_tot();
    sdl2::texte occup("occup. : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    occup.at(805, 140);
    sdl2::texte af_occ(to_string(occ), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_occ.at(1170, 140);
    //blessés
    int blesses = C.get_Ouvriers().get_nb_blesses();
    sdl2::texte bles("bles. : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bles.at(805, 160);
    sdl2::texte af_bles(to_string(blesses), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_bles.at(1170, 160);
    
    sdl2::rectangle Effectif({790,95}, {430,120}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Effectif << titreeff << disp << af_nb << occup << af_occ << bles << af_bles;

    ////////       Cadre Reacteur     ////////
    sdl2::texte titrereac("Reacteur"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrereac.at(200, 290);

    //Etat canaux
    int E_canaux = (C.get_Reacteur().get_E_canaux())*100;
    sdl2::texte canaux("Etat canaux : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    canaux.at(45, 340);
    sdl2::texte af_canaux(to_string(E_canaux),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_canaux.at(360, 340);

    //Etat graphite
    int E_graphite = (C.get_Reacteur().get_E_barre())*100;
    sdl2::texte graph("Etat barre graphite : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    graph.at(45, 375);
    sdl2::texte af_graph(to_string(E_graphite),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_graph.at(360, 375);

    //Etat piscine
    int E_piscine = (C.get_Reacteur().get_E_piscine())*100;
    sdl2::texte e_piscine("Etat piscine : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_piscine.at(45, 410);
    sdl2::texte af_pisc(to_string(E_piscine),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_pisc.at(360, 410);

    //Etat cuve
     int E_cuve = (C.get_Reacteur().get_E_cuve())*100;
    sdl2::texte cuve("Etat cuve : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cuve.at(45, 445);
    sdl2::texte af_cuve(to_string(E_cuve),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_cuve.at(360, 445);

    //Etat injecteur borique 
    int E_bore = (C.get_Reacteur().get_E_bore())*100;
    sdl2::texte bor("Etat injecteur borique : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bor.at(45, 480);
    sdl2::texte af_bore(to_string(E_bore),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_bore.at(360, 480);

    sdl2::rectangle Reacteur({30,285}, {375,220}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Reacteur << titrereac << canaux << af_canaux << graph << af_graph << e_piscine << af_pisc << cuve << af_cuve << bor << af_bore;

    ////////       Cadre Circuit Primaire     ////////
    sdl2::texte titrecp("Circuit Primaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecp.at(545, 290);
    //Etat circuit primaire
    int E_cp = (C.get_Circuit_Primaire().get_E_circuit())*100;
    sdl2::texte e_cp("Etat circuit primaire : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_cp.at(430, 340);
    sdl2::texte af_ecp(to_string(E_cp),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_ecp.at(730, 340);

    //Etat pompe
    int E_pmp = (C.get_Circuit_Primaire().get_E_pompe())*100;
    sdl2::texte pompe("Etat pompe : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe.at(430, 375);
    sdl2::texte af_epmp(to_string(E_pmp),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_epmp.at(730, 375);

    //Etat pressuriseur
    int E_press = (C.get_Circuit_Primaire().get_E_pressuriseur())*100;
    sdl2::texte pres("Etat pressuriseur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pres.at(430, 410);
    sdl2::texte af_epress(to_string(E_press),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_epress.at(730, 410);

    //Etat res
    int E_res = (C.get_Circuit_Primaire().get_E_resistance())*100;
    sdl2::texte res("Etat resistance press. : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    res.at(430, 445);
    sdl2::texte af_eres(to_string(E_res),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_eres.at(730, 445);

    sdl2::rectangle CircuitP({415,285}, {365,220}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << CircuitP << titrecp << e_cp << af_ecp << pompe << af_epmp << pres << af_epress << res << af_eres;

    ////////       Cadre Circuit Secondaire     ////////
    sdl2::texte titrecs("Circuit Secondaire"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecs.at(950, 230);
    //Etat circuit secondaire
    int E_cs = (C.get_Circuit_Secondaire().get_E_circuit())*100;
    sdl2::texte e_cs("Etat circuit secondaire : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_cs.at(805, 280);
    sdl2::texte af_ecs(to_string(E_cs),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_ecs.at(1170, 280);

    //Etat pompe
    int E_pmp2 = (C.get_Circuit_Secondaire().get_E_pompe())*100;
    sdl2::texte pompe2("Etat pompe : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe2.at(805, 315);
    sdl2::texte af_pmp2(to_string(E_pmp2),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_pmp2.at(1170, 315);

    //Etat pressuriseur
    int E_gen = (C.get_Circuit_Secondaire().get_E_vapeur())*100;
    sdl2::texte gen("Etat générateur de vapeur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gen.at(805, 350);
    sdl2::texte af_egen(to_string(E_gen),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_egen.at(1170, 350);

    //Etat ech
    int E_ech = (C.get_Circuit_Primaire().get_E_echangeur())*100;
    sdl2::texte ech("Etat échangeur de chaleur : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ech.at(805, 385);
    sdl2::texte af_ech(to_string(E_ech),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_ech.at(1170, 385);

    sdl2::rectangle CircuitS({790,225}, {430,205}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << CircuitS << titrecs << e_cs << af_ecs << pompe2 << af_pmp2 << gen << af_egen << ech << af_ech;

    ////////       Cadre Confinement     ////////
    sdl2::texte titreec("Enceinte de confinement"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreec.at(60, 525);
    //Etat enceinte
    int E_enceinte = (C.get_E_enceinte())*100;
    sdl2::texte econf("Etat enceinte confinement : "s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    econf.at(45, 575);
    sdl2::texte af_eenc(to_string(E_enceinte),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_eenc.at(360, 575);

    sdl2::rectangle Conf({30,515}, {375,120}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Conf << titreec << econf << af_eenc;

    ////////       Cadre Condenseur     ////////
    sdl2::texte titrecond("Condenseur"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecond.at(525, 525);
    //Etat cond
    int E_cond = (C.get_Circuit_Secondaire().get_E_condenseur())*100;
    sdl2::texte econd("Etat condensateur :"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    econd.at(430, 575);
    sdl2::texte af_econd(to_string(E_cond),fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_econd.at(730, 575);
    

    sdl2::rectangle Cond({415,515}, {365,120}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << Cond << titrecond << econd << af_econd;

    ////////       Cadre Ordinateur     ////////
    sdl2::texte titreord("Ordinateur"s, fonte_titre, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreord.at(950, 455);
    //Etat centrale
    int E_centrale = (C.get_E_centrale())*100;
    sdl2::texte e_centrale("Etat général centrale :"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_centrale.at(805, 500);
    sdl2::texte af_ecentrale(to_string(E_centrale), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_ecentrale.at(1170, 500);
    //Niveau d'alerte
    sdl2::texte alerte("Niveau d'alerte :"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    alerte.at(805, 530);
    //Population évacuée
    int Evac = (C.get_Evac())*100;
    sdl2::texte popevac("Population évacuée :"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    popevac.at(805, 560);
    sdl2::texte af_evac(to_string(Evac), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_evac.at(1170, 560);
    //Population contaminée
    unsigned int Contamination = (C.get_Contamination());
    sdl2::texte popcont("Contamination :"s, fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    popcont.at(805, 590);
    sdl2::texte af_cont(to_string(Contamination), fonte_texte, fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_cont.at(1170, 590);

    sdl2::rectangle ord({790,440}, {430,195}, {0xFF,0xFF,0xFF,0xFF}, false);
    fenêtre << ord << titreord << e_centrale << af_ecentrale << alerte << popevac << af_evac << popcont << af_cont;


    bool quitting = false;
    sdl2::event_queue queue;

        fenêtre << help << sdl2::flush;
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

    SDL_Delay(5000);
}

