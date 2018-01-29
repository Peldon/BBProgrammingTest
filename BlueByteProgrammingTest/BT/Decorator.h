#pragma once
#include "Node.h"
class Decorator : public Node {
public:
    Decorator(Node* childNode) : child(childNode) {};
    virtual Status Execute(Entity* e, Blackboard* b) = 0;
protected: 
    Node* child = nullptr;
};

