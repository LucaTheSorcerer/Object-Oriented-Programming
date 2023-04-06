//
// Created by Luca Tudor on 05.04.2023.
//
#include "DSM.h"
#include "DSM.cpp"
#include <iostream>
#include <string>
#include <cassert>
#include <gtest/gtest.h>
using namespace std;

//Test the constructors
void testConstructors() {
    cout << "Testing the constructors..." << endl;
    //Test the default constructor
    DSM<int> DSM1(11);

    assert(DSM1.size() == 11);
    assert(DSM1.getCapacity() == 23);

    //Test the constructor that also has the element names
    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};

    DSM<int> DSM2(elementNames, 11);
    assert(DSM2.size() == 11);
    assert(DSM2.getCapacity() == 23);

    //Test the copy constructor
    DSM<int> DSM3(DSM2);
    assert(DSM3.size() == 11);
    assert(DSM3.getCapacity() == 23);

    cout << "All tests passed!" << endl;
    cout << "--------------------------------" << endl;
}

//void testGetName() {
//    //Professionally written tests with Google Test
//    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
//                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
//
//
//}

int main() {
    //the main function is only used for testing purposes
    testConstructors();

    return 0;
}
