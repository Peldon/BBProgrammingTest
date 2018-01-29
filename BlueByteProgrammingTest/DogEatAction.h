#pragma once

#include "DogAction.h"

class DogEatAction : public DogAction {

public:

    DogEatAction() : DogAction("eat", 50) {}

    Status ExecuteDogAction(Dog* dog, Blackboard* b) override {
        dog->Eat();
        int eatTime = b->GetInt(BBKEY_ACTIONTIME);
        eatTime++;
        if (eatTime >= actionDuration) {
            b->SetInt(BBKEY_ACTIONTIME, 0);
            return Status::SUCCESS;
        } else {
            b->SetInt(BBKEY_ACTIONTIME, eatTime);
            return Status::RUNNING;
        }
    }
};