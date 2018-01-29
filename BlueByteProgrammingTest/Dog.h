#pragma once
#include "Entity.h"
#include <iostream>

/* The dog class. I kept it as simple as possible to keep the focus on the BT, but still wanted to have a tick method since any real game object would tick as well.
 * I made energy consumption and hungry threshold configurable to have some variety in dogs...
 * Note: First I wanted to implement a variable myBoredom here, but decided to store it in the blackboard since it is purely controlling behavior
 */
class Dog : public Entity {
public:
    Dog(std::string name, float energyConsumption, float hungryThreshold) : myName(name), myEnergyConsumption(energyConsumption), myHungryThreshold(hungryThreshold) {};

    enum State {
        EATING, PLAYING, IDLE
    };

    bool IsHungry() const;

    void Tick();
    void Eat();
    void Play();
    void Idle();
private:
    std::string myName;
    float myEnergyConsumption;
    float myHungryThreshold;
    float myEnergy = 50.f;
    State myState = State::IDLE;

    const float ENERGY_FOOD_GAIN = 20.f;
};
