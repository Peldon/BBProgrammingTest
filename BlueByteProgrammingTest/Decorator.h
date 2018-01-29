#pragma once
#include "Node.h"
class Decorator :
    public Node {
public:
    Decorator(Node* childNode) : child(childNode) {};
    virtual Status Execute(Entity* e, Blackboard* b) {
        if (child) {
            return child->Execute(e, b);
        }
        return Status::FAILURE;
    };
protected: 
    Node* child = nullptr;
};

