//
// Created by Luca Tudor on 13.04.2023.
//


#include "../../Controller/src/Controller.h"

ControllerFruit::Controller::Controller(const string &filename): repositoryFruit(filename) {
    fruits = repositoryFruit.getAllFruits();
}

void ControllerFruit::Controller::addFruit(const string &name, const string &origin, const string &producer,
                                           const Date &expiry_date, int quantity, double price) {
    repositoryFruit.addFruit(Fruit(name, origin, producer, expiry_date, quantity, price));

}

void ControllerFruit::Controller::removeFruit(const string &name, const string &origin) {
    Fruit auxFruit(name, origin);
    for(const auto &fruit : *fruits){
        if(fruit == auxFruit){
            repositoryFruit.removeFruit(fruit);
            break;
        }
    }
}

unique_ptr<list<Fruit>> ControllerFruit::Controller::getAllFruits() {
    auto sortedFruits = std::make_unique<list<Fruit>>(*fruits);

    sortedFruits->sort([](const Fruit &fruit1, const Fruit &fruit2) -> bool {
        return fruit1.getExpiryDate() < fruit2.getExpiryDate();
    });

    return sortedFruits;
}

unique_ptr<list<Fruit>> ControllerFruit::Controller::findFruitsContainingString(const string &search_string) {

    auto foundFruits = std::make_unique<list<Fruit>>();

    if(search_string.empty()){
        return getAllFruits();
    }

    for(const auto &fruit : *fruits){
        if(fruit.getName().find(search_string) != string::npos){
            foundFruits->push_back(fruit);
        }
    }

    foundFruits->sort([](const Fruit &fruit1, const Fruit &fruit2) -> bool {
        return fruit1.getName() < fruit2.getName();
    });

    return foundFruits;
}
