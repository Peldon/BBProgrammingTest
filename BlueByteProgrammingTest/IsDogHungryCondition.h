#pragma once
#include "BT/Condition.h"
#include "Dog.h"

class IsDogHungryCondition : public Condition {
public:
    bool CheckCondition(Entity* e, Blackboard* b) override;
};

