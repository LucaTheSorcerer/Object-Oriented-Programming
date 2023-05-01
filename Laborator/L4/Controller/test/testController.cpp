//
// Created by Luca Tudor on 30.04.2023.
//

#include "testController.h"
#include <cassert>
#include <vector>
#include <iostream>

using std::cout, std::endl;

void testConstructorController() {

    //Test with an empty file
    {
        cout << "Test with an empty file" << endl;
        Controller controller("../Repository/Data/DataTestEmpty.txt");
        assert(controller.getAllFruits()->empty());

    }

    //Test with a data base that has values
    {
        cout << "Test with a data base that has values" << endl;
        Controller controller("../Repository/Data/DataTestValid.txt");
        assert(controller.getAllFruits()->size() == 2);
        assert(controller.getAllFruits()->front() == Fruit("Apple", "Romania"));
        assert(controller.getAllFruits()->back() == Fruit("Banana", "Germany"));
    }
}

void testController() {
    cout << "Testing Controller..." << endl;
    testConstructorController();
    cout << "Controller tested successfully!" << endl;
}