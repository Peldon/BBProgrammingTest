#pragma once

#include "DogAction.h"

class DogIdleAction : public DogAction {

public:
    DogIdleAction() : DogAction("idle", 0) {}
    Status ExecuteDogAction(Dog* dog, Blackboard* b) override;

private:
    const std::string BBKEY_ISBORED = "isBored";
    const int BOOORING = 10;
};
