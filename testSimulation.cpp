#include "centrale.hpp"
#include <iostream>

int main() {
    centrale C;
    
    std::cout << C.get_Reacteur().get_TBore_eff() << std::endl;
    return EXIT_SUCCESS;
}