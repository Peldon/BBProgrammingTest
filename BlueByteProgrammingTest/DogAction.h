#pragma once

#include "Action.h"
#include "Dog.h"

class DogAction : public Action {

public:
    DogAction(std::string actionName, int actionDuration) : actionName(actionName), actionDuration(actionDuration) {};
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            if (b->GetString(BBKEY_CURRENTACTION) != actionName) {
                b->SetString(BBKEY_CURRENTACTION, actionName);
                b->SetInt(BBKEY_ACTIONTIME, 0);
            }
            return ExecuteDogAction(dog, b);
        }
        return Status::FAILURE;
    }

    virtual Status ExecuteDogAction(Dog* dog, Blackboard* b) = 0;

protected:
    const std::string actionName;
    const int actionDuration;
    const std::string BBKEY_ACTIONTIME = "DogActionTime";
    const std::string BBKEY_CURRENTACTION = "DogActionType";
};