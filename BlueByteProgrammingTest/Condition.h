#pragma once
#include "Node.h"
class Condition :
    public Node {
public:
    Status Execute(Entity* e, Blackboard* b) {
        if (CheckCondition(e, b)) {
            return Status::SUCCESS;
        } else {
            return Status::FAILURE;
        }
    }
    virtual bool CheckCondition(Entity* e, Blackboard* b) = 0;
};

