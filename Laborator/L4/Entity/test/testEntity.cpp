//
// Created by Luca Tudor on 30.04.2023.
//

#include <iostream>
#include "../../Entity/test/testEntity.h"

using std::cout;
using std::endl;

void testDefaultConstructor() {

    cout << "Testing default constructor..." << endl;

    Fruit orange("Orange");
    assert(orange.getName() == "Orange");
    assert(orange.getOrigin() == "Romania");
    assert(orange.getProducer() == "Gicu de la Craiova");
    assert(orange.getExpiryDate().getYear() == 2024);
    assert(orange.getExpiryDate().getMonth() == 1);
    assert(orange.getExpiryDate().getDay() == 1);
    assert(orange.getQuantity() == 1);
    assert(orange.getPrice() == 1);
}

void testCopyConstructor() {

    cout << "Testing copy constructor..." << endl;

    Fruit watermelon("Watermelon", "Dabuleni", "Ion", Date(2019, 9, 11), 100, 40);
    Fruit watermelonCopy(watermelon);

    assert(watermelonCopy.getName() == "Watermelon");
    assert(watermelonCopy.getOrigin() == "Dabuleni");
    assert(watermelonCopy.getProducer() == "Ion");
    assert(watermelonCopy.getExpiryDate().getYear() == 2019);
    assert(watermelonCopy.getExpiryDate().getMonth() == 9);
    assert(watermelonCopy.getExpiryDate().getDay() == 11);
    assert(watermelonCopy.getQuantity() == 100);
    assert(watermelonCopy.getPrice() == 40);

    //Modify the copied object and check if the original object remained the same

    watermelonCopy.setName("WatermelonCopy");
    watermelonCopy.setOrigin("DabuleniCopy");
    watermelonCopy.setProducer("IonCopy");
    watermelonCopy.setExpiryDate(Date(2019, 9, 12));
    watermelonCopy.setQuantity(101);
    watermelonCopy.setPrice(41);

    assert(watermelon.getName() == "Watermelon");
    assert(watermelon.getOrigin() == "Dabuleni");
    assert(watermelon.getProducer() == "Ion");
    assert(watermelon.getExpiryDate().getYear() == 2019);
    assert(watermelon.getExpiryDate().getMonth() == 9);
    assert(watermelon.getExpiryDate().getDay() == 11);
    assert(watermelon.getQuantity() == 100);
    assert(watermelon.getPrice() == 40);
}

void testDefaultParameters() {

    cout << "Testing default parameters..." << endl;

    Fruit apple("Apple", "Italy");
    assert(apple.getName() == "Apple");
    assert(apple.getOrigin() == "Italy");
    assert(apple.getProducer() == "Gicu de la Craiova");
    assert(apple.getExpiryDate().getYear() == 2024);
    assert(apple.getExpiryDate().getMonth() == 1);
    assert(apple.getExpiryDate().getDay() == 1);
    assert(apple.getQuantity() == 1);
    assert(apple.getPrice() == 1);
}

void testExtendedEntity() {

    cout << "Testing extended entity..." << endl;

    //Test the getters
    {
        Fruit orange("Orange", "Romania", "Gicu de la Craiova", Date(2024, 1, 1), 1, 1);
        assert(orange.getName() == "Orange");
        assert(orange.getOrigin() == "Romania");
        assert(orange.getProducer() == "Gicu de la Craiova");
        assert(orange.getExpiryDate().getYear() == 2024);
        assert(orange.getExpiryDate().getMonth() == 1);
        assert(orange.getExpiryDate().getDay() == 1);
        assert(orange.getQuantity() == 1);
        assert(orange.getPrice() == 1);
    }

    //Test the setters
    {
        Fruit orange("Orange", "Romania", "Gicu de la Craiova", Date(2024, 1, 1), 1, 1);
        orange.setName("OrangeCopy");
        orange.setOrigin("RomaniaCopy");
        orange.setProducer("Gicu de la CraiovaCopy");
        orange.setExpiryDate(Date(2025, 1, 1));
        orange.setQuantity(2);
        orange.setPrice(2);

        assert(orange.getName() == "OrangeCopy");
        assert(orange.getOrigin() == "RomaniaCopy");
        assert(orange.getProducer() == "Gicu de la CraiovaCopy");
        assert(orange.getExpiryDate().getYear() == 2025);
        assert(orange.getExpiryDate().getMonth() == 1);
        assert(orange.getExpiryDate().getDay() == 1);
        assert(orange.getQuantity() == 2);
        assert(orange.getPrice() == 2);
    }

    //Test the copy constructor
    {
        Fruit orange("Orange", "Romania", "Gicu de la Craiova", Date(2024, 1, 1), 1, 1);
        Fruit orangeCopy(orange);
        assert(orangeCopy.getName() == "Orange");
        assert(orangeCopy.getOrigin() == "Romania");
        assert(orangeCopy.getProducer() == "Gicu de la Craiova");
        assert(orangeCopy.getExpiryDate().getYear() == 2024);
        assert(orangeCopy.getExpiryDate().getMonth() == 1);
        assert(orangeCopy.getExpiryDate().getDay() == 1);
        assert(orangeCopy.getQuantity() == 1);
        assert(orangeCopy.getPrice() == 1);
    }

    //Test the assignment operator
    {
        Fruit orange("Orange", "Romania", "Gicu de la Craiova", Date(2024, 1, 1), 1, 1);
        Fruit orangeCopy2 = orange;
        assert(orangeCopy2.getName() == "Orange");
        assert(orangeCopy2.getOrigin() == "Romania");
        assert(orangeCopy2.getProducer() == "Gicu de la Craiova");
        assert(orangeCopy2.getExpiryDate().getYear() == 2024);
        assert(orangeCopy2.getExpiryDate().getMonth() == 1);
        assert(orangeCopy2.getExpiryDate().getDay() == 1);
        assert(orangeCopy2.getQuantity() == 1);
        assert(orangeCopy2.getPrice() == 1);
    }

    //Test the equality operator
    {
        Fruit apple1("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit apple2("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        assert(apple1 == apple2);
        assert(apple2 == apple1);

    }

    //Test the inequalty operator
    {
        Fruit apple1("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit orange1("Orange", "Spain", "Carlos", Date(1980, 2, 10), 50, 10);
        assert(apple1 != orange1);
        assert(orange1 != apple1);

    }

    //Test the less than operator
    {
        Fruit apple("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit orange("Orange", "Spain", "Carlos", Date(1980, 2, 10), 50, 10);
        assert(orange < apple);
    }

    //Test the greater than operator
    {
        Fruit apple("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit orange("Orange", "Spain", "Carlos", Date(1980, 2, 10), 50, 10);
        assert(apple > orange);
    }

    //Test the less than or equal operator
    {
        Fruit apple1("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit apple2("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit orange("Orange", "Spain", "Carlos", Date(1980, 2, 10), 50, 10);
        assert(apple1 <= apple2);
        assert(orange <= apple1);
    }

    //Test the greater than or equal operator
    {
        Fruit apple1("Apple", "Romania", "Ion", Date(2003, 9, 11), 200, 45);
        Fruit apple2("Apple", "Romania", "Ion", Date(2003, 9, 11), 100, 40);
        Fruit orange("Orange", "Spain", "Carlos", Date(1980, 2, 10), 50, 10);
        assert(apple1 >= apple2);
        assert(apple1 >= orange);
    }

    //Test the getFruitAsString function with full parameters
    {
        Entity::Fruit apple("Apple", "Romania", "Ion", Time::Date(2003, 9, 11), 100, 40.00);
        assert(apple.getName() == "Apple");
        assert(apple.getOrigin() == "Romania");
        assert(apple.getProducer() == "Ion");
        assert(apple.getExpiryDate().getYear() == 2003);
        assert(apple.getExpiryDate().getMonth() == 9);
        assert(apple.getExpiryDate().getDay() == 11);
        assert(apple.getQuantity() == 100);
        assert(apple.getPrice() == 40.00);
        string appleString = apple.getFruitAsString();
        assert(appleString == "Apple,Romania,Ion,2003-9-11,100,40.00");
    }

    //Test the getFruitAsString function without the name parameter

    {
        Entity::Fruit apple("", "Romania", "Ion", Time::Date(2003, 9, 11), 100, 40.00);
        assert(apple.getName().empty());
        assert(apple.getOrigin() == "Romania");
        assert(apple.getProducer() == "Ion");
        assert(apple.getExpiryDate().getYear() == 2003);
        assert(apple.getExpiryDate().getMonth() == 9);
        assert(apple.getExpiryDate().getDay() == 11);
        assert(apple.getQuantity() == 100);
        assert(apple.getPrice() == 40.00);
        string appleString = apple.getFruitAsString();
        assert(appleString == ",Romania,Ion,2003-9-11,100,40.00");
    }

    //Test the getFruitAsString function without more parameters

    {
        Entity::Fruit apple("", "", "", Time::Date(2003, 9, 11), 100, 40.00);
        assert(apple.getName().empty());
        assert(apple.getOrigin().empty());
        assert(apple.getProducer().empty());
        assert(apple.getExpiryDate().getYear() == 2003);
        assert(apple.getExpiryDate().getMonth() == 9);
        assert(apple.getExpiryDate().getDay() == 11);
        assert(apple.getQuantity() == 100);
        assert(apple.getPrice() == 40.00);
        string appleString = apple.getFruitAsString();
        assert(appleString == ",,,2003-9-11,100,40.00");
    }

}

void testEntity() {
    testDefaultConstructor();
    testCopyConstructor();
    testDefaultParameters();
    testExtendedEntity();
    std::cout << "All Entity tests passed!" << std::endl;
}