#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <utility>
#include "Entity.h"
#include "FruitException.h"

using std::string, std::shared_ptr, std::vector, Entity::Fruit;

namespace Repository{
    class FruitRepository{
    private:
        string fileName{};
        shared_ptr<vector<Fruit>> data{};

    public:
        ///Constructor
        explicit FruitRepository(string _fileName = "../DataBase");

        ///Copy constructor
        FruitRepository(const FruitRepository &fruitRepository) = default;

        ///Assignment operator
        FruitRepository &operator=(const FruitRepository &other) = default;

        ///Destructor
        ~FruitRepository() = default;

        ///Data interactions
        void addFruit(const Fruit &fruit);
        void deleteFruit(const Fruit &fruit);
        void deleteData();
        shared_ptr<vector<Fruit>> getAll();

        ///Update the DataBase
        void writeToDataBase();

        ///Convert the data to a string
        static string convertToString(Fruit &fruit);

        ///Convert a Fruit to a string
        static Fruit convertFromString(const string &fruit);
    };
}