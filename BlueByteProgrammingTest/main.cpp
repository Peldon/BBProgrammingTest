#include <iostream>
#include "DogSimulation.h"


int main() {
    std::cout << "Blue Byte Programming Test" << std::endl;
    std::cout << "Gerald Schenke 29.01.2018" << std::endl;

    DogSimulation dogSim;
    dogSim.Run();

    std::cout << "Goodbye" << std::endl;
    return 0;
}

