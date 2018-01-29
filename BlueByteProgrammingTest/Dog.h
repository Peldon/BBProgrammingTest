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
    Dog(std::string name, float energyConsumption, float hungryThreshold) : myName(name), energyConsumption(energyConsumption), hungryThreshold(hungryThreshold) {};
    enum State {
        EATING, PLAYING, IDLE
    };

    bool IsHungry() const;

    void Tick() override;
    void Eat();
    void Play();
    void Idle();
private:
    float energyConsumption = 5;
    float hungryThreshold = 5;
    const float ENERGY_FOOD_GAIN = 20.f;

    State myState = State::IDLE;
    float myEnergy = 50.f;
    std::string myName;
};
