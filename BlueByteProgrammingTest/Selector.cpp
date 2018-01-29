#include "Selector.h"
#include "Blackboard.h"

Status Selector::Execute(Entity* e, Blackboard* b) {
    if (children.empty()) {
        return Status::SUCCESS;
    }
    unsigned int index = 0;
    if (!priority) {
        index = b->GetUInt(blackboardKeyForIndex);
    }
    while (true) {
        Node* child = children.at(index);
        Status childstatus = child->Execute(e, b);

        if (childstatus != Status::FAILURE) {
            return childstatus;
        } else {
            index++;
            if (index >= children.size()) {
                b->SetUInt(blackboardKeyForIndex, 0);
                return Status::FAILURE;
            } else {
                b->SetUInt(blackboardKeyForIndex, index);
            }
        }
    }
}
