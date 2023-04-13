//
// Created by Luca Tudor on 13.04.2023.
//
#include "console.h"
#include "../Exception/FruitException.h"


ConsoleUI::ConsoleUI(Controller& controller): controller(controller) {}

void ConsoleUI::start() {
    this->run();
}

void ConsoleUI::printMenu() {
    cout << "a. Add fruit" << endl;
    cout << "b. Update fruit" << endl;
    cout << "c. Remove fruit" << endl;
    cout << "d. List all fruits" << endl;
    cout << "e. Search fruit" << endl;
    cout << "f. Get low stock fruit" << endl;
    cout << "g. Get expired fruit" << endl;
    cout << "h. Get fruit by origin" << endl;
    cout << "i. Get fruit by expiry date" << endl;
    cout << "j. Get fruit by price" << endl;
    cout << "k. Get fruit by quantity" << endl;
    cout << "l. Get fruit by price and quantity" << endl;
    cout << "m. Get fruits sorted by expiry date" << endl;
    cout << "q. Quit" << endl;
    cout << "Enter your choice: ";
}

void ConsoleUI::run() {
    char choice;
    do {
        this->printMenu();
        choice = readInput();
        executeChoice(choice);
    } while(choice != 'q');
}

char ConsoleUI::readInput() {
    char choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void ConsoleUI::executeChoice(char choice) {
    switch(choice) {
        case 'a':
            this->addFruit();
            break;
        case 'b':
            this->updateFruit();
            break;
        case 'c':
            this->removeFruit();
            break;
        case 'd':
            this->listFruits();
            break;
        case 'e':
            this->searchFruit();
            break;
        case 'f':
            this->getLowStockFruit();
            break;
        case 'g':
            this->getExpiredFruit();
            break;
        case 'h':
            this->getFruitByOrigin();
            break;
        case 'i':
            this->getFruitByExpiryDate();
            break;
        case 'j':
            this->getFruitByPrice();
            break;
        case 'k':
            this->getFruitByQuantity();
            break;
        case 'l':
            this->getFruitByPriceAndQuantity();
            break;
        case 'm':
            this->getFruitsSortedByExpiryDate();
            break;
        case 'q':
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

void ConsoleUI::addFruit() {
    string name, origin, expiry_date;
    int quantity;
    double price;

    cout << "\nEnter the name of the fruit: ";
    getline(cin, name);

    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);

    cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
    getline(cin, expiry_date);

    cout << "Enter the quantity of the fruit: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the price of the fruit: ";
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Add the fruit
    try {
        this->controller.addFruit(name, origin, expiry_date, quantity, price);
        cout << "Fruit added successfully!" << endl;
    } catch (FruitException& e) {
        cout << e.what() << endl;
    }
}

void ConsoleUI::updateFruit() {
    string name, origin, expiry_date;
    int quantity;
    double price;

    cout << "\nEnter the name of the fruit: ";
    getline(cin, name);

    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);

    cout << "Enter the expiry date of the fruit (yyyy-mm-dd): ";
    getline(cin, expiry_date);

    cout << "Enter the quantity of the fruit: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the price of the fruit: ";
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Update the fruit

    try {
        this->controller.updateFruit(name, origin, expiry_date, quantity, price);
        cout << "Fruit updated successfully!" << endl;
    } catch (FruitException& e) {
        cout << e.what() << endl;
    }
}

void ConsoleUI::removeFruit() {
    string name;
    string origin;


    cout << "\nEnter the name of the fruit: ";
    getline(cin, name);

    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);


    //Remove the fruit
    try {
        this->controller.removeFruit(name, origin);
        cout << "Fruit removed successfully!" << endl;
    } catch (FruitException& e) {
        cout << e.what() << endl;
    }
}

void ConsoleUI::listFruits() {
    //This function will list all the fruits

    list<shared_ptr<Fruit>> fruits = this->controller.getAllFruits();

    if (fruits.empty()) {
        cout << "There are no fruits in the repository!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}


void ConsoleUI::searchFruit() {
    string name;
    string origin;


    cout << "\nEnter the name of the fruit: ";
    getline(cin, name);

    cout << "Enter the origin of the fruit: ";
    getline(cin, origin);


    //We search the fruit by name and origin

    try {
        list<shared_ptr<Fruit>> fruit = this->controller.searchFruit(name);
        cout << fruit.front()->toString() << endl;
    } catch (FruitException& e) {
        cout << e.what() << endl;
    }
}

void ConsoleUI::getLowStockFruit() {
    //This function will list all the fruits with a quantity less than 10

    //We get the fruits with a quantity less than 10

    list<shared_ptr<Fruit>> fruits = this->controller.getLowStockFruit(10 );

    if (fruits.empty()) {
        cout << "There are no fruits with a quantity less than 10!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getExpiredFruit() {
    //This function will list all the fruits with an expiry date before the current date

    //We get the fruits with an expiry date before the current date and we have to give to the function
    //the current date that the user can choose

    list<shared_ptr<Fruit>> fruits = this->controller.getExpiredFruit( "2019-12-12");

    if (fruits.empty()) {
        cout << "There are no expired fruits!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitByOrigin() {
    string origin;

    cout << "\nEnter the origin of the fruit: ";
    getline(cin, origin);

    //We get the fruits by origin

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitByOrigin(origin);

    if (fruits.empty()) {
        cout << "There are no fruits with the origin " << origin << "!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitByExpiryDate() {
    string expiry_date;

    cout << "\nEnter the expiry date of the fruit (yyyy-mm-dd): ";
    getline(cin, expiry_date);

    //We get the fruits by expiry date

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitByExpiryDate(expiry_date);

    if (fruits.empty()) {
        cout << "There are no fruits with the expiry date " << expiry_date << "!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitByQuantity() {
    //This function will list all the fruits sorted by quantity

    //We get the fruits sorted by quantity

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitByQuantity();

    if (fruits.empty()) {
        cout << "There are no fruits in the repository!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitByPrice() {
    //This function will list all the fruits sorted by price

    //We get the fruits sorted by price

    //We get the fruits sorted by price but we assign a variable to the function getFruitByPrice() becaue we do not need
    //it to be a fixed value

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitByPrice(10.0);

    if (fruits.empty()) {
        cout << "There are no fruits in the repository!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitByPriceAndQuantity() {
    //This function will list all the fruits sorted by price and quantity

    //We get the fruits sorted by price and quantity

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitByPriceAndQuantity(10.0, 100);

    if (fruits.empty()) {
        cout << "There are no fruits in the repository!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}

void ConsoleUI::getFruitsSortedByExpiryDate() {
    //This function will list all the fruits sorted by expiry date

    //We get the fruits sorted by expiry date

    list<shared_ptr<Fruit>> fruits = this->controller.getFruitsSortedByExpiryDate();

    if (fruits.empty()) {
        cout << "There are no fruits in the repository!" << endl;
        return;
    }

    for (const auto& fruit : fruits) {
        cout << fruit->toString() << endl;
    }
}



