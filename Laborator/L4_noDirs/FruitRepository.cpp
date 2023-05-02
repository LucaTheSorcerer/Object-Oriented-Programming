#include <algorithm>
#include "FruitRepository.h"

using Exception::FruitException;

/**
 * @brief Constructor for the FruitRepository class
 * @details Create a FruitRepository object. If the file does not exist, it will be created. If the file cannot be
 * created, an exception will be thrown. If the file is empty, the data will be initialized with an empty vector. If
 * the file is not empty, the data will be initialized with the data from the file.
 * @param _fileName
 */
Repository::FruitRepository::FruitRepository(string _fileName) : fileName(std::move(_fileName)) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw Exception::FruitException("Failed to create database file: " + fileName);
    }

    data = std::make_shared<vector<Fruit>>();

    string line;
    while (std::getline(file, line)) {
        Fruit fruit = convertFromString(line);
        data->push_back(fruit);
    }

    file.close();
}


/**
 * @brief Add a fruit to the data
 * @details Add a fruit to the data.
 * @param fruit
 */
void Repository::FruitRepository::writeToDataBase() {
    std::ofstream file(fileName, std::ios::trunc);

    string fileData{};
    for (auto it = data->begin(); it != data->end(); ++it) {
        fileData += (it->getFruitAsFormattedString());
        if (it != data->end() - 1) {
            fileData += '\n';
        }
    }

    file << fileData;

    file.close();
}

/**
 * @brief add a fruit to the data base
 * @param fruit
 */
void Repository::FruitRepository::addFruit(const Fruit &fruit) {
    data->push_back(fruit);
}

/**
 * @brief delete a fruit from the data base
 * @param fruit
 */
void Repository::FruitRepository::deleteFruit(const Fruit &fruit) {
    auto it = std::find_if(data->begin(), data->end(), [&](const Fruit& f){
        return f.getName() == fruit.getName();
    });
    if (it != data->end()) {
        data->erase(it);
    }
}

/**
 * @brief get all the data from the data base
 * @return
 */
shared_ptr<vector<Fruit>> Repository::FruitRepository::getAll() {
    return data;
}

/**
 * @brief delete all the data from the data base
 */
void Repository::FruitRepository::deleteData() {
    data = std::make_unique<vector<Fruit>>();
}

/**
 * @brief convert a string to a fruit
 * @param fruit
 * @return a fruit object
 */
Entity::Fruit Repository::FruitRepository::convertFromString(const string &fruit) {
    std::stringstream ss(fruit);
    string name, origin, producer, expDateStr;
    int quantity;
    float price;
    char delim;

    std::getline(ss, name, ',');
    std::getline(ss, origin, ',');
    std::getline(ss, producer, ',');
    std::getline(ss, expDateStr, ',');
    ss >> quantity >> delim >> price;

    // Parse the expiration date string to a Date object
    std::istringstream iss(expDateStr);
    int year, month, day;
    iss >> year >> delim >> month >> delim >> day;
    Time::Date expirationDate(year, month, day);

    return Entity::Fruit(name, origin, producer, expirationDate, quantity, price);
}

/**
 * @brief convert a fruit to a string
 * @param fruit
 * @return a string object
 */
string Repository::FruitRepository::convertToString(Fruit &fruit) {
    return fruit.getFruitAsFormattedString();
}