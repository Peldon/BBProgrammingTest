#pragma once
#include "Decorator.h"
class Repeater : public Decorator {
public:
    Status Execute(Entity* e, Blackboard* b) override {
        if (child) {
            Status childStatus;
            do{
            while (true) {
                childStatus = child->Execute(e, b);
                if (AbortCondition(childStatus, b)) {
                    break;
                }
            }
            return childStatus;
        }
        return Status::FAILURE;
    };

    /* override this to implement the condition for the repeater
     * return true to stop repeating, false for keep repeating
     */
    virtual bool AbortCondition(Status s, Blackboard* b) = 0;
};

