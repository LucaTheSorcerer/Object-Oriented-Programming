//
// Created by Luca Tudor on 06.04.2023.
//
#include "Test.h"
#include <iostream>
using namespace std;

Test::Test() {
    std::cout << "Constructor of Test" << std::endl;
}

Test::~Test() {
    std::cout << "Destructor of Test" << std::endl;
}

void Test::check() {
    cout << "Causing a problem" << endl;
    throw exception();
}
