#pragma once
#include "BT/Condition.h"
#include "BT/Blackboard.h"
#include "Dog.h"


class IsDogBoredCondition : public Condition {
public:
    bool CheckCondition(Entity* e, Blackboard* b) override;

private:
    const std::string BBKEY_ISBORED = "isBored";
};
