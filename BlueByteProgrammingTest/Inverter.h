#pragma once
#include "Decorator.h"
class Inverter : public Decorator {
public:
    Status Execute(Entity* e, Blackboard* b) override {
        if (child) {
            Status childStatus = child->Execute(e, b);
            if (childStatus == Status::FAILURE) {
                return Status::SUCCESS;
            } else if (childStatus == Status::SUCCESS) {
                return Status::FAILURE;
            } else {
                return childStatus;
            }

        }
        return Status::FAILURE;
    };
};

