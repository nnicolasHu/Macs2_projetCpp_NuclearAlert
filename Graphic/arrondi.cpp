#include "Graphic_Fonction.hpp"

double arrondi(double x, int i) {
    int puissance = pow(10,i);
    return std::round(x*puissance)/puissance;
}