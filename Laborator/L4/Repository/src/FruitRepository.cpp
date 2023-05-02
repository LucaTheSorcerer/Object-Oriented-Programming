//
// Created by Luca Tudor on 13.04.2023.
//

#include "FruitRepository.h"
#include "../../Exception/src/FruitException.h"


Repository::FruitRepository::FruitRepository(string filename_) : filename(std::move(filename_)) {
     std::ifstream file(filename);

     //check is file is not opened correctly
    if (!file.is_open()) {
        throw FruitException("File could not be opened!");
    }

    fruits = std::make_shared<vector<Fruit>>();
    //read from file
    string line;
    while (getline(file, line)) {
        Fruit fruit = convertFromString(line);
        fruits->push_back(fruit);
    }

    file.close();
}

void Repository::FruitRepository::addFruit(const Fruit &fruit) {
    fruits->push_back(fruit);
}

void Repository::FruitRepository::removeFruit(const Fruit &fruit) {
    auto iterator = std::find_if(fruits->begin(), fruits->end(), [&](const Fruit &f) {
        return f == fruit;
    });
    if (iterator != fruits->end()) {
        fruits->erase(iterator);
    }
}

shared_ptr<vector<Fruit>> Repository::FruitRepository::getAllFruits(){
    return fruits;
}

void Repository::FruitRepository::writeFruitsToFile() const {

    std::ofstream file(filename, std::ios::trunc);

    string fileData{};
    for (auto it = fruits->begin(); it != fruits->end(); ++it) {
        fileData += (it->getFruitAsString());
        if (it != fruits->end() - 1) {
            fileData += '\n';
        }
    }

    file << fileData;

    file.close();
}

void Repository::FruitRepository::deleteAllFruits() {
    fruits = std::make_unique<vector<Fruit>>();
}

string Repository::FruitRepository::convertToString(Fruit &fruit) {
    return fruit.getFruitAsString();
}

Fruit Repository::FruitRepository::convertFromString(const string &fruit) {

    std::stringstream stream(fruit);
    string name, origin, producer, expiry_date;
    int quantity;
    double price;
    char delimiter;

    getline(stream, name, ',');
    getline(stream, origin, ',');
    getline(stream, producer, ',');
    getline(stream, expiry_date, ',');
    stream >> quantity >> delimiter >> price;

    //Expiration date string to a Date object
    std::istringstream date_stream(expiry_date);
    int year, month, day;
    date_stream >> year >> delimiter >> month >> delimiter >> day;
    Time::Date expiration_date(year, month, day);

    return Entity::Fruit(name, origin, producer, expiration_date, quantity, price);
}

