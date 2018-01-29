#include "Sequence.h"
#include "Blackboard.h"

Status Sequence::Execute(Entity* e, Blackboard* b){
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

        if (childstatus != Status::SUCCESS) {
            return childstatus;
        }else{
            index++;
            if (index >= children.size()) {
                b->SetUInt(blackboardKeyForIndex, 0);
                return Status::SUCCESS;
            }else{
                b->SetUInt(blackboardKeyForIndex, index);
            }
        }
    }
}
