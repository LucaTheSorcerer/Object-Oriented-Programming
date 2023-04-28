//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <memory>
#include <list>
#include <string>
#include <utility>
#include "../Entity/Fruit.h"

using std::shared_ptr, std::list, std::string, Entity::Fruit;


namespace Repository {
    class FruitRepository {

    private:
        string filename;

        shared_ptr<list<Fruit>> fruits;

        //function that converts a fruit to a string

        static string convertToString(const Fruit &fruit);

        //function that converts the data from the file to a fruit

        static Fruit convertFromString(const string &fruit);

    public:
        FruitRepository();
        //constructor with a filename

        explicit FruitRepository(const string &filename);

        FruitRepository(const FruitRepository &other) = delete;

        FruitRepository &operator=(const FruitRepository &other) = delete;

        ~FruitRepository() = default;

        void addFruit(const Fruit &fruit);

        void removeFruit(const Fruit &fruit);

        shared_ptr<list<Fruit>> getAllFruits() const;

        //function that writes the fruits to the file
        void writeFruitsToFile() const;


    };
}

