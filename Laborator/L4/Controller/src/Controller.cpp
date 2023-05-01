//
// Created by Luca Tudor on 13.04.2023.
//


#include "../../Controller/src/Controller.h"

#include <iostream>
using std::cout;

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
        }
    }
}

unique_ptr<::vector<Fruit>> ControllerFruit::Controller::getAllFruits() {
    auto sortedFruits = std::make_unique<vector<Fruit>>(*fruits);
    std::sort(sortedFruits->begin(), sortedFruits->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );
    return sortedFruits;
}

unique_ptr<vector<Fruit>> ControllerFruit::Controller::findFruitsContainingString(const string &search_string) {

    auto result = std::make_unique<vector<Fruit>>();

    if (search_string.empty())
        return getAllFruits();

    for (const auto &it: *fruits) {
        if (it.getName().find(search_string) != std::string::npos)
            result->push_back(it);
    }

    std::sort(result->begin(), result->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );

    return result;
}

unique_ptr<vector<Fruit>> ControllerFruit::Controller::findFruitsWithLowStock(int threshold) {

    //returns a list of fruits with a quantity lower than the threshold

    auto result = std::make_unique<vector<Fruit>>();

    for(const auto &fruit : *fruits){
        if(fruit.getQuantity() < threshold){
            result->push_back(fruit);
        }
    }

    return result;
}

unique_ptr<vector<Fruit>> ControllerFruit::Controller::getFruitSortedByExpiry() {

    //returns a list of fruits sorted by expiry date

    auto result = std::make_unique<vector<Fruit>>(*fruits);

    std::sort(result->begin(), result->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getExpiryDate() < b.getExpiryDate();
              }
    );

    return result;
}

void ControllerFruit::Controller::printAllFruits() {

    //prints all fruits

    for(const auto &fruit : *fruits){
        cout << fruit << endl;
    }

}


