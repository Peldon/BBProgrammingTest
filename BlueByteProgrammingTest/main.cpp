#include <iostream>
#include "DogSimulation.h"

/* 
 The class DogSimulation instantiates five dogs, builds a behavior tree (BT) and simulates endlessly
 The used BT does not use a Repeater nor a Inverter, but provides classes for this. All generic BT classes can be found in the subdirectory "BT"
 I am still not sure if I should have used them and if the given picture was already a part of a solution I could not see.
 So maybe I missed something, but the BT works as specified in the task: Dogs play when bored as long as they are not hungry. Boredom is increased when idling
 and only reset by playing. I assumed that "exhausted" was meant as a synonym for being low on energy and "rest and recover" as a synonym for idle and eating.
   */
int main() {
    std::cout << "Blue Byte Programming Test" << std::endl;
    std::cout << "Gerald Schenke 29.01.2018" << std::endl;

    DogSimulation dogSim;
    dogSim.Run();

    std::cout << "Goodbye" << std::endl;
    return 0;
}

