#pragma once

#include "DogAction.h"

class DogPlayAction : public DogAction {

public:
    DogPlayAction() : DogAction("play", 100) {}

    Status ExecuteDogAction(Dog* dog, Blackboard* b) override {
        dog->Play();
        b->SetBool(BBKEY_ISBORED, false);
        int playTime = b->GetInt(BBKEY_ACTIONTIME);
        playTime++;
        if (playTime >= actionDuration) {
            b->SetInt(BBKEY_ACTIONTIME, 0);
            return Status::SUCCESS;
        } else {
            b->SetInt(BBKEY_ACTIONTIME, playTime);
            return Status::RUNNING;
        }
    }
private:
    const std::string BBKEY_ISBORED = "isBored";
};