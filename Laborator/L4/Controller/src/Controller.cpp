////
//// Created by Luca Tudor on 13.04.2023.
////
//#include "Controller.h"
//
//Controller::Controller(FruitRepository& repository) : repository(repository) {}
//
//void Controller::addFruit(const string &name, const string &origin, const string &expiry_date, int quantity, double price) {
//    std::shared_ptr<Fruit> fruit = std::make_shared<Fruit>(name, origin, expiry_date, quantity, price);
//    repository.addFruit(fruit);
//}
//
//
//
//
//void Controller::removeFruit(const string &name, const string &origin) {
//std::shared_ptr<Fruit> fruit = std::make_shared<Fruit>(name, origin, "", 0, 0);
//    repository.removeFruit(fruit);
//
//}
//
//list<shared_ptr<Fruit>> Controller::searchFruit(const string &search_string) {
//    //This function searches for a fruit by a name given as arguemnt to the function
//
//    return repository.getFruitContainingString(search_string);
//
//}
//
//list<shared_ptr<Fruit>> Controller::getLowStockFruit(int threshold) {
//    //This function returns the low stock fruits from the repository
//
//    return repository.getLowQuantityFruits(threshold);
//}
//
//list<shared_ptr<Fruit>> Controller::getFruitSortedByExpiry() {
//    //This function returns the expired fruits from the repository
//
//    return repository.getFruitsSortedByExpiryDate();
//}
//
//void Controller::printAllFruits() {
//    //This function prints all the fruits from the repository
//
//    repository.printFruits();
//}
//
//
//
//
