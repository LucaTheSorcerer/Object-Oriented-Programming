//
// Created by Luca Tudor on 30.04.2023.
//

#include "testController.h"
#include <cassert>
#include <iostream>

using std::cout, std::endl;

void testControllerConstructor() {
    //Test empty Data Base
    {
        Controller fruitController("DataTestEmpty.txt");
        assert(fruitController.getAllFruits()->empty());
    }
    //Test valid Data Base
//    {
//        Controller fruitController("../Repository/Data/DataTestValid.txt");
//        assert(fruitController.getAllFruits()->size() == 2);
//        assert(fruitController.getAllFruits()->front() == Fruit("Apple", "USA"));
//        assert(fruitController.getAllFruits()->back() == Fruit("Banana", "Ecuador"));
//    }
}

void testController() {
    cout << "Testing Controller..." << endl;
    testControllerConstructor();
    cout << "Controller tested successfully!" << endl;
}