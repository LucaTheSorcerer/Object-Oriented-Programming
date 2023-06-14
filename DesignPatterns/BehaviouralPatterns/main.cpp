#include <iostream>

#include "Strategy/Strategy.h"
#include "Observer/Observer.h"

int main() {

    //==================================================================================================================
    // Strategy Design Pattern
    Context context(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting" << std::endl;
    context.doSomeBusinessLogic();
    std::cout << std::endl;
    std::cout << "Client: Strategy is set to reverse sorting" << std::endl;
    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();

    std::cout << std::endl;

    //==================================================================================================================
    // Observer Design Pattern
    std::cout << "Observer Design Pattern" << std::endl;
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->SomeBusinessLogic();

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("Dacia goes vroom vroom!");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    return 0;
}
