#pragma once

#include "Action.h"
#include "Dog.h"

class DogPlayAction : public Action {

public:
    Status Execute(Entity* e, Blackboard* b) {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {

            if (b->GetString(BBKEY_CURRENTACTION) != ACTIONNAME) {
                b->SetString(BBKEY_CURRENTACTION, ACTIONNAME);
                b->SetInt(BBKEY_ACTIONTIME, 0);
            }
            dog->Play();
            b->SetBool(BBKEY_ISBORED, false);
            int playTime = b->GetInt(BBKEY_ACTIONTIME);
            playTime++;
            if (playTime >= ACTIONDURATION) {
                b->SetInt(BBKEY_ACTIONTIME, 0);
                return Status::SUCCESS;
            } else {
                b->SetInt(BBKEY_ACTIONTIME, playTime);
                return Status::RUNNING;
            }
        }
        return Status::FAILURE;
    }
private:
    const std::string ACTIONNAME = "play";
    const int ACTIONDURATION = 50;
    const std::string BBKEY_ACTIONTIME = "actionTime";
    const std::string BBKEY_CURRENTACTION = "currentAction";
    const std::string BBKEY_ISBORED = "isBored";
};