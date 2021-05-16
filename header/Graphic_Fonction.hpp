#ifndef _GRAPHIC_FONCTION_HPP_
#define _GRAPHIC_FONCTION_HPP_

#include<iostream>
#include<string>
#include<cmath>

#include"centrale.hpp"

#include"sdl2.hpp"
#include<SDL2/SDL_ttf.h>


using namespace std::string_literals ;// Indispensable pour utiliser le suffixe s

std::string arrondi(double x, int i);

std::string Fenetre_acceuil(sdl2::window& fenêtre);
int Choix_Niveau(sdl2::window& fenêtre);
void Centrale_tab(sdl2::window& fenêtre, centrale& C, bool clignotement);
void Commande1(sdl2::window& fenêtre);
void Commande2(sdl2::window& fenêtre);
void SalleDeControle(sdl2::window& fenêtre, centrale& C);
void Radioprotection_win(sdl2::window& fenêtre, centrale& C);
void InterventionO(sdl2::window& fenêtre, centrale& C);
void Bilanactiviteouvriere(sdl2::window& fenêtre,centrale& C);
void BilanJeu(sdl2::window& fenetre, centrale&C, double prod, std::string& pseudo);
void message_confirmation(sdl2::window& fenêtre, int choix);

#endif

