#include <iostream>

#include "CreationalPattern/Singleton/Logger.h"
#include "CreationalPattern/FactoryMethod/runGame.h"
#include "BehaviouralPatterns/Strategy/shopping.h"
#include "BehaviouralPatterns/Observer/weather_station.h"



//Two functions to check if the singleton works correctly

void printLoggerMessage() {
    std::shared_ptr<Logger> logger = Logger::getInstance("Hello Logger1");
    std::cout << logger->getMessage() << std::endl;
    logger->debug("Debug message");
}

void printLoggerMessage2() {
    std::shared_ptr<Logger> logger = Logger::getInstance("Hello Logger2");
    std::cout << logger->getMessage() << std::endl;
    logger->info("Info message");
}

int main() {
    printLoggerMessage();
    printLoggerMessage2();

    runGame();
    std::cout << std::endl;
    shoppingCart();
    std::cout << std::endl;
    weatherStation();
    return 0;
}
