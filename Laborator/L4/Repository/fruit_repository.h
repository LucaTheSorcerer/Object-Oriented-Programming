//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <memory>
#include <list>
#include <string>
#include <utility>
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Entity/Fruit.h"
using namespace std;

class FruitRepository {

protected:
    list<shared_ptr<Fruit>> fruits;

private:
    string filename;

public:
    FruitRepository();
    //constructor with a filename
    explicit FruitRepository(const string& filename);
    void addFruit(shared_ptr<Fruit>& FruitList);
    void updateFruit(shared_ptr<Fruit>& fruit);
    void removeFruit(const string& name, const string& origin);
    list<shared_ptr<Fruit>> getAllFruits();
    [[nodiscard]] list<shared_ptr<Fruit>> searchFruit(const string& search_string) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getLowStockFruit(int threshold) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getExpiredFruit(const string& current_date) ;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitByOrigin(const string& origin) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitByExpiryDate(const string& expiry_date) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitByPrice(double price) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitByQuantity(int quantity) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitByPriceAndQuantity(double price, int quantity) const;
    [[nodiscard]] list<shared_ptr<Fruit>> getFruitsSortedByExpiryDate() const;
    void saveFruits(const string& filename);
    void loadFruits(const string& filename);
};

