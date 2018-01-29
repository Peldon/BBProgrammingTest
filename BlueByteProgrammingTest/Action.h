#pragma once
#include "Node.h"

/* Action nodes perform actions and return RUNNING as long an action is ongoing.
* Finally, they will return SUCCESS or FAILURE depending on the performed action.
*/
class Action :
    public Node {
public:
    /* Execute the action */
    virtual Status Execute(Entity* e, Blackboard* b) = 0;
};

