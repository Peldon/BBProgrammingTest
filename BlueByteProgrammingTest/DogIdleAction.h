#pragma once

#include "Action.h"
#include "Dog.h"

class DogIdleAction : public Action {

public:
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {

            if (b->GetString(BBKEY_CURRENTACTION) != ACTIONNAME) {
                b->SetString(BBKEY_CURRENTACTION, ACTIONNAME);
                b->SetInt(BBKEY_ACTIONTIME, 0);
            }
            dog->Idle();
            int idleTime = b->GetInt(BBKEY_ACTIONTIME);
            idleTime++;
            if (idleTime >= BOOORING) {
                b->SetBool(BBKEY_ISBORED, true);
            }
            b->SetInt(BBKEY_ACTIONTIME, idleTime);
            return Status::RUNNING;
        }
        return Status::FAILURE;
    }
private:
    const std::string ACTIONNAME = "idle";
    const std::string BBKEY_ACTIONTIME = "actionTime";
    const std::string BBKEY_CURRENTACTION = "currentAction";
    const std::string BBKEY_ISBORED = "isBored";
    const int BOOORING = 10;
};