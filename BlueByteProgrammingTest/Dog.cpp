#include "Dog.h"


void Dog::Tick() {
    switch (myState) {
    case PLAYING:
        myEnergy -= 2 * energyConsumption;
        break;
    case EATING:
        myEnergy += ENERGY_FOOD_GAIN;
        break;
    case IDLE:
        myEnergy -= energyConsumption;
        break;
    }
}
void Dog::Eat() {
    if (myState != State::EATING) {
        cout << myName.c_str() << " started eating" << " (energy=" << myEnergy << ")" << endl;
    }
    myState = State::EATING;
}
void Dog::Play() {
    if (myState != State::PLAYING) {
        cout << myName.c_str() << " started playing" << " (energy=" << myEnergy << ")" << endl;
    }
    myState = State::PLAYING;
}
void Dog::Idle() {
    if (myState != State::IDLE) {
        cout << myName.c_str() << " started idle" << " (energy=" << myEnergy << ")" << endl;
    }
    myState = State::IDLE;
}

bool Dog::IsHungry() const {
    return myEnergy <= hungryThreshold;
}