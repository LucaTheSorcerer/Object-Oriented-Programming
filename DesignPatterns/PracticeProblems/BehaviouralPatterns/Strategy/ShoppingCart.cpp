//
// Created by Luca Tudor on 14.06.2023.
//

#include "ShoppingCart.h"

void ShoppingCart::setStrategy(std::unique_ptr<Strategy> &&strategy) {
    this->strategy_ = std::move(strategy);
}

double ShoppingCart::calculateTotal() {

    if(strategy_) {
        double discount = strategy_->calculateDiscount(total_);
        return total_ - discount;
    }
    return total_;
}

double PercentageDiscountStrategy::calculateDiscount(double total) const {

    return total * (percentage_ / 100);
}

double FixedAmountDiscountStrategy::calculateDiscount(double total) const {

    return fixedAmount_;
}
