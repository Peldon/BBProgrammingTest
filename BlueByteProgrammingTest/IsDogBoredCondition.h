#pragma once
#include "Condition.h"
#include "Dog.h"
#include "Blackboard.h"

class IsDogBoredCondition : public Condition {
public:
    bool CheckCondition(Entity* e, Blackboard* b) override;

private:
    const std::string BBKEY_ISBORED = "isBored";
};
