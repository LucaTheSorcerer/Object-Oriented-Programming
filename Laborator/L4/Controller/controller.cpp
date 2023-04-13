//
// Created by Luca Tudor on 13.04.2023.
//
#include "controller.h"

Controller::Controller(FruitFileRepository& repository) : repository(repository) {}

void Controller::addFruit(const string &name, const string &origin, const string &expiry_date, int quantity, double price) {
    std::shared_ptr<Fruit> fruit = std::make_shared<Fruit>(name, origin, expiry_date, quantity, price);
    repository.addFruit(fruit);
}

void Controller::updateFruit(const string &name, const string &origin, const string &expiry_date, int quantity,
                             double price) {
    std::shared_ptr<Fruit> fruit = std::make_shared<Fruit>(name, origin, expiry_date, quantity, price);
    repository.updateFruit(fruit);
}

void Controller::removeFruit(const string &name, const string &origin) {

}

list<shared_ptr<Fruit>> Controller::getAllFruits() {
    repository.getAllFruits();
}

list<shared_ptr<Fruit>> Controller::searchFruit(const string &search_string) {


}

list<shared_ptr<Fruit>> Controller::getLowStockFruit(int threshold) {
    //this gets the low stock fruit from the repository


}

list<shared_ptr<Fruit>> Controller::getExpiredFruit(const string &current_date) {
    //this gets the expired fruit from the repository

    return repository.getExpiredFruit(current_date);
}

list<shared_ptr<Fruit>> Controller::getFruitByOrigin(const string &origin) {
    //this gets the fruit by origin from the repository

    return repository.getFruitByOrigin(origin);
}

list<shared_ptr<Fruit>> Controller::getFruitByExpiryDate(const string &expiry_date) {
    //this gets the fruit by expiry date from the repository

    return repository.getFruitByExpiryDate(expiry_date);
}

list<shared_ptr<Fruit>> Controller::getFruitByPrice(double price) {
    //this gets the fruit by price from the repository

    return repository.getFruitByPrice(price);
}

list<shared_ptr<Fruit>> Controller::getFruitByQuantity(int quantity) {
    //this gets the fruit by quantity from the repository

    return repository.getFruitByQuantity(quantity);
}

list<shared_ptr<Fruit>> Controller::getFruitByPriceAndQuantity(double price, int quantity) {
    //this gets the fruit by price and quantity from the repository

    return repository.getFruitByPriceAndQuantity(price, quantity);
}

list<shared_ptr<Fruit>> Controller::getFruitsSortedByExpiryDate() {
    //this gets the fruit sorted by expiry date from the repository

    return repository.getFruitsSortedByExpiryDate();
}


