#include "IsDogHungryCondition.h"

bool IsDogHungryCondition::CheckCondition(Entity* e, Blackboard* b) {
    Dog* dog = static_cast<Dog*>(e);
    if (dog) {
        return dog->IsHungry();
    }
    return false;
};


