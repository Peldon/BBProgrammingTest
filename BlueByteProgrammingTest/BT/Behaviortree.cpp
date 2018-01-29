#include "Behaviortree.h"

Status Behaviortree::Execute(Entity* e, Blackboard* b) {
    if (root) {
        return root->Execute(e, b);
    } else {
        return Status::FAILURE;
    }
};
