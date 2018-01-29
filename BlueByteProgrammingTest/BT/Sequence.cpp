#include "Sequence.h"
#include "Blackboard.h"

Status Sequence::Execute(Entity* e, Blackboard* b) {
    if (children.empty()) {
        return Status::SUCCESS;
    }
    unsigned int index = 0;
    if (!priority) {
        index = b->GetUInt(blackboardKeyForIndex);
    }
    for (; index < children.size(); index++) {
        Node* child = children.at(index);
        Status childstatus = child->Execute(e, b);

        if (childstatus != Status::SUCCESS) {
            if (!priority && childstatus == Status::RUNNING) {
                b->SetUInt(blackboardKeyForIndex, index);
            }
            return childstatus;
        }
    }
    if (!priority) {
        b->SetUInt(blackboardKeyForIndex, 0);
    }
    return Status::SUCCESS;

}
