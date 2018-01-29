#pragma once

#include "DogAction.h"

class DogIdleAction : public DogAction {

public:
    DogIdleAction() : DogAction("idle", 0) {}

    Status ExecuteDogAction(Dog* dog, Blackboard* b) override {
            dog->Idle();
            int idleTime = b->GetInt(BBKEY_ACTIONTIME);
            idleTime++;
            if (idleTime >= BOOORING) {
                b->SetBool(BBKEY_ISBORED, true);
            }
            b->SetInt(BBKEY_ACTIONTIME, idleTime);
            return Status::RUNNING;
    }
private:
    const std::string BBKEY_ISBORED = "isBored";
    const int BOOORING = 10;
};