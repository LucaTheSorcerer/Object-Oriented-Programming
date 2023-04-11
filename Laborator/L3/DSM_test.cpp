//
// Created by Luca Tudor on 05.04.2023.
//
#include "DSM.h"
#include <iostream>
#include <string>
#include <cassert>
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

void testGetName() {
    //Test the getName function
    cout << "Testing the getName function..." << endl;
    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};

    DSM<int> DSM1(elementNames, 11);
    assert(DSM1.getName(0) == "Display");
    assert(DSM1.getName(1) == "Battery");
    assert(DSM1.getName(2) == "Processor");
    assert(DSM1.getName(3) == "Memory");
    assert(DSM1.getName(4) == "Camera");
    assert(DSM1.getName(5) == "Speakers");
    assert(DSM1.getName(6) == "Microphone");
    assert(DSM1.getName(7) == "SIM Card");
    assert(DSM1.getName(8) == "Antenna");
    assert(DSM1.getName(9) == "Charging Port");
    assert(DSM1.getName(10) == "Buttons");

    cout << "All tests passed!" << endl;
}

void testSetElementName() {
    //Test the setElementName function
    cout << "Testing the setElementName function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};

    DSM<int> DSM1(elementNames, 11);
    DSM1.setElementName(0, "Display1");
    DSM1.setElementName(1, "Battery1");
    DSM1.setElementName(2, "Processor1");
    DSM1.setElementName(3, "Memory1");
    DSM1.setElementName(4, "Camera1");
    DSM1.setElementName(5, "Speakers1");
    DSM1.setElementName(6, "Microphone1");
    DSM1.setElementName(7, "SIM Card1");
    DSM1.setElementName(8, "Antenna1");
    DSM1.setElementName(9, "Charging Port1");
    DSM1.setElementName(10, "Buttons1");

    assert(DSM1.getName(0) == "Display1");
    assert(DSM1.getName(1) == "Battery1");
    assert(DSM1.getName(2) == "Processor1");
    assert(DSM1.getName(3) == "Memory1");
    assert(DSM1.getName(4) == "Camera1");
    assert(DSM1.getName(5) == "Speakers1");
    assert(DSM1.getName(6) == "Microphone1");
    assert(DSM1.getName(7) == "SIM Card1");
    assert(DSM1.getName(8) == "Antenna1");
    assert(DSM1.getName(9) == "Charging Port1");
    assert(DSM1.getName(10) == "Buttons1");

    cout << "All tests passed!" << endl;
}

void testAddLink() {
    //Test the addLink function
    cout << "Testing the addLink function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};

    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);
    DSM1.addLink("Display", "Microphone", 6);
    DSM1.addLink("Display", "SIM Card", 7);
    DSM1.addLink("Display", "Antenna", 8);
    DSM1.addLink("Display", "Charging Port", 9);
    DSM1.addLink("Display", "Buttons", 10);

    assert(DSM1.linkWeight("Display", "Battery") == 1);
    assert(DSM1.linkWeight("Display", "Processor") == 2);
    assert(DSM1.linkWeight("Display", "Memory") == 3);
    assert(DSM1.linkWeight("Display", "Camera") == 4);
    assert(DSM1.linkWeight("Display", "Speakers") == 5);
    assert(DSM1.linkWeight("Display", "Microphone") == 6);
    assert(DSM1.linkWeight("Display", "SIM Card") == 7);
    assert(DSM1.linkWeight("Display", "Antenna") == 8);
    assert(DSM1.linkWeight("Display", "Charging Port") == 9);
    assert(DSM1.linkWeight("Display", "Buttons") == 10);

    cout << "All tests passed!" << endl;
}

void testDeleteLink() {
    //Test the DeleteLink function
    cout << "Testing the DeleteLink function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);
    DSM1.addLink("Display", "Microphone", 6);
    DSM1.addLink("Display", "SIM Card", 7);
    DSM1.addLink("Display", "Antenna", 8);
    DSM1.addLink("Display", "Charging Port", 9);
    DSM1.addLink("Display", "Buttons", 10);

    DSM1.deleteLink("Display", "Battery");
    DSM1.deleteLink("Display", "Processor");
    DSM1.deleteLink("Display", "Memory");
    DSM1.deleteLink("Display", "Camera");
    DSM1.deleteLink("Display", "Speakers");
    DSM1.deleteLink("Display", "Microphone");
    DSM1.deleteLink("Display", "SIM Card");
    DSM1.deleteLink("Display", "Antenna");
    DSM1.deleteLink("Display", "Charging Port");
    DSM1.deleteLink("Display", "Buttons");

    assert(DSM1.linkWeight("Display", "Battery") == 0);
    assert(DSM1.linkWeight("Display", "Processor") == 0);
    assert(DSM1.linkWeight("Display", "Memory") == 0);
    assert(DSM1.linkWeight("Display", "Camera") == 0);
    assert(DSM1.linkWeight("Display", "Speakers") == 0);
    assert(DSM1.linkWeight("Display", "Microphone") == 0);
    assert(DSM1.linkWeight("Display", "SIM Card") == 0);
    assert(DSM1.linkWeight("Display", "Antenna") == 0);
    assert(DSM1.linkWeight("Display", "Charging Port") == 0);
    assert(DSM1.linkWeight("Display", "Buttons") == 0);

    cout << "All tests passed!" << endl;
}

void testResizeElements() {
    //Test the resizeElements function
    cout << "Testing the resizeElements function..." << endl;

    DSM<int> DSM1(11);
    DSM1.setElementName(0, "Display");
    DSM1.setElementName(1, "Battery");
    DSM1.setElementName(2, "Processor");
    DSM1.setElementName(3, "Memory");
    DSM1.setElementName(4, "Camera");
    DSM1.setElementName(5, "Speakers");
    DSM1.setElementName(6, "Microphone");
    DSM1.setElementName(7, "SIM Card");
    DSM1.setElementName(8, "Antenna");
    DSM1.setElementName(9, "Charging Port");
    DSM1.setElementName(10, "Buttons");

    DSM1.resizeElements(20);
    assert(DSM1.getCapacity() == 20);
    assert(DSM1.size() == 11);
    assert(DSM1.getName(0) == "Display");
    assert(DSM1.getName(1) == "Battery");
    assert(DSM1.getName(2) == "Processor");
    assert(DSM1.getName(3) == "Memory");
    assert(DSM1.getName(4) == "Camera");
    assert(DSM1.getName(5) == "Speakers");
    assert(DSM1.getName(6) == "Microphone");
    assert(DSM1.getName(7) == "SIM Card");
    assert(DSM1.getName(8) == "Antenna");
    assert(DSM1.getName(9) == "Charging Port");
    assert(DSM1.getName(10) == "Buttons");

//    //Test resizing to a smaller size
//    try {
//        DSM1.resizeElements(5);
//        assert(false);
//    } catch(const std::out_of_range& e) {
//        assert(string(e.what()) == "The new size is smaller than the current size");
//    }
//
//    //Test resizing to the same size
//    try {
//        DSM1.resizeElements(20);
//        assert(false);
//    } catch(const std::out_of_range& e) {
//        assert(string(e.what()) == "The new size is the same as the current size");
//    }

    cout << "All tests passed!" << endl;
}

void testHasLink() {
    //This function tests the function hasLink()
    cout << "Testing the hasLink function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);
    DSM1.addLink("Display", "Microphone", 6);
    DSM1.addLink("Display", "SIM Card", 7);
    DSM1.addLink("Display", "Antenna", 8);
    DSM1.addLink("Display", "Charging Port", 9);
    DSM1.addLink("Display", "Buttons", 10);

    assert(DSM1.hasLink("Display", "Battery") == true);
    assert(DSM1.hasLink("Display", "Processor") == true);
    assert(DSM1.hasLink("Display", "Memory") == true);
    assert(DSM1.hasLink("Display", "Camera") == true);
    assert(DSM1.hasLink("Display", "Speakers") == true);
    assert(DSM1.hasLink("Display", "Microphone") == true);
    assert(DSM1.hasLink("Display", "SIM Card") == true);
    assert(DSM1.hasLink("Display", "Antenna") == true);
    assert(DSM1.hasLink("Display", "Charging Port") == true);
    assert(DSM1.hasLink("Display", "Buttons") == true);
    assert(DSM1.hasLink("Display", "Display") == false);


    cout << "All tests passed!" << endl;
}

void testCountAllLinks() {
    //This function tests the function countAllLinks()
    cout << "Testing the countAllLinks function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);
    DSM1.addLink("Display", "Microphone", 6);
    DSM1.addLink("Display", "SIM Card", 7);
    DSM1.addLink("Display", "Antenna", 8);
    DSM1.addLink("Display", "Charging Port", 9);
    DSM1.addLink("Display", "Buttons", 10);

    assert(DSM1.countAllLinks() == 10);

    cout << "All tests passed!" << endl;
}

void testCountFromLinks() {
    //This function tests the function countFromLinks()
    cout << "Testing the countFromLinks function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);
    DSM1.addLink("Display", "Microphone", 6);
    DSM1.addLink("Display", "SIM Card", 7);
    DSM1.addLink("Display", "Antenna", 8);
    DSM1.addLink("Display", "Charging Port", 9);
    DSM1.addLink("Display", "Buttons", 10);

    assert(DSM1.countFromLinks("Display") == 10);

    cout << "All tests passed!" << endl;
}

void testToLinks() {
    //This function tests the function countToLinks()
    cout << "Testing the countToLinks function..." << endl;

    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    DSM1.addLink("Display", "Battery", 1);
    DSM1.addLink("Display", "Processor", 2);
    DSM1.addLink("Display", "Memory", 3);
    DSM1.addLink("Display", "Camera", 4);
    DSM1.addLink("Display", "Speakers", 5);

    assert(DSM1.countToLinks("Display") == 0);

    cout << "All tests passed!" << endl;
}

void testHasElement() {
    //This function tests the function hasElement()
    cout << "Testing the hasElement function..." << endl;
    string elementNames[11] = {"Display", "Battery", "Processor", "Memory", "Camera", "Speakers",
                               "Microphone", "SIM Card", "Antenna", "Charging Port", "Buttons"};
    DSM<int> DSM1(elementNames, 11);
    assert(DSM1.hasElement("Display") == true);
    assert(DSM1.hasElement("Battery") == true);
    assert(DSM1.hasElement("Processor") == true);
    assert(DSM1.hasElement("Memory") == true);
    assert(DSM1.hasElement("Camera") == true);
    assert(DSM1.hasElement("Speakers") == true);
    assert(DSM1.hasElement("Microphone") == true);
    assert(DSM1.hasElement("SIM Card") == true);
    assert(DSM1.hasElement("Antenna") == true);
    assert(DSM1.hasElement("Charging Port") == true);
    assert(DSM1.hasElement("Buttons") == true);
    assert(DSM1.hasElement("Apple") == false);
    assert(DSM1.hasElement("Banana") == false);
    assert(DSM1.hasElement("Orange") == false);


    cout << "All tests passed!" << endl;
}

int main() {
    //the main function is only used for testing purposes
    testConstructors();
    testGetName();
    testSetElementName();
    testAddLink();
    testDeleteLink();
    testResizeElements();
    testHasLink();
    testCountAllLinks();
    testCountFromLinks();
    testToLinks();
    testHasElement();
    cout << "Test complete!" << endl;
    return 0;
}
