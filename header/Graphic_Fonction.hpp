#ifndef _GRAPHIC_FONCTION_HPP_
#define _GRAPHIC_FONCTION_HPP_
#include<string>
#include"sdl2.hpp"

std::string Fenetre_acceuil();
int Choix_Niveau();
void Centrale_tab();
void Controle_win(int level);
void Commande(sdl2::window fenêtre);
void Niveau1();
#endif

