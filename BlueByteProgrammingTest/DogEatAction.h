#pragma once

#include "DogAction.h"

class DogEatAction : public DogAction {

public:
    DogEatAction() : DogAction("eat", 50) {}

    Status ExecuteDogAction(Dog* dog, Blackboard* b) override;
};
