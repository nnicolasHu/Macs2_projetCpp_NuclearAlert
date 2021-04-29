#include<iostream>
#include"Graphic_Fonction.hpp"
#include"SDL2/sdl2.hpp"

int main(int argc, char* args[]){
    sdl2::init(argc, args);
    int level = 1;
    Controle_win(level);
    sdl2::finalize();
    return 0;
}