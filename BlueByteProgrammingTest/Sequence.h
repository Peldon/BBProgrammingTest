#pragma once
#include "Controlflow.h"

/* The sequence node will execute all children in sequence. 
 * If a child returns other than SUCCESS, it will stop iterating and return this state.
 * It returns SUCCESS only if all children return SUCCESS.
 */
class Sequence : public Controlflow {
public:
    /* if priority is set to true, the sequence will not store the running child and always start with the first child */
    Sequence(bool priority = false) : priority(priority) {};
    Status Execute(Entity* e, Blackboard* b) override;

private:
    bool priority = false;
};

