//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_SHOPPING_H
#define PRACTICEPROBLEMS_SHOPPING_H

#include <memory>
#include <iostream>
#include "ShoppingCart.h"

void shoppingCart() {

    ShoppingCart cart(std::make_unique<PercentageDiscountStrategy>(10.0));

    cart.addToCart(10.0, 2);
    cart.addToCart(5.0, 3);

    std::cout <<  "Total price with 10% discount: " << cart.calculateTotal() << std::endl;

    cart.setStrategy(std::make_unique<FixedAmountDiscountStrategy>(5.0));

    std::cout <<  "Total price with $5 discount: " << cart.calculateTotal() << std::endl;
}

#endif //PRACTICEPROBLEMS_SHOPPING_H
