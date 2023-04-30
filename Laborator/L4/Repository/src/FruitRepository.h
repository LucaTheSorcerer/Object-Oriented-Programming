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
#include "../../Entity/src/Fruit.h"

using std::shared_ptr, std::list, std::string, Entity::Fruit;


namespace Repository {
    class FruitRepository {

    private:
        string filename;

        shared_ptr<list<Fruit>> fruits{};

        //function that converts a fruit to a string


    public:

        //Constructor with filename for database
        explicit FruitRepository(string filename_ = "Repository/Data/DataBase.txt");

        //Copy constructor
        FruitRepository(const FruitRepository &fruitRepository) = default;

        //Assignment operator

        FruitRepository &operator=(const FruitRepository &fruitRepository) = default;


        //Destructor
        ~FruitRepository() = default;


        //function that adds a fruit to the list
        void addFruit(const Fruit &fruit);

        //function that removes a fruit from the list
        void removeFruit(const Fruit &fruit);

        //function that updates a fruit from the list
        void updateFruit(Fruit &fruit);

        //function that returns all fruits
        shared_ptr<list<Fruit>> getAllFruits() const;

        //function that writes the fruits to the file
        void writeFruitsToFile() const;

        //function that deletes all fruits
        void deleteAllFruits();

        //function that converts a fruit to a string
        static string convertToString(const Fruit &fruit);

        //function that converts the data from the file to a string
        static Fruit convertFromString(const string &fruit);

    };
}

