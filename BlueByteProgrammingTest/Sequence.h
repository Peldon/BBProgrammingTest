#pragma once
#include "Controlflow.h"

/* The sequence node will execute all children in sequence. 
 * If a child returns other than SUCCESS, it will stop iterating and return this state.
 * It returns SUCCESS only if all children return SUCCESS.
 */
class Sequence : public Controlflow {
public:
    /* if priority is set to true, the sequence will not store the running child and always start with the first child
    uniqueName is necessary for any non-priority sequence. It is used to store the index of the running child on the blackboard
    I know that this is no optimal solution */
    Sequence(bool priority = false, std::string uniqueName = "") : priority(priority), blackboardKeyForIndex(uniqueName) {};
    Status Execute(Entity* e, Blackboard* b) override;

private:
    bool priority = false;
    std::string blackboardKeyForIndex = "";
};

