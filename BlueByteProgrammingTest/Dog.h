#pragma once
#include "Entity.h"
#include <iostream>

using namespace std;

/* 
 * 
 * Note: First I wanted to implement a variable myBoredom here, but decided to store it in the blackboard since it is purely controlling behavior 
 * and I wanted to use the blackboard for something.
 */
class Dog : public Entity {
public:
    Dog(std::string name) : myName(name) {};
    enum State {
        EATING, PLAYING, IDLE
    };

    bool IsHungry() const { return myEnergy <= HUNGRY_THRESHOLD; }
    bool IsPlaying() const { return myState == State::PLAYING; }
    bool IsEating() const { return myState == State::EATING; }
    bool IsIdle() const { return myState == State::IDLE; }

    void Tick() override;
    void Eat();
    void Play();
    void Idle();
private:
    const float ENERGY_CONSUMPTION = 1.f;
    const float ENERGY_FOOD_GAIN = 2.f;
    const int EATING_TICKS = 5;
    const int PLAYING_TICKS = 5;
    const float HUNGRY_THRESHOLD = 5.f;

    State myState = State::IDLE;
    float myEnergy;
    std::string myName;

    int eatTime = 0;
    int playTime = 0;
};
