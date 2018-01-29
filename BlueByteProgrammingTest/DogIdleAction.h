#pragma once

#include "Action.h"
#include "Dog.h"

class DogIdleAction : public Action {
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            /*if (dog->IsIdle()) {
            return Status::RUNNING;
            } else {
            dog->Idle();
            }
            */
            // TODO implement
            //b->GetBool
            return Status::SUCCESS;
        }
        return Status::FAILURE;

    }


};