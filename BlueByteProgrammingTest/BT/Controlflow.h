#pragma once
#include "Node.h"
#include <vector>


class Controlflow : public Node {
public:
    void AddChild(Node* child);

protected:
    std::vector<Node*> children;
};

