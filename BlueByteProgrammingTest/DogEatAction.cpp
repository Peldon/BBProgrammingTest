#include "DogEatAction.h"

Status DogEatAction::ExecuteDogAction(Dog* dog, Blackboard* b) {
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
