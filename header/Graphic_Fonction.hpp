#ifndef _GRAPHIC_FONCTION_HPP_
#define _GRAPHIC_FONCTION_HPP_
#include<iostream>
#include"centrale.hpp"
#include<string>
#include"sdl2.hpp"

std::string Fenetre_acceuil();
int Choix_Niveau();
void Centrale_tab(sdl2::window* fenêtre);
void Controle_win(int level);
void Commande();
void Niveau1();
void SalleDeControle();
#endif

