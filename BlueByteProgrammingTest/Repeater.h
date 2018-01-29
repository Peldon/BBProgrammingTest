#pragma once
#include "Decorator.h"
class Repeater : public Decorator {
public:
    Status Execute(Entity* e, Blackboard* b) override {
        if (child) {
            Status childStatus;
            do{
                childStatus = child->Execute(e, b);
            } while (RepeatCondition(childStatus, b));
            return childStatus;
        }
        return Status::FAILURE;
    };

    /* override this to implement the condition for the repeater
     * return true to keep repeating, false for stop repeating
     */
    virtual bool RepeatCondition(Status s, Blackboard* b) = 0;
};

