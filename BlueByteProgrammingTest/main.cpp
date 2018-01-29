#include <iostream>

#include "Behaviortree.h"
#include "Sequence.h"
#include "Selector.h"
#include "Blackboard.h"
#include "Dog.h"
#include "IsDogHungryCondition.h"
#include "IsDogBoredCondition.h"
#include "DogEatAction.h"
#include "DogPlayAction.h"

using namespace std;

int main() {
    cout << "Blue Byte Programming Test" << endl;
    cout << "Gerald Schenke 29.01.2018" << endl;

    // bring some dogs to life
    Dog* dog1 = new Dog("Rocky");
    Dog* dog2 = new Dog("Daisy");
    Dog* dog3 = new Dog("Bella");
    Dog* dog4 = new Dog("Buddy");
    Dog* dog5 = new Dog("Lucky");
    Blackboard* bb1 = new Blackboard();
    Blackboard* bb2 = new Blackboard();
    Blackboard* bb3 = new Blackboard();
    Blackboard* bb4 = new Blackboard();
    Blackboard* bb5 = new Blackboard();

    // build BT for dog behavior
    Sequence* eatSequence = new Sequence();
    eatSequence->AddChild(new IsDogHungryCondition());
    eatSequence->AddChild(new DogEatAction());
    Sequence* playSequence = new Sequence();
    playSequence->AddChild(new IsDogBoredCondition());
    playSequence->AddChild(new DogPlayAction());
    // this is a priority selector, so the dog stops playing and start eating, when exhausted
    Selector* rootSelector = new Selector(true);
    rootSelector->AddChild(eatSequence);
    rootSelector->AddChild(playSequence);

    Behaviortree* dogBehavior = new Behaviortree(rootSelector);
    // endless simulation
    for (;;) {
        Status result1 = dogBehavior->Execute(dog1, bb1);
        Status result2 = dogBehavior->Execute(dog2, bb2);
        Status result3 = dogBehavior->Execute(dog3, bb3);
        Status result4 = dogBehavior->Execute(dog4, bb4);
        Status result5 = dogBehavior->Execute(dog5, bb5);

        dog1->Tick();
        dog2->Tick();
        dog3->Tick();
        dog4->Tick();
        dog5->Tick();
    }


    cout << "Goodbye" << endl;
    return 0;
}

