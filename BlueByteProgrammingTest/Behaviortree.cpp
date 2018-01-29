#include "Behaviortree.h"
#include "Entity.h"
#include "Blackboard.h"

Status Behaviortree::Execute(Entity* e, Blackboard* b) {
    return root->Execute(e, b);
}
