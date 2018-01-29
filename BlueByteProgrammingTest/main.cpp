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
#include "DogIdleAction.h"

using namespace std;

int main() {
    cout << "Blue Byte Programming Test" << endl;
    cout << "Gerald Schenke 29.01.2018" << endl;

    // bring some dogs to life
    Dog* dog1 = new Dog("Rocky", 10, 15);
    Dog* dog2 = new Dog("Daisy", 4, 4);
    Dog* dog3 = new Dog("Bella", 7, 5);
    Dog* dog4 = new Dog("Buddy", 3, 9);
    Dog* dog5 = new Dog("Lucky", 9, 18);
    Blackboard* bb1 = new Blackboard();
    Blackboard* bb2 = new Blackboard();
    Blackboard* bb3 = new Blackboard();
    Blackboard* bb4 = new Blackboard();
    Blackboard* bb5 = new Blackboard();

    // build BT for dog behavior
    Sequence* eatSequence = new Sequence(false, "eatSequence");
    eatSequence->AddChild(new IsDogHungryCondition());
    eatSequence->AddChild(new DogEatAction());
    Sequence* playSequence = new Sequence(false, "playSequence");
    playSequence->AddChild(new IsDogBoredCondition());
    playSequence->AddChild(new DogPlayAction());
    // this is a priority selector, so the dog stops playing and start eating, when exhausted
    Selector* rootSelector = new Selector(true);
    rootSelector->AddChild(eatSequence);
    rootSelector->AddChild(playSequence);
    rootSelector->AddChild(new DogIdleAction());
    Behaviortree* dogBehavior = new Behaviortree(rootSelector);

    // endless simulation
    for (int i = 0; i < 1000; i++) {
        //cout << i << endl;
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

