#pragma once

#include "Action.h"
#include "Dog.h"

class DogPlayAction : public Action {
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            /*if (dog->IsPlaying()) {
            return Status::RUNNING;
            } else {
            dog->Play();
            }
            */
            // TODO implement
            return Status::SUCCESS;
        }
        return Status::FAILURE;

    }


};