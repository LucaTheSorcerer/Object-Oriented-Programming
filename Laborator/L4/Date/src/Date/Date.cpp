//
// Created by Luca Tudor on 30.04.2023.
//
#include <string>
#include "Date.h"

Time::Date::Date(int day, int month, int year) {

    if(year <= 0 || month <= 0 || day <= 0)
        throw std::invalid_argument("Invalid date");

    if(month > 12)
        throw std::invalid_argument("Invalid date");

    int daysInMonth = 31;

    if(month == 2) {
        daysInMonth = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }

    if(day > daysInMonth)
        throw std::invalid_argument("Invalid date");

    this->day = day;
    this->month = month;
    this->year = year;
}

int Time::Date::getDay() const {
    return day;
}

int Time::Date::getMonth() const {
    return month;
}

int Time::Date::getYear() const {
    return year;
}

std::string Time::Date::getDateAsString() const {
    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
}

void Time::Date::setDay(int newDay) {

    //set the day and check it is is withing the bounds of the day of a month

    int daysInMonth = getNumberOfDaysInMonth(month, year);

    if(newDay >= 1 && newDay <= daysInMonth)
        this->day = newDay;
    else
        throw std::invalid_argument("The days must be between 1 and " + std::to_string(daysInMonth));

}

void Time::Date::setMonth(int newMonth) {

    if(newMonth >= 1 && newMonth <= 12)
        this->month = newMonth;
    else
        throw std::invalid_argument("Invalid date");
}

void Time::Date::setYear(int newYear) {

    if(newYear >= 0)
        this->year = newYear;
    else
        throw std::invalid_argument("Invalid date");
}



bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Time::Date::getNumberOfDaysInMonth(int month, int year) {

    const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

Time::Date &Time::Date::operator=(const Time::Date &other) {
    if(this != &other) {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}

bool Time::Date::operator==(const Time::Date &other) const {
    return (this->day == other.day && this->month == other.month && this->year == other.year);
}

bool Time::Date::operator!=(const Time::Date &other) const {
    return !(*this == other);
}

bool Time::Date::operator<(const Time::Date &other) const {
    if(this->year < other.year) {
        return true;
    }
    else if(this->year == other.year && this->month < other.month) {
        return true;
    }
    else if(this->year == other.year && this->month == other.month && this->day < other.day) {
        return true;
    }
    else {
        return false;
    }
}

bool Time::Date::operator>(const Time::Date &other) const {
    return !(*this <= other);
}

bool Time::Date::operator<=(const Time::Date &other) const {
    return (*this < other || *this == other);
}

bool Time::Date::operator>=(const Time::Date &other) const {
    return !(*this < other);
}

