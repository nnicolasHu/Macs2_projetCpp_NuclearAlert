#include<iostream>
#include"sdl2.hpp"
#include<SDL2/SDL_ttf.h>
#include "Graphic_Fonction.hpp"
#include <string>

using namespace std;

void Radioprotection_win(sdl2::window* fenêtre,centrale* C){
    sdl2::font fonte_texte("./Graphic/data/Lato-Thin.ttf", 18);
    sdl2::font fonte_titre("./Graphic/data/Lato-Bold.ttf", 28);
    
    unsigned short a = 200;
    //sdl2::window fenêtre("Nuclear Alert : Poste de sécurité Radioprotection"s, {800, 600});

        /////////        Titre fenêtre      ////////
    sdl2::texte gdtitre("POSTE DE SECURITE RADIOPROTECTION"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gdtitre.at(450, 13);

    sdl2::rectangle GD({30,10}, {1340,50}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << GD << gdtitre; 

    /////////       Cadre Activité       /////////
    sdl2::texte titre("Activité"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titre.at(460, 65);

    //piscine
    double R_piscine = C->get_Reacteur()->get_R_piscine();
    //string R_p = to_string(R_piscine);
    sdl2::texte piscine("Piscine : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    piscine.at(45, 115);
    sdl2::texte af_piscine(to_string(R_piscine), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_piscine.at(800, 115);
    sdl2::texte unitp("bq"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitp.at(700+a, 115);

    //enceinte
    double R_enceinte = C->get_R_enceinte();
    sdl2::texte enceinte("Enceinte : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    enceinte.at(45, 150);
    sdl2::texte af_enceinte(to_string(R_enceinte), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_enceinte.at(800, 150);
    sdl2::texte unitenc("rem/h"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitenc.at(700+a, 150);

    //rejets atmo
    double R_air = C->get_R_air();
    sdl2::texte atmo("Rejets atmosphériques : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    atmo.at(45, 185);
    sdl2::texte af_air(to_string(R_air), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_air.at(800, 185);
    sdl2::texte unitatmo("mrem/h"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    unitatmo.at(700+a, 185);

    //rejets eau
    double R_eau = C->get_R_eau();
    sdl2::texte eau("Rejets aqueux : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    eau.at(45, 220);
    sdl2::texte af_eau(to_string(R_eau), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_eau.at(800, 220);
    sdl2::texte uniteau("mrem/h"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    uniteau.at(700+a, 220);

    sdl2::rectangle Activité({30,65}, {950,200}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << Activité << titre << piscine << af_piscine << unitp << enceinte << af_enceinte << unitenc << atmo << af_air << unitatmo << eau << af_eau << uniteau;

    /////////     Cadre Effectif     ////////
    sdl2::texte titreeff("Effectif"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreeff.at(930+a, 65);
    //total
    int dispo = C->get_Ouvriers()->get_nb_disponible();
    sdl2::texte disp("disp. : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    disp.at(805+a, 115);
    sdl2::texte af_nb(to_string(dispo), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_nb.at(805+a+300, 115);
    
    //occup
    int occ = 0;
    for(int i=0; i<=7; i++){
        occ += C->get_Ouvriers()->get_nb_ouvriersEnIntervention(i);
    };
    
    sdl2::texte occup("occup. : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    occup.at(805+a, 150);
    sdl2::texte af_occ(to_string(occ), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_occ.at(805+a+300, 150);
    
    //blessés
    int blesses = C->get_Ouvriers()->get_nb_blesses();
    sdl2::texte bles("bles. : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bles.at(805+a, 185);
    sdl2::texte af_bles(to_string(blesses), fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    af_bles.at(805+a+300, 185);
    
    sdl2::rectangle Effectif({990,65}, {380,200}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << Effectif << titreeff << disp << af_nb << occup << af_occ << bles << af_bles;

    ////////       Cadre Reacteur     ////////
    sdl2::texte titrereac("Reacteur"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrereac.at(200, 280);

    //Etat canaux
    int E_canaux = (C->get_Reacteur()->get_E_canaux())*100;
    sdl2::texte canaux("Etat canaux : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    canaux.at(45, 330);
    sdl2::texte e_canaux(to_string(E_canaux),fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_canaux.at(460, 330);

    //Etat graphite
    sdl2::texte graph("Etat barre graphite : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    graph.at(45, 365);
    //Etat graphite
    sdl2::texte e_piscine("Etat piscine : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_piscine.at(45, 400);
    //Etat cuve
    sdl2::texte cuve("Etat cuve : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    cuve.at(45, 435);
    //Etat injecteur borique */
    sdl2::texte bor("Etat injecteur borique : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    bor.at(45, 470);


    sdl2::rectangle Reacteur({30,275}, {475,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << Reacteur << titrereac << canaux << e_canaux << graph << e_piscine << cuve << bor;

    ////////       Cadre Circuit Primaire     ////////
    sdl2::texte titrecp("Circuit Primaire"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecp.at(645, 280);
    //Etat circuit primaire
    sdl2::texte e_cp("Etat circuit primaire : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_cp.at(530, 330);
    //Etat pompe
    sdl2::texte pompe("Etat pompe : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe.at(530, 365);
    //Etat pressuriseur
    sdl2::texte pres("Etat pressuriseur : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pres.at(530, 400);
    //Etat res
    sdl2::texte res("Etat resistance press. : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    res.at(530, 435);

    sdl2::rectangle CircuitP({515,275}, {465,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << CircuitP << titrecp << e_cp << pompe << pres << res;

    ////////       Cadre Circuit Secondaire     ////////
    sdl2::texte titrecs("Circuit Secondaire"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecs.at(870+a, 280);
    //Etat circuit primaire
    sdl2::texte e_cs("Etat circuit secondaire : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_cs.at(805+a, 330);
    //Etat pompe
    sdl2::texte pompe2("Etat pompe : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    pompe2.at(805+a, 365);
    //Etat pressuriseur
    sdl2::texte gen("Etat générateur de vapeur : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    gen.at(805+a, 400);
    //Etat res
    sdl2::texte ech("Etat réchangeur de vapeur : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    ech.at(805+a, 435);

    sdl2::rectangle CircuitS({990,275}, {380,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << CircuitS << titrecs << e_cs << pompe2 << gen << ech;

    ////////       Cadre Confinement     ////////
    sdl2::texte titreec("Enceinte de confinement"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreec.at(60, 545);
    //Etat enceinte
    sdl2::texte econf("Etat enceinte confinement : "s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    econf.at(45, 595);

    sdl2::rectangle Conf({30,535}, {375,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << Conf << titreec << econf;

    ////////       Cadre Condenseur     ////////
    sdl2::texte titrecond("Condenseur"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titrecond.at(525, 545);
    //Etat cond
    sdl2::texte econd("Etat condensateur :"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    econd.at(430, 595);
    

    sdl2::rectangle Cond({415,535}, {365,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << Cond << titrecond << econd;

    ////////       Cadre Ordinateur     ////////
    sdl2::texte titreord("Ordinateur"s, fonte_titre, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    titreord.at(910, 545);
    //Etat centrale
    sdl2::texte e_centrale("Etat général centrale :"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    e_centrale.at(805, 595);
    //Niveau d'alerte
    sdl2::texte alerte("Niveau d'alerte :"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    alerte.at(805, 630);
    //Population évacuée
    sdl2::texte popevac("Population évacuée :"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    popevac.at(805, 665);
    //Population contaminée
    sdl2::texte popcont("Population contaminée :"s, fonte_texte, *fenêtre, {0xAD, 0xFF, 0x2F, 0});
    popcont.at(805, 700);

    sdl2::rectangle ord({790,535}, {380,250}, {0xFF,0xFF,0xFF,0xFF}, false);
    *fenêtre << ord << titreord << e_centrale << alerte << popevac << popcont;


    bool quitting = false;
    sdl2::event_queue queue;

        *fenêtre << sdl2::flush;
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

