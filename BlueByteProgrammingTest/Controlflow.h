#pragma once
#include "Node.h"
#include <vector>


class Controlflow :
    public Node {
public:
    void AddChild(Node* child) { children.push_back(child); };

protected:
    std::vector<Node*> children;
    // TODO state! move this to blackboard!?
    size_t index = 0;
};

