#pragma once
#include "Decorator.h"

class Inverter : public Decorator {
public:
    Inverter(Node* child) : Decorator(child) {}
    Status Execute(Entity* e, Blackboard* b) override;
};

