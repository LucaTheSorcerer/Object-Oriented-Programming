#include <iostream>
#include "Console/src/Console.h"
#include "Controller/src/Controller.h"
#include "Repository/src/FruitRepository.h"
#include "Entity/src/Fruit.h"
#include <memory>
#include <list>



//This is the main function that will be executed when the program starts and runs our fruit shop
int main() {
    //We create a new repository
    FruitRepository repository;
    //We create a new controller
    Controller controller(repository);
    //We create a new console from the console.h file

    ConsoleUI console(controller);

    //We run the console
    console.start();

    return 0;
}
