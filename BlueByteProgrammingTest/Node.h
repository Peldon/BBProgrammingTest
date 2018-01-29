#pragma once

enum Status { SUCCESS, FAILURE, RUNNING };

class Entity;
class Blackboard;

/*
 * Base class for all Behaviortree (BT) nodes
 * All nodes get the gameobject (entity) and the blackboard from their parent and pass them on to their children, if any.
 * 
 * Note: First I had a different implementation in mind, where the general BT classes don't know about the entity class
 * and only the concrete implementations of conditions and actions must be provided with the entity on construction.
 * The rough skeleton seemed to prefer passing everything along, so I used this in the end.
 */
class Node {
public:
    virtual Status Execute(Entity* e, Blackboard* b) = 0;
};

