//
// Created by Luca Tudor on 13.04.2023.
//

#include "../Controller/controller.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using Entity::Fruit;

namespace UI {
    class ConsoleUI {
    private:
        Controller &controller;

        static void printMenu();

        static void addFruit();

        static void removeFruit();

        static void updateFruit();

        static void searchFruitString();

        static void findFruitShortInQuantity();

        static void findAllFruitsSortedByExpiration();

        static void printAllFruits();


    public:
        explicit ConsoleUI(Controller &controller);


        static int readInput();

        void executeChoice(int choice);

        void run();
    };
}
