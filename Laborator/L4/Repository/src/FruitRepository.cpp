//
// Created by Luca Tudor on 13.04.2023.
//
//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include "FruitRepository.h"
//
//Repository::FruitRepository::FruitRepository(const string &file_) {
//    this->filename = file_;
//
//    std::ifstream file(file_);
//
//    if (!file.is_open()) {
//        throw std::runtime_error("File could not be opened!");
//    }
//
//    fruits = std::make_shared<list<Fruit>>();
//
//    string line;
//    std::getline(file, line);
//
//    while (std::getline(file, line)) {
//        Fruit fruit = convertFromString(line);
//        fruits->push_back(fruit);
//    }
//
//    file.close();
//}
//
//
//void Repository::FruitRepository::addFruit(const Fruit &fruit) {
//    //This function adds a fruit to the repositor
//    fruits->push_back(fruit);
//}
//
//void Repository::FruitRepository::removeFruit(const Fruit &fruit) {
//    //This function removes a fruit from the repository
//    auto iterator = std::find(fruits->begin(), fruits->end(), fruit);
//    if(iterator != fruits->end()) {
//        fruits->erase(iterator);
//    }
//}
//
//
//void Repository::FruitRepository::updateFruit(Fruit &fruit) {
//    //This function updates a fruit from the repository
//    auto iterator = std::find(fruits->begin(), fruits->end(), fruit);
//    if(iterator != fruits->end()) {
//        *iterator = fruit;
//    }
//}
//
//shared_ptr<list<Fruit>> Repository::FruitRepository::getAllFruits() const {
//    //This function returns all the fruits from the repository
//    return fruits;
//}
//
//void Repository::FruitRepository::deleteAllFruits() {
////This function deletes all the fruits from the data base file
//    fruits->clear();
//    writeFruitsToFile();
//}
//
//
//void Repository::FruitRepository::writeFruitsToFile() const {
//    std::ofstream file(filename, std::ios::trunc);
//
//    string dataBase{};
//
//    for(auto &fruit : *fruits) {
//        dataBase += fruit.toString() + "\n";
//    }
//
//}
//
//Entity::Fruit Repository::FruitRepository::convertFromString(const std::string &fruit) {
//    std::stringstream ss(fruit);
//
//    string name, origin, expiry_date, producer;
//
//    int quantity;
//    double price;
//    char delimiter;
//
//    std::getline(ss, name, ',');
//    std::getline(ss, origin, ',');
//    std::getline(ss, producer, ',');
//    std::getline(ss, expiry_date, ',');
//    ss >> quantity >> delimiter >> price;
//
//    std::
//
//}





