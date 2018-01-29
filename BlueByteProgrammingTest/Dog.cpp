#include "Dog.h"


void Dog::Tick() {
    switch (myState) {
    case PLAYING:
        myEnergy -= 2 * ENERGY_CONSUMPTION;
        playTime++;
        if (playTime > MAX_PLAY_TICKS) {
            Idle();
        }
        break;
    case EATING:
        myEnergy += ENERGY_FOOD_GAIN;
        eatTime++;
        if (eatTime > MAX_EAT_TICKS) {
            Idle();
        }
        break;
    case IDLE:
        myEnergy -= ENERGY_CONSUMPTION;
        idleTime++;
        break;
    }
}
void Dog::Eat() {
    if (myState == State::EATING) {
        return;
    }
    cout << myName.c_str() << " started eating" << endl;
    myState = State::EATING;
    eatTime = 0;
}
void Dog::Play() {
    if (myState == State::PLAYING) {
        return;
    }
    cout << myName.c_str() << " started playing" << endl;
    myState = State::PLAYING;
    playTime = 0;
}
void Dog::Idle() {
    if (myState == State::IDLE) {
        return;
    }
    cout << myName.c_str() << " started resting" << endl;
    myState = State::IDLE;
    idleTime = 0;
}