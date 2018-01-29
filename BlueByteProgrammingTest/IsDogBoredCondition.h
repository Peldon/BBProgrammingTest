#pragma once
#include "Condition.h"
#include "Dog.h"
#include "Blackboard.h"

class IsDogBoredCondition :
    public Condition {
public:
    bool CheckCondition(Entity* e, Blackboard* b) override {
        return b->GetBool(blackboardKey);
    };

private:
    const std::string blackboardKey = "isBored";
};
