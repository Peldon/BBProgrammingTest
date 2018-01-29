#pragma once

#include "Action.h"
#include "Dog.h"

class DogEatAction : public Action {

public:
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            ExecuteDogAction(dog, b);
        }
        return Status::FAILURE;
    }
private:
    const std::string BBKEY_ACTIONTIME = "actionTime";
    const std::string BBKEY_CURRENTACTION = "currentAction";
};