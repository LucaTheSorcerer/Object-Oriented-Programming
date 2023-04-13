//
// Created by Luca Tudor on 13.04.2023.
//
#include <fstream>
#include <sstream>
#include "fruit_repository.h"

FruitRepository::FruitRepository() {
    //Generate some sample data for testing
    shared_ptr<Fruit> fruit1 = make_shared<Fruit>("Apple", "Romania", "2023-04-13", 10, 2.5);
    shared_ptr<Fruit> fruit2 = make_shared<Fruit>("Banana", "USA", "2023-04-13", 10, 5.5);
    shared_ptr<Fruit> fruit3 = make_shared<Fruit>("Orange", "Spain", "2023-04-13", 10, 3.5);
    shared_ptr<Fruit> fruit4 = make_shared<Fruit>("Pineapple", "Brazil", "2023-04-13", 10, 4.5);
    shared_ptr<Fruit> fruit5 = make_shared<Fruit>("Strawberry", "France", "2023-04-13", 10, 6.5);
    shared_ptr<Fruit> fruit6 = make_shared<Fruit>("Watermelon", "China", "2023-04-13", 10, 7.5);
    shared_ptr<Fruit> fruit7 = make_shared<Fruit>("Peach", "Italy", "2023-04-13", 10, 8.5);
    shared_ptr<Fruit> fruit8 = make_shared<Fruit>("Pear", "Germany", "2023-04-13", 10, 9.5);
}

//void FruitRepository::addOrUpdateFruit(shared_ptr<Fruit> &fruit) {
//    //this function adds or updates a fruit to the repository
//
//}

FruitRepository::FruitRepository(const string &file_name) {
    this->filename = file_name;
    loadFruits(file_name);
}

void FruitRepository::addFruit(shared_ptr<Fruit> &fruit) {
    fruits.push_back(fruit);
}

void FruitRepository::updateFruit(shared_ptr<Fruit> &fruit) {
    //This function updates a fruit from the repository
    for(auto &i : fruits) {
        if(i->getName() == fruit->getName() && i->getOrigin() == fruit->getOrigin()) {
            i = fruit;
        }
    }
}

list<shared_ptr<Fruit>> FruitRepository::getAllFruits() {
    //This function returns all the fruits from the repository
    return fruits;
}

list<shared_ptr<Fruit>> FruitRepository::searchFruit(const string& search_string) const {
    //This function searches for a fruit in the repository
    list<shared_ptr<Fruit>> search_results;
    for(const auto &fruit : fruits) {
        if(fruit->getName() == search_string || fruit->getOrigin() == search_string) {
            search_results.push_back(fruit);
        }
    }

    return search_results;
}

list<shared_ptr<Fruit>> FruitRepository::getLowStockFruit(int threshold) const {
    //This function returns all the fruits that have a quantity lower than the given threshhold
    list<shared_ptr<Fruit>> low_stock_fruits;
    for(const auto &fruit : fruits) {
        if(fruit->getQuantity() < threshold) {
            low_stock_fruits.push_back(fruit);
        }
    }

    return low_stock_fruits;
}

list<shared_ptr<Fruit>> FruitRepository:: getExpiredFruit(const string& current_date) {
    //This function returns all fruits that have an expiry date before the current date
    list<shared_ptr<Fruit>> expired_fruits;
    for(const auto &fruit : fruits) {
        if(fruit->getExpiryDate() < current_date) {
            expired_fruits.push_back(fruit);
        }
    }

    return expired_fruits;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitByOrigin(const string& origin) const {
    //This function returns all the fruits from the same given origin
    list<shared_ptr<Fruit>> fruits_by_origin;
    for(auto const &fruit : fruits) {
        if(fruit->getOrigin() == origin) {
            fruits_by_origin.push_back(fruit);
        }
    }

    return fruits_by_origin;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitByExpiryDate(const string& expiry_date) const {
    //This function returns all the fruits based on the given expiry date
    list<shared_ptr<Fruit>> fruits_by_expiry_date;
    for(auto const &fruit : fruits) {
        if(fruit->getExpiryDate() == expiry_date) {
            fruits_by_expiry_date.push_back(fruit);
        }
    }

    return fruits_by_expiry_date;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitByPrice(double price) const {
    //This function returns all the fruits based on the given price

    //First check if the given price is negative
    if(price < 0) {
        throw std::invalid_argument("The price cannot be negative!");
    }

    list<shared_ptr<Fruit>> fruits_by_price;
    for(auto const &fruit : fruits) {
        if(fruit->getPrice() == price) {
            fruits_by_price.push_back(fruit);
        }
    }

    return fruits_by_price;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitByQuantity(int quantity) const {
    //This function returns all the fruits based on the given quantity

    //First check if the given quantity is negative
    if(quantity < 0) {
        throw std::invalid_argument("The quantity cannot be negative!");
    }

    list<shared_ptr<Fruit>> fruits_by_quantity;
    for(auto const &fruit : fruits) {
        fruits_by_quantity.push_back(fruit);
    }

    return fruits_by_quantity;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitByPriceAndQuantity(double price, int quantity) const {
    //This function returns all the fruits based on the given price and quantity

    //First we check if the given price and quantity are negative

    if(price < 0 && quantity < 0) {
        throw std::invalid_argument("The price and quantity cannot be negative!");
    }

    if(price < 0) {
        throw std::invalid_argument("The price cannot be negative!");
    }

    if(quantity < 0) {
        throw std::invalid_argument("The quantity cannot be negative!");
    }


    list<shared_ptr<Fruit>> fruits_by_price_and_quantity;
    for(auto const &fruit : fruits) {
        if(fruit->getPrice() == price && fruit->getQuantity() == quantity) {
            fruits_by_price_and_quantity.push_back(fruit);
        }
    }


    return fruits_by_price_and_quantity;
}

list<shared_ptr<Fruit>> FruitRepository::getFruitsSortedByExpiryDate() const {
    //This function returns all the fruits sorted by expiry date using the sort function

    list<shared_ptr<Fruit>> sorted_fruits = fruits;
    sorted_fruits.sort([](const shared_ptr<Fruit> &fruit1, const shared_ptr<Fruit> &fruit2) {
        return fruit1->getExpiryDate() < fruit2->getExpiryDate();
    });

    return sorted_fruits;
}



void FruitRepository::removeFruit(const string &name, const string &origin) {
    //This function removes a fruit from the repository
    for(auto it = fruits.begin(); it != fruits.end(); it++) {
        if((*it)->getName() == name && (*it)->getOrigin() == origin) {
            fruits.erase(it);
            break;
        }
    }
}

void FruitRepository::saveFruits(const string& filename) {
    //This function saves the fruits from the repository to a file

    //First we open the file

    ofstream file(filename);
    if(!file.is_open()) {
        throw std::invalid_argument("The file could not be opened!");
    }

    //Then we write the fruits to the file

    for(const auto &fruit : fruits) {
        file << fruit->getName() << " " << fruit->getOrigin() << " " << fruit->getExpiryDate() << " " << fruit->getPrice() << " " << fruit->getQuantity() << endl;
    }

    file.close();


}

void FruitRepository::loadFruits(const string& filename) {
    //This function loads the fruits from a file to the repository

    //First we open the file

    ifstream file(filename);
    if(!file.is_open()) {
        throw std::invalid_argument("The file could not be opened!");
    }

    //We read the fruits from the file line by line

    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string name, origin, expiry_date;
        double price;
        int quantity;
        ss >> name >> origin >> expiry_date >> price >> quantity;
        fruits.push_back(make_shared<Fruit>(name, origin, expiry_date, price, quantity));
    }

    file.close();
}


