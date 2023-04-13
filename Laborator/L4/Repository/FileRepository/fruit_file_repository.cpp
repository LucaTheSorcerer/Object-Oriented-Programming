//
// Created by Luca Tudor on 13.04.2023.
//
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Repository/fruit_repository.h"
#include <utility>
#include <fstream>
#include <iostream>

using namespace std;

FruitFileRepository::FruitFileRepository(const string& filename) : FruitRepository() {
    //load fruits from file
    this->filename = filename;
    loadFruits();
}

void FruitFileRepository::addFruit(shared_ptr<Fruit>& fruit) {
    FruitRepository::addFruit(fruit);
    saveFruits();
}

void FruitFileRepository::updateFruit(shared_ptr<Fruit>& fruit) {
    FruitRepository::updateFruit(fruit);
    saveFruits();
}

void FruitFileRepository::saveFruits() {
    //This function will save the fruits to the file
    ofstream fout(this->filename);
    for(const auto &fruit : fruits){
        fout << fruit->getName() << "," << fruit->getOrigin() << "," << fruit->getExpiryDate() << "," << fruit->getQuantity() << "," << fruit->getPrice() << endl;
    }
    fout.close();
}

void FruitFileRepository::loadFruits() {
    //This function loads the fruits from the file;

    //TODO
}




