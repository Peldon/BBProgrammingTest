#pragma once
#include "Controlflow.h"

/* The selector node will execute all children in sequence as long as they return FAILURE. 
 * So it will execute until one of the nodes returns SUCCESS.
 */
class Selector :
    public Controlflow {
public:
    Status Execute(Entity* e, Blackboard* b) override;
};

