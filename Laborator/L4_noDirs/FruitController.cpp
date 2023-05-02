#include "FruitController.h"

using Exception::FruitException;

/**
 * Constructor for the FruitController class
 * @param fruitRepository  The repository that will be used
 * @param fileName  The name of the file that will be used
 */
Controller::FruitController::FruitController(const string &fileName) : fruitRepository(fileName) {
    fruits = fruitRepository.getAll();
}

/**
 * Add a fruit to the Data Base
 * @details Add a fruit to the Data Base. If the fruit already exists, update it. If the fruit does not exist, add it.
 * @param name name of the fruit
 * @param origin origin of the fruit
 * @param producer producer of the fruit
 * @param expiryDate expiry date of the fruit
 * @param quantity quantity of the fruit
 * @param price price of the fruit
 */
void Controller::FruitController::addFruit(const string &name, const string &origin, const string &producer,
                                           const Time::Date &expiryDate, int quantity, float price) {
    Fruit newFruit(name, origin, producer, expiryDate, quantity, price);
    bool exists = false;

    //If the fruit already exists update it
    for (auto &it: *fruits) {
        if (it == newFruit) {
            it.setQuantity(it.getQuantity() + newFruit.getQuantity());
            exists = true;

            float oldPrice = it.getPrice();
            int oldQuantity = it.getQuantity() - newFruit.getQuantity();
            float newPrice = newFruit.getPrice();
            int newQuantity = newFruit.getQuantity();
            float avgPrice = (oldPrice * float(oldQuantity) + newPrice * float(newQuantity)) /
                             float((oldQuantity + newQuantity)); //calculate the median price
            it.setPrice(avgPrice);

            // Update expiry date to the closest one
            if (it.getExpirationDate() > newFruit.getExpirationDate()) {
                it.setExpirationDate(expiryDate);
            }
            break;
        }
    }

    if (!exists) {
        fruitRepository.addFruit(newFruit);
    }
}


/**
 * @brief Delete a fruit from the Data Base
 * @details Delete a fruit from the Data Base. If the fruit does not exist, throw an exception.
 * @param name
 * @param origin
 */
void Controller::FruitController::deleteFruit(const string& name, const string& origin) {
    Fruit tempFruit(name, origin);
    bool found = false;
    for (auto &it : *fruits) {
        if (it == tempFruit) {
            fruitRepository.deleteFruit(it);
            found = true;
            break;
        }
    }
    if (!found) {
        throw FruitException("Fruit not found");
    }
}

///Get all the fruits from the dataBase
unique_ptr<vector<Fruit>> Controller::FruitController::getAllFruits() {
    auto sortedFruits = std::make_unique<vector<Fruit>>(*fruits);
    std::sort(sortedFruits->begin(), sortedFruits->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );
    return sortedFruits;
}

///Get all the fruits sorted by their expiry date
unique_ptr<vector<Fruit>> Controller::FruitController::getFruitsByExpirationDate() {
    auto sortedFruits = std::make_unique<vector<Fruit>>(*fruits);
    std::sort(sortedFruits->begin(), sortedFruits->end(), [](const Fruit &a, const Fruit &b) {
        return a.getExpirationDate() < b.getExpirationDate();
    });
    return sortedFruits;
}
///Get all the fruits that are in low quantity
///@throws runtime_error if the threshold is invalid
unique_ptr<vector<Fruit>> Controller::FruitController::getLowQuantityFruits(int quantityThreshold) {
    if(quantityThreshold <= 0){
        throw FruitException("Threshold must be positive");
    }

    auto lowQuantityFruits = std::make_unique<vector<Fruit>>();
    for (auto &it : *fruits) {
        if (it.getQuantity() < quantityThreshold) {
            lowQuantityFruits->push_back(it);
        }
    }
    return lowQuantityFruits;
}

///Find all the fruits that match a given string
unique_ptr<vector<Fruit>> Controller::FruitController::findFruits(const string &searchString) {
    auto result = std::make_unique<vector<Fruit>>();

    if (searchString.empty())
        return getAllFruits();

    for (const auto &it: *fruits) {
        if (it.getName().find(searchString) != std::string::npos ||
            it.getOrigin().find(searchString) != std::string::npos)
            result->push_back(it);
    }

    std::sort(result->begin(), result->end(),
              [](const Fruit &a, const Fruit &b) -> bool {
                  return a.getName() < b.getName();
              }
    );

    return result;
}

///Save the data to the DataBase
void Controller::FruitController::saveData() {
    fruitRepository.writeToDataBase();
}