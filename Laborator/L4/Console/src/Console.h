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

namespace UI {
    class [[maybe_unused]] ConsoleUI {
    private:
        static ControllerFruit::Controller &controller;

        static int readInput();

        static void executeChoice(int choice);


    public:
        static void run();

        static void searchFruitString();

        static void findFruitShortInQuantity();

        static void findAllFruitsSortedByExpiration();

        static void printAllFruits();

        static void printMenu();

        static void addFruit();

        static void removeFruit();

        static void updateFruit();

    };
}
