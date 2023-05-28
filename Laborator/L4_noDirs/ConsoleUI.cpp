#include "ConsoleUI.h"
#include <iostream>

using std::cin, std::cout;

/**
 * @details Display the menu and run the program until the user chooses to exit.
 *
 */
void UI::ConsoleUI::run() {
    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                cout << "Exiting program...\n";
                controller.saveData();
                break;
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                searchFruitByString();
                break;
            case 4:
                findFruitsShortInQuantity();
                break;
            case 5:
                findAllFruitsSortedByExpirationDate();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


/**
 * @details Display the menu of the fruit store management system.
 */
void UI::ConsoleUI::printMenu() {
    cout << "\n\n";
    cout << "\nFruit Store Management System\n\n"
         << "What would you like to do?\n\n"
         << "1. Add a fruit\n"
         << "2. Remove a fruit\n"
         << "3. Search for fruit by name\n"
         << "4. Find the fruits with a quantity less than a given number\n"
         << "5. Find all the fruits sorted by their expiration date\n"
         << "0. Exit\n\n"
         << "Enter your choice: ";
}

///Add a user given product to the Data Base
void UI::ConsoleUI::addProduct() {
    std::string userInput;
    std::string name, origin, producer;
    int quantity, year, month, day;
    float price;

    std::cout << "Enter the name of the fruit: ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> name;

    std::cout << "Enter the origin of the fruit: ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> origin;

    std::cout << "Enter the producer of the fruit: ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> producer;

    std::cout << "Enter the price of the fruit: ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> price;

    std::cout << "Enter the quantity of the fruit: ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> quantity;

    std::cout << "Enter product expiration date (yyyy-mm-dd): ";
    std::getline(std::cin, userInput);
    std::stringstream(userInput) >> year >> month >> day;

    while (year < 2023 || year > 2043 || month < 1 || month > 12 || day < 1 || day > Date::daysInMonth(year, month)) {
        std::cout << "Invalid date. Please enter a valid expiration date (year month day): ";
        std::getline(std::cin, userInput);
        std::stringstream(userInput) >> year >> month >> day;
    }

    std::cout << '\n';
    Date expirationDate(year, month, day);

    try {
        controller.addFruit(name, origin, producer, expirationDate, quantity, price);
        std::cout << "Fruit added successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * @details Remove a product from the Data Base
 */
void UI::ConsoleUI::removeProduct() {
    std::string name, origin;

    std::cout << "Enter the name of the fruit: ";
    std::getline(std::cin, name);

    std::cout << "Enter the origin of the fruit: ";
    std::getline(std::cin, origin);

    try {
        controller.deleteFruit(name, origin);
        std::cout << "Fruit removed successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * @details Display all products that contain a given string in their name. The user gives the string. If no products
 * are found, an error message is displayed. If products are found, they are displayed.
 */
void UI::ConsoleUI::searchFruitByString() {
    std::string name;

    std::cout << "Enter search name: ";
    std::getline(std::cin, name);

    try {
        auto fruits = controller.findFruitsContainingString(name);
        cout << "The fruits that contain the string " << name << " are: " << endl;
        for (const auto &fruit: *fruits) {
            std::cout << fruit.getName() << ", " << fruit.getOrigin() << ", " << fruit.getProducer() << ", "
                      << fruit.getExpirationDate().getDateAsFormattedString() << ", " << fruit.getQuantity() << ", "
                      << fruit.getPrice() << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * @details Display all products that have a quantity less than a given number. The user gives the number. If no
 * products are found, an error message is displayed. If products are found, they are displayed.
 */
void UI::ConsoleUI::findFruitsShortInQuantity() {
    int quantity;

    std::cout << "Enter quantity threshold: ";
    std::cin >> quantity;

    try {
        auto fruits = controller.findFruitsWithLowStock(quantity);
        cout << "The fruits with a quantity less than " << quantity << " are: " << endl;
        for (const auto &fruit: *fruits) {
            std::cout << fruit.getName() << ", " << fruit.getOrigin() << ", " << fruit.getProducer() << ", "
                      << fruit.getExpirationDate().getDateAsFormattedString() << ", " << fruit.getQuantity() << ", "
                      << fruit.getPrice() << std::endl;
        }
    }
    catch (Exception::FruitException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * @details Display all products sorted by their expiration date.
 */
void UI::ConsoleUI::findAllFruitsSortedByExpirationDate() {
    auto fruits = controller.getFruitsSortedByExpirationDate();
    cout << "The fruits sorted by their expiration date are: " << endl;
    for (const auto &fruit: *fruits) {
        std::cout << fruit.getName() << ", " << fruit.getOrigin() << ", " << fruit.getProducer() << ", "
                  << fruit.getExpirationDate().getDateAsFormattedString() << ", " << fruit.getQuantity() << ", "
                  << fruit.getPrice() << std::endl;
    }
}