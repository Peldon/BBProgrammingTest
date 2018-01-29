#include "DogIdleAction.h"

Status DogIdleAction::ExecuteDogAction(Dog* dog, Blackboard* b) {
    dog->Idle();
    int idleTime = b->GetInt(BBKEY_ACTIONTIME);
    idleTime++;
    if (idleTime >= BOOORING) {
        b->SetBool(BBKEY_ISBORED, true);
    }
    b->SetInt(BBKEY_ACTIONTIME, idleTime);
    return Status::RUNNING;
}
