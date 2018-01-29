#pragma once
#include "Decorator.h"

class Inverter : public Decorator {
public:
    Status Execute(Entity* e, Blackboard* b) override;
};

