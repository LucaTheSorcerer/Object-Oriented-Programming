//
// Created by Luca Tudor on 13.04.2023.
//
#include <fstream>
#include <sstream>
#include <iostream>
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

void FruitRepository::addFruit(const shared_ptr<Fruit> &fruit) {
    for (auto& f : fruits) {
        if (f->getName() == fruit->getName() && f->getOrigin() == fruit->getOrigin()) {
            f->setQuantity(f->getQuantity() + fruit->getQuantity());
            return;
        }
    }
    fruits.push_back(fruit);
}

void FruitRepository::removeFruit(const shared_ptr<Fruit> &fruit) {
    //This function removes a fruit from the repository
    for (auto it = fruits.begin(); it != fruits.end(); ++it) {
        if ((*it)->getName() == fruit->getName() && (*it)->getOrigin() == fruit->getOrigin()) {
            fruits.erase(it);
            return;
        }
    }
}


void FruitRepository::updateFruit(shared_ptr<Fruit> &fruit) {
    //This function updates a fruit from the repository
    for(auto &i : fruits) {
        if(i->getName() == fruit->getName() && i->getOrigin() == fruit->getOrigin()) {
            i = fruit;
        }
    }
}



//list<shared_ptr<Fruit>> FruitRepository::getFruitContainingString(const string& search_string) const {
//    //This function searches for a fruit in the repository
//    list<shared_ptr<Fruit>> search_results;
//    for(const auto &fruit : fruits) {
//        if(fruit->getName() == search_string || fruit->getOrigin() == search_string) {
//            search_results.push_back(fruit);
//        }
//    }
//
//    return search_results;
//}

list<shared_ptr<Fruit>> FruitRepository::getFruitContainingString(const string &name) const{
    std::list<std::shared_ptr<Fruit>> result;
    for (auto& f : fruits) {
        if (f->getName().find(name) != std::string::npos) {
            result.push_back(f);
        }
    }
    result.sort([](const std::shared_ptr<Fruit>& f1, const std::shared_ptr<Fruit>& f2) { return f1->getName() < f2->getName(); });
    return result;
}

std::list<std::shared_ptr<Fruit>> FruitRepository::getLowQuantityFruits(int threshold) const  {
    std::list<std::shared_ptr<Fruit>> result;
    for (auto& f : fruits) {
        if (f->getQuantity() < threshold) {
            result.push_back(f);
        }
    }
    result.sort([](std::shared_ptr<Fruit> f1, std::shared_ptr<Fruit> f2) { return f1->getName() < f2->getName(); });
    return result;
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



void FruitRepository::printFruits() const {
    //This function prints the fruits from the repository to the user

    for(const auto &fruit : fruits) {
        cout << fruit->getName() << " " << fruit->getOrigin() << " " << fruit->getExpiryDate() << " " << fruit->getPrice() << " " << fruit->getQuantity() << endl;
    }

}

list<shared_ptr<Fruit>> FruitRepository::getFruitsSortedByExpiryDate() const {
    //This function sorts the fruits from the repository by expiry date

    list<shared_ptr<Fruit>> sorted_fruits = fruits;
    sorted_fruits.sort([](const shared_ptr<Fruit> &fruit1, const shared_ptr<Fruit> &fruit2) {
        return fruit1->getExpiryDate() < fruit2->getExpiryDate();
    });

    return sorted_fruits;
}







