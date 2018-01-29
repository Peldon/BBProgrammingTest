#pragma once

#include "Node.h"
#include "Entity.h"
#include "Blackboard.h"

class Behaviortree : public Node {
public:
    Behaviortree(Node* rootNode) : root(rootNode) {};
    Status Execute(Entity* e, Blackboard* b) {
        if (root) {
            return root->Execute(e, b);
        } else {
            return Status::FAILURE;
        }
    };

private:
    Node* root;
 

};
