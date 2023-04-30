#include <iostream>
#include "Entity/src/Fruit.h"
#include "Test/testAllComponents.h"
#include <memory>
#include <list>



//This is the main function that will be executed when the program starts and runs our fruit shop
int main() {
    //Running tests first
    testAllComponents();
    std::cin.get();
    return 0;
}
