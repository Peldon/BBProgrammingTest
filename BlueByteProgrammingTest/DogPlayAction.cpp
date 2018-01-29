#include "DogPlayAction.h"

Status DogPlayAction::ExecuteDogAction(Dog* dog, Blackboard* b) {
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
