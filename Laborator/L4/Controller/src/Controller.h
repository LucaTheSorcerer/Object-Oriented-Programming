//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <string>
#include <vector>
#include "../../Entity/src/Fruit.h"
#include "../../Repository/src/FruitRepository.h"

using namespace std;

class Controller {
private:
    FruitRepository& repository;
public:
    explicit Controller(FruitRepository& m_repository);
    void addFruit(const string& name, const string& origin, const string& expiry_date, int quantity, double price);
    void removeFruit(const string& name, const string& origin);
    list<shared_ptr<Fruit>> searchFruit(const string& search_string);
    list<shared_ptr<Fruit>> getLowStockFruit(int threshold);
    list<shared_ptr<Fruit>> getFruitSortedByExpiry();

    //Function that prints all the fruits
    void printAllFruits();

//    void updateFruit(const string& name, const string& origin, const string& expiry_date, int quantity, double price);
//    list<shared_ptr<Fruit>> getAllFruits();
//    list<shared_ptr<Fruit>> getFruitContainingString(const string& search_string);
//    list<shared_ptr<Fruit>> getLowStockFruit(int threshold);
//    list<shared_ptr<Fruit>> getExpiredFruit(const string& current_date);
//    list<shared_ptr<Fruit>> getFruitByOrigin(const string& origin);
//    list<shared_ptr<Fruit>> getFruitByExpiryDate(const string& expiry_date);
//    list<shared_ptr<Fruit>> getFruitByPrice(double price);
//    list<shared_ptr<Fruit>> getFruitByQuantity(int quantity);
//    list<shared_ptr<Fruit>> getFruitByPriceAndQuantity(double price, int quantity);
//    list<shared_ptr<Fruit>> getFruitsSortedByExpiryDate();

};
