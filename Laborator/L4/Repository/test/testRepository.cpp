//
// Created by Luca Tudor on 01.05.2023.
//

#include "testRepository.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::string;

void testConvertFromString() {

    std::string fruitString = "Apple,USA,Red Del,2023-05-01,10,1.50";
    Fruit fruit = Repository::FruitRepository::convertFromString(fruitString);
    assert(fruit.getName() == "Apple");
    assert(fruit.getOrigin() == "USA");
    assert(fruit.getProducer() == "Red Del");
    assert(fruit.getExpiryDate().getDateAsString() == "2023-5-1");
    assert(fruit.getQuantity() == 10);
    assert(fruit.getPrice() == 1.5f);

    // Test convertToString()
    string expectedFruitString = "Apple,USA,Red Del,2023-5-1,10,1.50";
    string actualFruitString = Repository::FruitRepository::convertToString(fruit);

    assert(actualFruitString == expectedFruitString);
}


void testConstructor() {
    //Try creating an invalid fruit Repository
//    try {
//        Repository::FruitRepository fruitRepository("invalid");
//        assert(false);
//    } catch (const std::runtime_error &exception) {
//        assert(true);
//    }

    {
        //Create a repository with no data
        Repository::FruitRepository fruitRepository("../Repository/Data/DataTestEmpty");
        assert(fruitRepository.getAllFruits()->empty());
    }

    {
        //Create a valid repository
        Repository::FruitRepository fruitRepository("../Repository/Data/DataBaseTestRepo1.txt");
        Fruit expectedFruit1("Apple", "USA", "Apple Inc.",
                             Time::Date(2023, 5, 1), 10, 1.0);
        Fruit expectedFruit2("Banana", "Ecuador", "Fruit Co.",
                             Time::Date(2023, 4, 30), 5, 2.0);


        assert(fruitRepository.getAllFruits()->size() == 2);
        assert(fruitRepository.getAllFruits()->front() == expectedFruit1);
        assert(fruitRepository.getAllFruits()->back() == expectedFruit2);
    }
}

void testAddAndDeleteFruits() {

    cout << "testAddAndDeleteFruits" << endl;
    // Create a new repository
    Repository::FruitRepository fruitRepo("../Repository/Data/DataTestEmpty");

    // Create some sample fruits
    Entity::Fruit apple("Apple", "USA", "Apple Inc.",
                        Time::Date(2023, 5, 1), 10, 1);
    Entity::Fruit banana("Banana", "Ecuador", "Fruit Co.",
                         Time::Date(2023, 4, 30), 5, 2);
    Entity::Fruit kiwi("Kiwi", "New Zealand", "Kiwi Farms",
                       Time::Date(2023, 5, 10), 15, 3);

    // Add the first fruit to the repository
    fruitRepo.addFruit(apple);

    // Check that the fruit was added
    auto allFruits = fruitRepo.getAllFruits();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == apple);

    // Add the second fruit to the repository
    fruitRepo.addFruit(banana);

    // Check that both fruits were added
    allFruits = fruitRepo.getAllFruits();
    assert(allFruits->size() == 2);
    assert(allFruits->at(0) == apple);
    assert(allFruits->at(1) == banana);

    // Delete the first fruit from the repository
    fruitRepo.removeFruit(apple);

    // Check that the fruit was deleted
    allFruits = fruitRepo.getAllFruits();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == banana);

    // Delete the second fruit from the repository
    fruitRepo.removeFruit(banana);

    // Check that the repository is empty
    allFruits = fruitRepo.getAllFruits();
    assert(allFruits->empty());

    // Add a new fruit and then delete it
    fruitRepo.addFruit(kiwi);
    allFruits = fruitRepo.getAllFruits();
    assert(allFruits->size() == 1);
    assert(allFruits->at(0) == kiwi);

    fruitRepo.removeFruit(kiwi);
    allFruits = fruitRepo.getAllFruits();
    assert(allFruits->empty());

    cout << "testAddAndDeleteFruits passed" << endl;
}


void testDeleteData() {

    cout << "testDeleteData" << std::endl;
    Repository::FruitRepository fruitRepository("../Repository/Data/DataBaseTestRepo2.txt");
    fruitRepository.deleteAllFruits();
    assert(fruitRepository.getAllFruits()->empty());
    cout << "testDeleteData passed" << std::endl;
}

void testWriteToDataBase() {

    cout << "testWriteToDataBase" << std::endl;
    Repository::FruitRepository repo("../Repository/Data/DataBaseTestRepo3.txt");
    repo.deleteAllFruits();

    repo.addFruit(Entity::Fruit("Apple", "Romania", "Ion",
                                Time::Date(2023, 5, 1), 10, 1));
    repo.addFruit(Entity::Fruit("Orange", "Africa", "Jamal",
                                Time::Date(2023, 4, 30), 5, 2));
    repo.writeFruitsToFile();

    std::ifstream file("../Repository/Data/DataBaseTestRepo3.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContents = buffer.str();
    file.close();

    std::string expectedOutput = "Apple,Romania,Ion,2023-5-1,10,1.00\nOrange,Africa,Jamal,2023-4-30,5,2.00";
    assert(fileContents == expectedOutput);

    cout << "testWriteToDataBase passed" << std::endl;
}

void testRepository() {
    testConvertFromString();
    testConstructor();
    testAddAndDeleteFruits();
    testDeleteData();
    testWriteToDataBase();
}

