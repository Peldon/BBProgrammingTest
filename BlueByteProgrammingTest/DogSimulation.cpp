#include "DogSimulation.h"

#include <iostream>
#include <memory>

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

void DogSimulation::Run() {
    // bring some dogs to life
    std::unique_ptr<Dog> dog1 = std::make_unique<Dog>("Rocky", 10.f, 15.f);
    std::unique_ptr<Dog> dog2 = std::make_unique<Dog>("Daisy", 4.f, 4.f);
    std::unique_ptr<Dog> dog3 = std::make_unique<Dog>("Bella", 7.f, 5.f);
    std::unique_ptr<Dog> dog4 = std::make_unique<Dog>("Buddy", 3.f, 9.f);
    std::unique_ptr<Dog> dog5 = std::make_unique<Dog>("Lucky", 9.f, 18.f);

    std::unique_ptr<Blackboard> bb1 = std::make_unique<Blackboard>();
    std::unique_ptr<Blackboard> bb2 = std::make_unique<Blackboard>();
    std::unique_ptr<Blackboard> bb3 = std::make_unique<Blackboard>();
    std::unique_ptr<Blackboard> bb4 = std::make_unique<Blackboard>();
    std::unique_ptr<Blackboard> bb5 = std::make_unique<Blackboard>();

    // build BT for dog behavior
    std::unique_ptr<Sequence> eatSequence = std::make_unique<Sequence>(false, "eatSequence");
    std::unique_ptr<Sequence> playSequence = std::make_unique<Sequence>(false, "playSequence");
    // this is a priority selector, so the dog stops playing and starts eating, when exhausted
    std::unique_ptr<Selector> rootSelector = std::make_unique<Selector>(true);

    std::unique_ptr<IsDogHungryCondition> isDogHungryCondition = std::make_unique<IsDogHungryCondition>();
    std::unique_ptr<IsDogBoredCondition> isDogBoredCondition = std::make_unique<IsDogBoredCondition>();
    std::unique_ptr<DogEatAction> dogEatAction = std::make_unique<DogEatAction>();
    std::unique_ptr<DogPlayAction> dogPlayAction = std::make_unique<DogPlayAction>();
    std::unique_ptr<DogIdleAction> dogIdleAction = std::make_unique<DogIdleAction>();

    eatSequence->AddChild(isDogHungryCondition.get());
    eatSequence->AddChild(dogEatAction.get());
    playSequence->AddChild(isDogBoredCondition.get());
    playSequence->AddChild(dogPlayAction.get());
    rootSelector->AddChild(eatSequence.get());
    rootSelector->AddChild(playSequence.get());
    rootSelector->AddChild(dogIdleAction.get());
    std::unique_ptr<Behaviortree> dogBehavior = std::make_unique<Behaviortree>(rootSelector.get());

    // std::endless simulation
    for (int i = 0; i < 1000; i++) {
        //std::cout << i << std::endl;
        Status result1 = dogBehavior->Execute(dog1.get(), bb1.get());
        Status result2 = dogBehavior->Execute(dog2.get(), bb2.get());
        Status result3 = dogBehavior->Execute(dog3.get(), bb3.get());
        Status result4 = dogBehavior->Execute(dog4.get(), bb4.get());
        Status result5 = dogBehavior->Execute(dog5.get(), bb5.get());

        dog1->Tick();
        dog2->Tick();
        dog3->Tick();
        dog4->Tick();
        dog5->Tick();
    }
}