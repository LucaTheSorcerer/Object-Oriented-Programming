#pragma once

#include "Domain.h"
#include "Repository.h"
#include "Time.h"
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using Domain::Fruit, Repository::FruitRepository, Time::Date, std::vector, std::shared_ptr, std::string, std::unique_ptr;

namespace ControllerFruit {
    class Controller {
    private:
        FruitRepository fruitRepository; // an instance of fruit repository
        shared_ptr<vector<Fruit>> fruits; // all the fruits in the programme

    public:
        ///Constructor
        explicit Controller(const string &fileName = "../DataBase");

        ///Copy constructor
        Controller(const Controller &fruitController) = default;

        ///Assignment operator
        Controller &operator=(const Controller &fruitController) = default;

        ///Destructor
        ~Controller() = default;

        ///Data Manipulation
        void addFruit(const string &name, const string &origin, const string &producer, const Time::Date &expiryDate,
                      int quantity, float price);
        void deleteFruit(const string &name, const string &origin);
        void saveData();
        unique_ptr<vector<Fruit>> getAllFruits();
        unique_ptr<vector<Fruit>> getFruitsByExpirationDate();
        unique_ptr<vector<Fruit>> getLowQuantityFruits(int quantityThreshold);
        unique_ptr<vector<Fruit>> findFruits(const string &searchString);
    };
}