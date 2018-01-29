#include "Sequence.h"

Status Sequence::Execute(Entity* e, Blackboard* b){
    if (children.empty()) {
        return Status::SUCCESS;
    }
    while (true) {
        Node* child = children.at(index);
        Status childstatus = child->Execute(e, b);

        if (childstatus != Status::SUCCESS) {
            return childstatus;
        }else{
            index++;
            if (index >= children.size()) {
                index = 0;
                return Status::SUCCESS;
            }
        }
    }
}
