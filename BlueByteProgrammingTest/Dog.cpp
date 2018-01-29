#include "Dog.h"


void Dog::Tick() {
    switch (myState) {
    case PLAYING:
        myEnergy -= 2 * myEnergyConsumption;
        break;
    case EATING:
        myEnergy += ENERGY_FOOD_GAIN;
        break;
    case IDLE:
        myEnergy -= myEnergyConsumption;
        break;
    }
}
void Dog::Eat() {
    if (myState != State::EATING) {
        std::cout << myName.c_str() << " started eating" << " (energy=" << myEnergy << ")" << std::endl;
    }
    myState = State::EATING;
}
void Dog::Play() {
    if (myState != State::PLAYING) {
        std::cout << myName.c_str() << " started playing" << " (energy=" << myEnergy << ")" << std::endl;
    }
    myState = State::PLAYING;
}
void Dog::Idle() {
    if (myState != State::IDLE) {
        std::cout << myName.c_str() << " started to idle" << " (energy=" << myEnergy << ")" << std::endl;
    }
    myState = State::IDLE;
}

bool Dog::IsHungry() const {
    return myEnergy <= myHungryThreshold;
}