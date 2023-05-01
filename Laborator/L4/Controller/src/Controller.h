//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <utility>
#include <algorithm>

#include "../../Entity/src/Entity.h"
#include "../../Repository/src/FruitRepository.h"
#include "../../Date/src/Date/Date.h"

using namespace std;

using Entity::Fruit, Repository::FruitRepository, Time::Date, std::list, std::shared_ptr, std::string, std::unique_ptr;

namespace ControllerFruit {
    class Controller {
    private:
        FruitRepository repositoryFruit;
        shared_ptr<vector<Fruit>> fruits;
    public:
        //Constructor
        explicit Controller(const string &filename = "Repository/Data/DataBase.txt");

        //Coopy constructor

        Controller(const Controller &controller) = default;

        //Assignment operator

        Controller &operator=(const Controller &controller) = default;

        //Destructor

        ~Controller() = default;


        void addFruit(const string &name, const string &origin, const string &producer, const Time::Date &expiry_date,
                      int quantity, double price);

        void removeFruit(const string &name, const string &origin);

        unique_ptr<vector<Fruit>> getAllFruits();

        unique_ptr<vector<Fruit>> findFruitsContainingString(const string &search_string);

        unique_ptr<vector<Fruit>> findFruitsWithLowStock(int threshold);

        unique_ptr<vector<Fruit>> getFruitSortedByExpiry();

        void printAllFruits();
    };
}