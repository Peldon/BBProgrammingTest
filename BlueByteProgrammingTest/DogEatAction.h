#pragma once

#include "Action.h"
#include "Dog.h"

class DogEatAction : public Action {

public:
    Status Execute(Entity* e, Blackboard* b){
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {

            if (b->GetString(BBKEY_CURRENTACTION) != ACTIONNAME) {
                b->SetString(BBKEY_CURRENTACTION, ACTIONNAME);
                b->SetInt(BBKEY_ACTIONTIME, 0);
            }
            dog->Eat();
            int eatTime = b->GetInt(BBKEY_ACTIONTIME);
            eatTime++;
            if (eatTime >= ACTIONDURATION) {
                b->SetInt(BBKEY_ACTIONTIME, 0);
                return Status::SUCCESS;
            } else {
                b->SetInt(BBKEY_ACTIONTIME, eatTime);
                return Status::RUNNING;
            }
        }
        return Status::FAILURE;
    }
private:
    const std::string ACTIONNAME = "eat";
    const int ACTIONDURATION = 50;
    const std::string BBKEY_ACTIONTIME = "actionTime";
    const std::string BBKEY_CURRENTACTION = "currentAction";
};