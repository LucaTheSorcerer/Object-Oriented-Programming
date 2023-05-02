//
// Created by Luca Tudor on 13.04.2023.
//

#include "../../Controller/src/Controller.h"
#include "../../Entity/src/Entity.h"
#include "../../Date/src/Date/Date.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using Entity::Fruit;
using Time::Date;
using ControllerFruit::Controller;

namespace UI {
    class ConsoleUI {
    private:
        Controller controller{};

         int readInput();

         void executeChoice(int choice);

         void printMenu();

         void searchFruitString();

         void findFruitShortInQuantity();

         void findAllFruitsSortedByExpiration();

         void printAllFruits();


         void addFruit();

         void removeFruit();

         void updateFruit();


    public:
        void run();

        //Constructor
        ConsoleUI() = default;

        //Copy constructor

        ConsoleUI(const ConsoleUI &consoleUI) = default;

        //Destructor
        ~ConsoleUI() = default;

    };
}
