#pragma once
#include "Controlflow.h"

/* The selector node will execute all children in sequence as long as they return FAILURE. 
 * So it will execute until one of the nodes returns SUCCESS.
 */
class Selector : public Controlflow {
public:
    /* if priority is set to true, the sequence will not store the running child and always start with the first child
    uniqueName is necessary for any non-priority sequence. It is used to store the index of the running child on the blackboard
    I know that this is no optimal solution */
    Selector(bool priority = false, std::string uniqueName = "") : priority(priority), blackboardKeyForIndex(uniqueName) {};
    Status Execute(Entity* e, Blackboard* b) override;

private:
    bool priority = false;
    std::string blackboardKeyForIndex = "";
};

