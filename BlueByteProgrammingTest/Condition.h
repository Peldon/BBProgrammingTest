#pragma once
#include "Node.h"

class Condition : public Node {
public:
    Status Execute(Entity* e, Blackboard* b);
    virtual bool CheckCondition(Entity* e, Blackboard* b) = 0;
};
