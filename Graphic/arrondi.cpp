#include "Graphic_Fonction.hpp"

std::string arrondi(double x, int i) {
    int puissance=pow(10,i);
    double arr = std::round(x*puissance)/puissance;
    std::string modif = std::to_string(arr);
    std::string nouveau;
    int point = modif.find(".");
    for (int j=0; j<= i+point; j++) {
        nouveau += modif[j];
    }
    if (i==0) nouveau.pop_back();
    return nouveau;
}