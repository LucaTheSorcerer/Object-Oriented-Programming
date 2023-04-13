//
// Created by Luca Tudor on 13.04.2023.
//

#include "../Controller/controller.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class ConsoleUI {
    private:
    Controller& controller;
    static void printMenu();
    void addFruit();
    void updateFruit();
    void removeFruit();
    void listFruits();
    void searchFruit();
    void getLowStockFruit();
    void getExpiredFruit();
    void getFruitByOrigin();
    void getFruitByExpiryDate();
    void getFruitByPrice();
    void getFruitByQuantity();
    void getFruitByPriceAndQuantity();
    void getFruitsSortedByExpiryDate();

public:
    explicit ConsoleUI(Controller& controller);
    void start();

    char readInput();

    void executeChoice(char choice);

    void run();
};

