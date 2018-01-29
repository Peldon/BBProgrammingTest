#pragma once
#include "Node.h"

class Decorator : public Node {
public:
    Decorator(Node* child) : child(child) {};
    virtual Status Execute(Entity* e, Blackboard* b) = 0;
protected: 
    Node* child = nullptr;
};

