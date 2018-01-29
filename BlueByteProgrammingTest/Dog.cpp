#include "Dog.h"


void Dog::Tick() {
    switch (myState) {
    case PLAYING:
        myEnergy -= 2 * ENERGY_CONSUMPTION;
        playTime++;
        if (playTime > EATING_TICKS) {
            myState = State::IDLE;
        }
        break;
    case EATING:
        myEnergy += ENERGY_FOOD_GAIN;
        eatTime++;
        if (eatTime > EATING_TICKS) {
            myState = State::IDLE;
        }
        break;
    case IDLE:
        myEnergy -= ENERGY_CONSUMPTION;
        break;
    }
}
void Dog::Eat() {
    cout << myName.c_str() << " started eating" << endl;
    myState = State::EATING;
    eatTime = 0;
}
void Dog::Play() {
    cout << myName.c_str() << " started playing" << endl;
    myState = State::PLAYING;
    playTime = 0;
}
void Dog::Idle() {
    cout << myName.c_str() << " started resting" << endl;
    myState = State::IDLE;
}