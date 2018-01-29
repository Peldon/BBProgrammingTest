#include "DogAction.h"

Status DogAction::Execute(Entity* e, Blackboard* b) {
    Dog* dog = static_cast<Dog*>(e);
    if (dog) {
        if (b->GetString(BBKEY_CURRENTACTION) != actionName) {
            b->SetString(BBKEY_CURRENTACTION, actionName);
            b->SetInt(BBKEY_ACTIONTIME, 0);
        }
        return ExecuteDogAction(dog, b);
    }
    return Status::FAILURE;
}
