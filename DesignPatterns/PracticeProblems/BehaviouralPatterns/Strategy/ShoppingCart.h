//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_SHOPPINGCART_H
#define PRACTICEPROBLEMS_SHOPPINGCART_H

#include <memory>

/**
 * Implement a ShoppingCart class that allows users to add items to their cart and calculate the total price based
 * on different discount strategies. Define an abstract DiscountStrategy class with a calculateDiscount() method.
 * Create concrete subclasses that implement different discount strategies (e.g., PercentageDiscountStrategy,
 * FixedAmountDiscountStrategy). The ShoppingCart class should have a setDiscountStrategy() method to set the discount
 * strategy and a calculateTotal() method that applies the discount strategy to calculate the total price.
 */

class Strategy {
public:
    virtual ~Strategy() = default;
    [[nodiscard]] virtual double calculateDiscount(double total) const = 0;
};

class ShoppingCart {

private:
    std::unique_ptr<Strategy> strategy_;

    double total_;


public:
    explicit ShoppingCart(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<Strategy> &&strategy);

    double calculateTotal();

    void addToCart(double price, int quantity) {
        total_ += price * quantity;
    }
};

class PercentageDiscountStrategy : public Strategy {
private:
    double percentage_;
public:
    explicit PercentageDiscountStrategy(double percentage) : percentage_(percentage) {}
    [[nodiscard]] double calculateDiscount(double total) const override;
};

class FixedAmountDiscountStrategy : public Strategy {
private:
    double fixedAmount_;
public:
    explicit FixedAmountDiscountStrategy(double fixedAmount) : fixedAmount_(fixedAmount) {}
    [[nodiscard]] double calculateDiscount(double total) const override;
};

class A {

private:
    class B {

    };
};



#endif //PRACTICEPROBLEMS_SHOPPINGCART_H
