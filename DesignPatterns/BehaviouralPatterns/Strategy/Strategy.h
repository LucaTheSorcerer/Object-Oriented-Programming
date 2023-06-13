//
// Created by Luca Tudor on 13.06.2023.
//

#ifndef BEHAVIOURALPATTERNS_STRATEGY_H
#define BEHAVIOURALPATTERNS_STRATEGY_H


#include <string_view>
#include <memory>
#include <iostream>

/**
 * The strategy interface declares operations common to all supported versions of some algorithm
 *
 * The context uses this interface to call the algorithm defined by Concrete class Strategies
 */

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual std::string doAlgorithm(std::string_view data) const = 0;

};

/**
 * The context defines the interface of interest to clients
 */

class Context {

    /**
     * @var Strategy The Context maintains a reference to one of the Strategy objects.
     * The Context does not know the concrete class of a strategy. IT should
     * work with all strategies via the Strategy interface
     */

private:
    std::unique_ptr<Strategy> strategy_;

    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime
     */

public:
    explicit Context(std::unique_ptr<Strategy> &&strategy = {} ) : strategy_(std::move(strategy)) {}

    /**
     * Usually, the Context allows replacing a Strategy object at runtime
     */

    void set_strategy(std::unique_ptr<Strategy> &&strategy) {
        strategy_ = std::move(strategy);
    }

    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing multiple versions of the algorithm on its own
     */

    void doSomeBusinessLogic() const;
};

/**
 * Concrete Strategies implement the algorithm while following the base Strategy
 * interface. The interface makes them interchangeable in the Context
 */

class ConcreteStrategyA : public Strategy {
public:
    std::string doAlgorithm(std::string_view data) const override;
};

class ConcreteStrategyB : public Strategy {
public:
    std::string doAlgorithm(std::string_view data) const override;
};

#endif //BEHAVIOURALPATTERNS_STRATEGY_H
