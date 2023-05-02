//
// Created by Luca Tudor on 30.04.2023.
//

#include <iostream>
#include "testDate.h"
#include "cassert"

using std::cout, std::endl;


void testShortDate() {

    cout << "Testing Short Date..." << endl;

    Time::Date date(2020, 1, 1);

    //test getters

    assert(date.getDay() == 1);
    assert(date.getMonth() == 1);
    assert(date.getYear() == 2020);

    //test setters

    date.setDay(2);
    date.setMonth(2);
    date.setYear(2021);

    assert(date.getDay() == 2);
    assert(date.getMonth() == 2);
    assert(date.getYear() == 2021);
}

void extendedDateTest() {

    cout << "Testing Extended Date..." << endl;

    Time::Date date(2020, 1, 1);

    //test getters

    assert(date.getDay() == 1);
    assert(date.getMonth() == 1);
    assert(date.getYear() == 2020);

    //test setters

    date.setDay(2);
    date.setMonth(2);
    date.setYear(2021);

    assert(date.getDay() == 2);
    assert(date.getMonth() == 2);
    assert(date.getYear() == 2021);

    //test safequards and setters

    try {
        date.setDay(0);
        assert(false);
    }
    catch (std::invalid_argument& e) {
        assert(true);
    }

    //test exceptions and invalid dates

    try {
        Time::Date date1(2020, 13, 1);
        assert(false);
    }
    catch (std::invalid_argument& e) {
        assert(true);
    }

}

void testCopyConstructorDate() {

        cout << "Testing Copy Constructor for the Date..." << endl;

        Time::Date date(2020, 1, 1);

        Time::Date date2(date);

        assert(date.getDay() == date2.getDay());
        assert(date.getMonth() == date2.getMonth());
        assert(date.getYear() == date2.getYear());

}

void testAssignmentOperator() {

    cout << "Testing Assignment Operator for the Date..." << endl;

    Time::Date date(2020, 1, 1);

    Time::Date date2 = date;

    assert(date.getDay() == date2.getDay());
    assert(date.getMonth() == date2.getMonth());
    assert(date.getYear() == date2.getYear());
}


void testConvertDateToString() {

    cout << "Testing Convert Date to String..." << endl;

    Time::Date date(2020, 1, 1);

    assert(date.getDateAsString() == "2020-1-1");

    Time::Date date2(1400, 10, 10);

    assert(date2.getDateAsString() == "1400-10-10");

    //Try catch with invalid option

    try {
        Time::Date date3(-40, 10, 10);
        assert(false);
    }
    catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        assert(true);
    }

    try {
        Time::Date date4(-40, -10, -10);
        assert(false);
    }
    catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        assert(true);
    }

}
void testDate()
{
    cout << "Testing Date..." << endl;
    testShortDate();
    extendedDateTest();
    testCopyConstructorDate();
    testAssignmentOperator();
    testConvertDateToString();
    cout << "Date tested successfully!" << endl;
}