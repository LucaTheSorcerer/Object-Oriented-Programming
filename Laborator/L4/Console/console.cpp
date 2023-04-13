//
// Created by Luca Tudor on 13.04.2023.
//
#include "console.h"


ConsoleUI::ConsoleUI(Controller& controller): controller(controller) {}

void ConsoleUI::start() {
    this->run();
}

void ConsoleUI::printMenu() {
    cout << "1. Add fruit" << endl;
    cout << "2. Update fruit" << endl;
    cout << "3. Remove fruit" << endl;
    cout << "4. List all fruits" << endl;
    cout << "5. Search fruit" << endl;
    cout << "6. Get low stock fruit" << endl;
    cout << "7. Get expired fruit" << endl;
    cout << "8. Get fruit by origin" << endl;
    cout << "9. Get fruit by expiry date" << endl;
    cout << "10. Get fruit by price" << endl;
    cout << "11. Get fruit by quantity" << endl;
    cout << "12. Get fruit by price and quantity" << endl;
    cout << "13. Get fruits sorted by expiry date" << endl;
    cout << "0. Exit" << endl;
}

void ConsoleUI::run() {
    while (true) {
        this->printMenu();
        int command;
        cout << "Enter command: ";
        cin >> command;
        cin.ignore();
        if (command == 0) {
            break;
        }
        switch (command) {
            case 1: {
                this->addFruit();
                break;
            }
            case 2: {
                this->updateFruit();
                break;
            }
            case 3: {
                this->removeFruit();
                break;
            }
            case 4: {
                this->listFruits();
                break;
            }
            case 5: {
                this->searchFruit();
                break;
            }
            case 6: {
                this->getLowStockFruit();
                break;
            }
            case 7: {
                this->getExpiredFruit();
                break;
            }
            case 8: {
                this->getFruitByOrigin();
                break;
            }
            case 9: {
                this->getFruitByExpiryDate();
                break;
            }
            case 10: {
                this->getFruitByPrice();
                break;
            }
            case 11: {
                this->getFruitByQuantity();
                break;
            }
            case 12: {
                this->getFruitByPriceAndQuantity();
                break;
            }
            case 13: {
                this->getFruitsSortedByExpiryDate();
                break;
            }
            default: {
                cout << "Invalid command!" << endl;
                break;
            }
        }
    }
}

void ConsoleUI::addFruit() {
    string name, origin, expiry_date;
    int quantity;
    double price;
    cout << "Enter the name of the fruit: ";
    getline(cin, name);
    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);
    cout << "Enter the expiry date of the fruit: ";
    getline(cin, expiry_date);
    cout << "Enter the quantity of the fruit: ";
    cin >> quantity;
    cout << "Enter the price of the fruit: ";
    cin >> price;
    try {
        this->controller.addFruit(name, origin, expiry_date, quantity, price);
    } catch (FruitException& exception) {
        cout << exception.what() << endl;
    }

}