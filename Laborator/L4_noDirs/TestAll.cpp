#include "TestAll.h"
#include <iostream>

void testAll(){
    std::cout << "Testing all..." << std::endl;
    testTime();
    testDomain();
    testRepository();
    testController();
    std::cout << "All tests passed!" << std::endl;
}