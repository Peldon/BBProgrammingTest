#include "Repeater.h"

Status Repeater::Execute(Entity* e, Blackboard* b) {
    if (child) {
        Status childStatus;
        do {
            childStatus = child->Execute(e, b);
        } while (RepeatCondition(childStatus, b));
        return childStatus;
    }
    return Status::FAILURE;
};
