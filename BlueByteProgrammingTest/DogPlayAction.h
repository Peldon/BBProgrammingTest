#pragma once

#include "DogAction.h"

class DogPlayAction : public DogAction {

public:
    DogPlayAction() : DogAction("play", 100) {}

    Status ExecuteDogAction(Dog* dog, Blackboard* b) override;
private:
    const std::string BBKEY_ISBORED = "isBored";
};
