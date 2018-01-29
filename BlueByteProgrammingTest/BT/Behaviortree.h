#pragma once

#include "Node.h"
#include "../Entity.h"
#include "Blackboard.h"

class Behaviortree : public Node {
public:
    Behaviortree(Node* root) : root(root) {};
    Status Execute(Entity* e, Blackboard* b);

private:
    Node* root;
 
};
