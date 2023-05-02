#include "TestAll.h"
#include "UI.h"

using namespace UI;

int main() {
    testAll();

    ConsoleUI userInterface;
    userInterface.run();
}