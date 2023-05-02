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
        ///Run the programme
        void run();

        ///Constructor
        ConsoleUI() = default;

        ///Copy constructor
        ConsoleUI(const ConsoleUI &userInterface) = default;

        ///Destructor
        ~ConsoleUI() = default;

    private:
        ///Display the UI menu
        static void displayMenu();

        ///Manipulate data and display it if needed
        void addProduct();
        void removeProduct();
        void displayProductsByString();
        void displayLowQuantityProducts();
        void displayProductsByExpirationDate();
    };
}

