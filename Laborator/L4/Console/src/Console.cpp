////
//// Created by Luca Tudor on 13.04.2023.
////
//#include "Console.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//#include <sstream>
//
//#include "../../Exception/src/FruitException.h"
//
//using std::cin, std::cout, std::endl;
//
//void UI::ConsoleUI::run() {
//    int choice;
//    do {
//        printMenu();
//        choice = readInput();
//        executeChoice(choice);
//    }
//    while (choice != 0);
//}
//
//
//int UI::ConsoleUI::readInput() {
//    int choice;
//    cin >> choice;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    return choice;
//}
//
//void UI::ConsoleUI::executeChoice(int choice) {
//    //This function executes the choice of the user
//    switch (choice) {
//        case 0:
//            cout << "The program is ®exiting!\n" << endl;
//            break;
//        case 1:
//            UI::ConsoleUI::addFruit();
//            break;
//        case 2:
//            UI::ConsoleUI::removeFruit();
//            break;
//        case 3:
//            UI::ConsoleUI::updateFruit();
//            break;
//        case 4:
//            UI::ConsoleUI::searchFruitString();
//            break;
//        case 5:
//            UI::ConsoleUI::findFruitShortInQuantity();
//            break;
//        case 6:
//            UI::ConsoleUI::findAllFruitsSortedByExpiration();
//            break;
//        case 7:
//            UI::ConsoleUI::printAllFruits();
//            break;
//        default:
//            cout << "Invalid choice! Please try again! \n" << endl;
//    }
//
//}
//
//void UI::ConsoleUI::printMenu() {
//    //This function prints a beautiful menu
//
//    cout << "\n\n";
//    cout << "Welcome to the fruit shop!" << endl;
//    cout << "Please choose one of the following options:" << endl;
//    cout << "1. Add a fruit" << endl;
//    cout << "2. Remove a fruit" << endl;
//    cout << "3. Update a fruit" << endl;
//    cout << "4. Search for a fruit by name" << endl;
//    cout << "5. Find the fruits with a quantity less than a given number" << endl;
//    cout << "6. Find all the fruits sorted by their expiration date" << endl;
//    cout << "7. Print all the fruits" << endl;
//    cout << "q. Exit" << endl;
//    cout << "Enter your choice: ";
//}
//
//
//void UI::ConsoleUI::addFruit() {
//    string name, origin, expiry_date, producer;
//    int price, quantity, year, month, day;
//
//    cout << "\nEnter the name of the fruit: ";
//    cin >> name;
//
//    cout << "Enter the origin of the fruit: ";
//    cin >> origin;
//
//    cout << "Enter the producer of the product: ";
//    cin >> producer;
//
//    cout << "Enter the quantity of the fruit: ";
//    cin >> quantity;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    cout << "Enter the price of the fruit: ";
//    cin >> price;
//
//    //Ignore the newline character
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//
//    cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
//    cin >> year >> month >> day;
//
//
//
//    //Add the fruit
//    //A while loop that checks if the expiry date is valid
//    while(year < 2023 || year > 2050 || month < 1 || month > 12 || day < 1 || day > 31) {
//        cout << "Invalid date! Please try again!" << endl;
//        cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
//        cin >> year >> month >> day;
//    }
//
//    cout << "\n";
//
//    //Create the expiry date
//    Date expiryDate(year, month, day);
//    Fruit fruit(name, origin, producer, expiryDate, quantity, price);
//
//    try {
////        this->controller.addFruit(fruit);
//        cout << "Fruit added successfully!" << endl;
//    } catch (FruitException& e) {
//        cout << "Error: " << e.what() << endl;
//    }
//}
//
//void UI::ConsoleUI::updateFruit() {
//    std::string name, origin, producer;
//    int price, quantity, year, month, day;
//
//    std::cout << "Enter product name: ";
//    std::cin >> name;
//
//    std::cout << "Enter product origin: ";
//    std::cin >> origin;
//
//    std::cout << "Enter product producer: ";
//    std::cin >> producer;
//
//    std::cout << "Enter product price: ";
//    std::cin >> price;
//
//    std::cout << "Enter product quantity: ";
//    std::cin >> quantity;
//
//    std::cout << "Enter product expiration date (year month day): ";
//    std::cin >> year >> month >> day;
//
//    while (year < 2023 || year > 2043 || month < 1 || month > 12 || day < 1 || day > Time::Date::getNumberOfDaysInMonth(month, year)) {
//        std::cout << "Invalid date. Please enter a valid expiration date (year, month, day): ";
//        std::cin >> year >> month >> day;
//    }
//
//    std::cout << '\n';
//
//    Date expirationDate(year, month, day);
//    Fruit new_fruit(name, origin, producer, expirationDate, quantity, price);
//
//    try {
//
//        std::cout << "Product added successfully." << std::endl;
//    }
//    catch (std::exception &e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//}
//
//void UI::ConsoleUI::removeFruit() {
//    string name;
//    string origin;
//
//
//    cout << "\nEnter the name of the fruit: ";
//    getline(cin, name);
//
//    cout << "Enter the origin of the fruit: ";
//    getline(cin, origin);
//
//
//    //Remove the fruit
//    try {
//        controller.removeFruit(name, origin);
//        cout << "Fruit removed successfully!" << endl;
//    } catch (FruitException& e) {
//        cout << e.what() << endl;
//    }
//}
//
//void UI::ConsoleUI::searchFruitString() {
//    //This function searches for a fruit by its given name
//    string name;
//    cout << "\nEnter the name of the fruit: ";
//    getline(cin, name);
//
//    unique_ptr<vector<Entity::Fruit>> fruits = controller.findFruitsContainingString(name);
//}
//
//void UI::ConsoleUI::findFruitShortInQuantity() {
//    //This function finds the fruits with a quantity less than a given number
//    int quantity;
//    cout << "\nEnter the quantity: ";
//    cin >> quantity;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    unique_ptr<vector<Fruit>> fruits = controller.findFruitsWithLowStock(quantity);
//}
//
//void UI::ConsoleUI::findAllFruitsSortedByExpiration() {
//    //This function finds all the fruits sorted by their expiration date and gets a current date
//    unique_ptr<vector<Fruit>> fruits = controller.getFruitSortedByExpiry();
//}
//
//
//void UI::ConsoleUI::printAllFruits() {
//    //This function prints all the fruits
//    return controller.printAllFruits();
//}
//
//
//
//
//
//
//
//
