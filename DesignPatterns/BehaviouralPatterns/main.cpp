#include <iostream>

#include "Strategy/Strategy.h"

int main() {

    //==================================================================================================================
    // Strategy
    Context context(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting" << std::endl;
    context.doSomeBusinessLogic();
    std::cout << std::endl;
    std::cout << "Client: Strategy is set to reverse sorting" << std::endl;
    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();

    //==================================================================================================================
    return 0;
}
