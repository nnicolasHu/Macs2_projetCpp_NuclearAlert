#ifndef _GRAPHIC_FONCTION_HPP_
#define _GRAPHIC_FONCTION_HPP_
#include<iostream>
#include"centrale.hpp"
#include<string>
#include"sdl2.hpp"

using namespace std::string_literals ;// Indispensable pour utiliser le suffixe s


std::string Fenetre_acceuil(sdl2::window* fenêtre, int* dim_x, int* dim_y);
int Choix_Niveau(sdl2::window* fenêtre);
void Centrale_tab(sdl2::window* fenêtre);
void Controle_win(int level);
void Commande(sdl2::window * fenêtre, int *dim_x, int *dim_y);
void Niveau1(sdl2::window* fenêtre);
void SalleDeControle();
void Radioprotection_win(int level);
#endif

