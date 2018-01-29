#pragma once
#include "Controlflow.h"

/* The sequence node will execute all children in sequence. 
 * If a child returns other than SUCCESS, it will stop iterating and return this state.
 * It returns SUCCESS only if all children return SUCCESS.

 * This Sequence actually has a state - currently stored in the instance. TODO change that to use blackboard!?
 */
class Sequence :
    public Controlflow {
public:
    Status Execute(Entity* e, Blackboard* b) override;
};

