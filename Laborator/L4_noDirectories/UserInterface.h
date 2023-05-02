#pragma once

#include "Time.h"
#include "Entity.h"
#include "ControllerFruit.h"

using Time::Date;
using Entity::Fruit;
using ControllerFruit::Controller;

namespace UI{
    class UserInterface{
    private:
        Controller controller{};

    public:
        ///Run the programme
        void run();

        ///Constructor
        UserInterface() = default;

        ///Copy constructor
        UserInterface(const UserInterface &userInterface) = default;

        ///Destructor
        ~UserInterface() = default;

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

