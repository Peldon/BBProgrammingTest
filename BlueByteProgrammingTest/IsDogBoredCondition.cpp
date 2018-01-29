#include "IsDogBoredCondition.h"

bool IsDogBoredCondition::CheckCondition(Entity* e, Blackboard* b) {
    return b->GetBool(BBKEY_ISBORED);
};
