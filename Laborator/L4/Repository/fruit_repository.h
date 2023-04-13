//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <memory>
#include <list>
#include <string>
#include <utility>
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Entity/Fruit.h"
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Repository/FileRepository/fruit_file_repository.h"
using namespace std;

class FruitRepository {

protected:
    //list<shared_ptr<Fruit>> fruits_;
    FruitFileRepository fruitFileRepository;

    list<shared_ptr<Fruit>> fruits;
public:
    FruitRepository();
    virtual void addFruit(shared_ptr<Fruit>& fruit);
    virtual void updateFruit(shared_ptr<Fruit>& fruit);
    virtual void removeFruit(const string& name, const string& origin);
    virtual list<shared_ptr<Fruit>> getAllFruits();
    [[nodiscard]] virtual list <shared_ptr<Fruit>> searchFruit(const string& search_string) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getLowStockFruit(int threshold) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getExpiredFruit(const string& current_date) ;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitByOrigin(const string& origin) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitByExpiryDate(const string& expiry_date) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitByPrice(double price) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitByQuantity(int quantity) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitByPriceAndQuantity(double price, int quantity) const;
    [[nodiscard]] virtual list <shared_ptr<Fruit>> getFruitsSortedByExpiryDate() const;
};

