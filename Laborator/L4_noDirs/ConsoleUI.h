#pragma once

#include "Time.h"
#include "Entity.h"
#include "Controller.h"

using Time::Date;
using Entity::Fruit;
using Controller::FruitController;

namespace UI{
    class ConsoleUI{
    private:
        FruitController controller{};

    public:
        //Runs the program
        void run();

        //Constructor
        ConsoleUI() = default;

        //Copy constructor
        ConsoleUI(const ConsoleUI &userInterface) = default;

        //Destructor
        ~ConsoleUI() = default;

    private:
        //Display the user interface menu
        static void printMenu();

        //Manipulate data and display it if needed

        //Add a product to the database
        void addProduct();

        //Remove a product from the database
        void removeProduct();

        //Search for a fruit by name and origin
        void searchFruitByString();

        //Find fruits that are short in quantity
        void findFruitsShortInQuantity();

        //Find all fruits sorted by their expiration date
        void findAllFruitsSortedByExpirationDate();
    };
}

