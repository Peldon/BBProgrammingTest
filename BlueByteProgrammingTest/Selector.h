#pragma once
#include "Controlflow.h"

/* The selector node will execute all children in sequence as long as they return FAILURE. 
 * So it will execute until one of the nodes returns SUCCESS.
 */
class Selector : public Controlflow {
public:
    /* if priority is set to true, the selector will not store the running child and always start with the first child */
    Selector(bool priority = false) : priority(priority) {};
    Status Execute(Entity* e, Blackboard* b) override;

private:
    bool priority = false;
};

