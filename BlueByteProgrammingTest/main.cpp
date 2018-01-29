#include <iostream>

#include "Behaviortree.h"
#include "Sequence.h"
#include "Selector.h"
#include "Blackboard.h"
#include "Dog.h"
#include "main.h"

using namespace std;

int main() {
    cout << "Blue Byte Programming Test" << endl;
    cout << "Gerald Schenke 29.01.2018" << endl;

    // bring some dogs to life
    Dog* myDog1 = new Dog("Rocky");
    Dog* myDog2 = new Dog("Daisy");
    Dog* myDog3 = new Dog("Bella");
    Dog* myDog4 = new Dog("Buddy");
    Dog* myDog5 = new Dog("Lucky");

    // build BT for dog behavior
    Sequence* mySequence = new Sequence();
    Selector* mySelector = new Selector();
    mySelector->AddChild(mySequence);

    Behaviortree* myDogBehavior = new Behaviortree(mySelector);
    // endless simulation
    for (;;) {
        Status result1 = myDogBehavior->Execute(myDog1, new Blackboard());
        Status result2 = myDogBehavior->Execute(myDog2, new Blackboard());
        Status result3 = myDogBehavior->Execute(myDog3, new Blackboard());
        Status result4 = myDogBehavior->Execute(myDog4, new Blackboard());
        Status result5 = myDogBehavior->Execute(myDog5, new Blackboard());

        myDog1->Tick();
        myDog2->Tick();
        myDog3->Tick();
        myDog4->Tick();
        myDog5->Tick();
    }


    cout << "Goodbye" << endl;
    return 0;
}

