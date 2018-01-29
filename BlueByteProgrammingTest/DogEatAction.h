#pragma once

#include "Action.h"
#include "Dog.h"

class DogEatAction : public Action {
    Status Execute(Entity* e, Blackboard* b){
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            /*if (dog->IsEating()) {
                return Status::RUNNING;
            } else {
                dog->Eat();
            }
            */
            // TODO implement
            return Status::SUCCESS;
        }
        return Status::FAILURE;

    }

    
};