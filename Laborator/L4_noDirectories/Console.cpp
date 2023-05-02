//
// Created by Luca Tudor on 13.04.2023.
//
#include "Console.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

#include "../../Exception/src/FruitException.h"

using std::cin, std::cout, std::endl;

void UI::ConsoleUI::run() {
    int choice;
    do {
        printMenu();
        choice = readInput();
        executeChoice(choice);
    }
    while (choice != 0);
}


int UI::ConsoleUI::readInput() {
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void UI::ConsoleUI::executeChoice(int choice) {
    //This function executes the choice of the user
    switch (choice) {
        case 0:
            cout << "The program is exiting!\n" << endl;
            break;
        case 1:
            addFruit();
            break;
        case 2:
            removeFruit();
            break;
        case 3:
            searchFruitString();
            break;
        case 4:
            findFruitShortInQuantity();
            break;
        case 5:
            findAllFruitsSortedByExpiration();
            break;
        case 6:
            printAllFruits();
            break;
        default:
            cout << "Invalid choice! Please try again! \n" << endl;
            break;
    }

}

void UI::ConsoleUI::printMenu() {
    //This function prints a beautiful menu

    cout << "\n\n";
    cout << "Welcome to the fruit shop!" << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << "1. Add a fruit" << endl;
    cout << "2. Remove a fruit" << endl;
    cout << "3. Search for a fruit by name" << endl;
    cout << "4. Find the fruits with a quantity less than a given number" << endl;
    cout << "5. Find all the fruits sorted by their expiration date" << endl;
    cout << "6. Print all the fruits" << endl;
    cout << "q. Exit" << endl;
    cout << "Enter your choice: ";
}


void UI::ConsoleUI::addFruit() {
    string name, origin, expiry_date, producer, userInput;
    int price, quantity, year, month, day;

    cout << "\nEnter the name of the fruit: ";
    getline(cin, userInput);
    stringstream(userInput) >> name;

    cout << "Enter the origin of the fruit: ";
    getline(cin, userInput);
    stringstream(userInput) >> origin;

    cout << "Enter the producer of the product: ";
    getline(cin, userInput);
    stringstream(userInput) >> producer;

    cout << "Enter the quantity of the fruit: ";
    getline(cin, userInput);
    stringstream(userInput) >> quantity;

    cout << "Enter the price of the fruit: ";
    getline(cin, userInput);
    stringstream(userInput) >> price;

    cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
    getline(cin, userInput);
    stringstream(userInput) >> year >> month >> day;

    //Add the fruit
    //A while loop that checks if the expiry date is valid
    while(year < 2023 || year > 2050 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "Invalid date! Please try again!" << endl;
        cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
        getline(cin, userInput);
        stringstream(userInput) >> year >> month >> day;
    }

    cout << "\n";

    //Create the expiry date
    Date expiryDate(year, month, day);

    try {
        controller.addFruit(name, origin, producer, expiryDate, quantity, price);
        cout << "Fruit added successfully!" << endl;
    } catch (FruitException& e) {
        cout << "Error: " << e.what() << endl;
    }
}


void UI::ConsoleUI::removeFruit() {
    string name;
    string origin;


    cout << "\nEnter the name of the fruit: ";
    getline(cin, name);

    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);


    //Remove the fruit
    try {
        controller.removeFruit(name, origin);
        cout << "Fruit removed successfully!" << endl;
    } catch (FruitException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void UI::ConsoleUI::searchFruitString() {
    //This function searches for a fruit by its given name

    string searchString;

    cout << "\nEnter the name of the fruit: ";
    getline(cin, searchString);

    try {
        auto fruits = controller.findFruitsContainingString(searchString);
        cout << "The fruits that contain the string " << searchString << " are: " << endl;
        for(const auto &fruit : *fruits) {
            cout << fruit.getName() << ", "
                 << fruit.getOrigin() << ", "
                 << fruit.getProducer() << ", "
                 << fruit.getExpiryDate().getDateAsString() << ", "
                 << fruit.getQuantity() << ", "
                 << fruit.getPrice() << endl;
        }
    } catch (FruitException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void UI::ConsoleUI::findFruitShortInQuantity() {
    //This function finds the fruits with a quantity less than a given number
    int quantity;
    cout << "\nEnter the quantity: ";
    cin >> quantity;

    try {
        auto fruits = controller.findFruitsWithLowStock(quantity);
        cout << "The fruits with a quantity less than " << quantity << " are: " << endl;
        for(const auto &fruit : *fruits) {
            cout << fruit.getName() << ", "
                 << fruit.getOrigin() << ", "
                 << fruit.getProducer() << ", "
                 << fruit.getExpiryDate().getDateAsString() << ", "
                 << fruit.getQuantity() << ", "
                 << fruit.getPrice() << endl;
        }
    } catch (FruitException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void UI::ConsoleUI::findAllFruitsSortedByExpiration() {
    //This function finds all the fruits sorted by their expiration date and gets a current date

    auto fruits = controller.getFruitSortedByExpiry();
    cout << "The fruits sorted by their expiration date are: " << endl;
    for(const auto &fruit : *fruits) {
        cout << fruit.getName() << ", "
             << fruit.getOrigin() << ", "
             << fruit.getProducer() << ", "
             << fruit.getExpiryDate().getDateAsString() << ", "
             << fruit.getQuantity() << ", "
             << fruit.getPrice() << endl;
    }
}


void UI::ConsoleUI::printAllFruits() {
    //This function prints all the fruits
    return controller.printAllFruits();
}








