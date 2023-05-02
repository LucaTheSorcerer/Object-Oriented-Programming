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
    Fruit auxFruit(name, origin, producer, expiry_date, quantity, price);
    bool found = false;

    //If the fruit already exists, we just update the quantity
    for(auto &fruit : *fruits) {
        if(fruit == auxFruit) {
            fruit.setQuantity(fruit.getQuantity() + auxFruit.getQuantity());
            found = true;

            //We update the repository

            float oldPrice = fruit.getPrice();
            int oldQuantity = fruit.getQuantity() - auxFruit.getQuantity();
            float newPrice = auxFruit.getPrice();
            int  newQuantity = auxFruit.getQuantity();
            float averagePrice = (oldPrice * float(oldQuantity) + newPrice * float(newQuantity)) / float(oldQuantity + newQuantity);
            fruit.setPrice(averagePrice);

            if(fruit.getExpiryDate() < auxFruit.getExpiryDate()) {
                fruit.setExpiryDate(expiry_date);
            }
            break;
        }
    }

    if(!found) {
        repositoryFruit.addFruit(auxFruit);
    }
}

void ControllerFruit::Controller::removeFruit(const string &name, const string &origin) {
    Fruit auxFruit(name, origin);
    bool found = false;

    for(const auto &fruit : *fruits){
        if(fruit == auxFruit){
            repositoryFruit.removeFruit(fruit);
            found = true;
            break;
        }
    }
    if(!found)
        throw std::runtime_error("Fruit not found");
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
        if (it.getName().find(search_string) != std::string::npos || it.getOrigin().find(search_string) != std::string::npos)
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

    if(threshold <= 0) {
        throw std::runtime_error("Threshold must be positive");
    }

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

void ControllerFruit::Controller::saveData() {
    repositoryFruit.writeFruitsToFile();
}



