#include "RND.hpp"

/** RND pour un int en entrée **/
int RND(int borne_sup){
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_int_distribution<int> igenran(0, borne_sup);
    return (igenran(hgenerator));
}

/** RND pour un double en entrée **/
double RND(double borne_sup){
    std::random_device hgenerator;
    std::default_random_engine generator(hgenerator());
    std::uniform_real_distribution<double> genrand(0.,borne_sup);
    return (genrand(hgenerator));
}
