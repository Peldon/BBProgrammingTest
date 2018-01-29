#include "Condition.h"

Status Condition::Execute(Entity* e, Blackboard* b) {
    if (CheckCondition(e, b)) {
        return Status::SUCCESS;
    } else {
        return Status::FAILURE;
    }
}
