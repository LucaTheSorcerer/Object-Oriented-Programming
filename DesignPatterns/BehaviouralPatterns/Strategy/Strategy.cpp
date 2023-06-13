//
// Created by Luca Tudor on 13.06.2023.
//

#include "Strategy.h"

void Context::doSomeBusinessLogic() const {
    if(strategy_) {
        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)" << std::endl;
        std::string result = strategy_->doAlgorithm("aecbd");
        std::cout << result << std::endl;
    } else {
        std::cout << "Context: Strategy is not set" << std::endl;
    }
}

std::string ConcreteStrategyA::doAlgorithm(std::string_view data) const {
    std::string result(data);
    std::sort(result.begin(), result.end());

    return result;
}

std::string ConcreteStrategyB::doAlgorithm(std::string_view data) const {
    std::string result(data);
    std::sort(result.begin(), result.end(), std::greater<>());

    return result;
}
