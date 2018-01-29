#include "Inverter.h"

Status Inverter::Execute(Entity* e, Blackboard* b) {
    if (child) {
        Status childStatus = child->Execute(e, b);
        if (childStatus == Status::FAILURE) {
            return Status::SUCCESS;
        } else if (childStatus == Status::SUCCESS) {
            return Status::FAILURE;
        } else {
            return childStatus;
        }

    }
    return Status::FAILURE;
};

