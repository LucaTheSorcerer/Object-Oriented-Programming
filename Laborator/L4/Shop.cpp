#include <iostream>
#include "Console/src/UI.h"
#include "Test/testAllComponents.h"
#include <memory>
#include <list>

using namespace UI;


//This is the main function that will be executed when the program starts and runs our fruit shop
int main() {
    //Running tests first
    testAllComponents();

    ConsoleUI consoleUI{};
    consoleUI.run();
    return 0;
}
