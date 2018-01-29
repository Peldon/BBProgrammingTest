#pragma once
#include "Node.h"
#include "Blackboard.h"

/* Action nodes perform actions and return RUNNING as long an action is ongoing.
 * Finally, they will return SUCCESS or FAILURE depending on the performed action.#
 * 
 * Note: Since implementations of actions could just inherit from Node directly I thought about adding a method "ExecuteAction" that is called from Execute and make Execute final here,
 * but decided against it to avoid code clutter. I still kept this class for clarity of hierarchy even though it does nothing (yet)
 */
class Action : public Node {
public:
    /* Override this method to implement actions */
    virtual Status Execute(Entity* e, Blackboard* b) = 0;
};

