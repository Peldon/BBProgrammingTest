#pragma once
#include "Node.h"
#include "Dog.h"

class IsHungry :
    public Node {
public:
    Status Execute(Entity* e, Blackboard* b) override {
        Dog* dog = static_cast<Dog*>(e);
        if (dog) {
            if (dog->IsHungry()) {
                return Status::SUCCESS;
            } else {
                return Status::FAILURE;
            }
        }
        return Status::FAILURE;
    };
};

