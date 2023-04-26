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

private:
    string filename;

    list<shared_ptr<Fruit>> fruits;

public:
    FruitRepository();
    //constructor with a filename

    explicit FruitRepository(const string &filename);

    void addFruit(const shared_ptr<Fruit> &fruit);

    void removeFruit(const shared_ptr<Fruit> &fruit);

    [[nodiscard]] list<shared_ptr<Fruit>> getFruitContainingString(const string &name) const;

    [[nodiscard]] list<shared_ptr<Fruit>> getLowQuantityFruits(int threshold) const;

    [[nodiscard]] list<shared_ptr<Fruit>> getFruitsSortedByExpiryDate() const;

    void saveFruits(const string &filename);

    void loadFruits(const string &filename);

    void updateFruit(shared_ptr<Fruit> &fruit);

    //function that prints all fruits from the repository to the user

    void printFruits() const;


};


