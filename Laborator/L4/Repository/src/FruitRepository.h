//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <memory>
#include <list>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include "../../Entity/src/Entity.h"

using std::shared_ptr, std::string, Entity::Fruit, std::vector;


namespace Repository {
    class FruitRepository {

    private:
        string filename{};

        shared_ptr<vector<Fruit>> fruits{};


    public:

        //Constructor with filename for database
        explicit FruitRepository(string filename_ = "Repository/Data/DataBase.txt");

        //Copy constructor
        FruitRepository(const FruitRepository &fruitRepository) = default;

        //Assignment operator

        FruitRepository &operator=(const FruitRepository &fruitRepository) = default;


        //Destructor
        ~FruitRepository() = default;


        void addFruit(const Fruit &fruit);
        void removeFruit(const Fruit &fruit);
        void deleteAllFruits();
        [[nodiscard]] shared_ptr<vector<Fruit>> getAllFruits();
        void writeFruitsToFile() const;
        static string convertToString(Fruit &fruit);
        static Fruit convertFromString(const string &fruit);

    };
}

