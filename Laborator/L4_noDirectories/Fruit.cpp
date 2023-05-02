//
// Created by Luca Tudor on 13.04.2023.
//
#include "Fruit.h"

#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

using Entity::Fruit;
using std::cout;
using std::endl;
using std::to_string;

Fruit::Fruit(string name_, string origin_, string producer_, const Date& expiry_date_, int quantity_, double price_) : name(std::move(name_)),
                                                                                                                       origin(std::move(origin_)),
                                                                                                                       producer(std::move(producer_)),
                                                                                                                       expiry_date(expiry_date_),
                                                                                                                       quantity(quantity_),
                                                                                                                       price(price_) {}

string Fruit::getName() const {
    return name;
}

const string &Fruit::getOrigin() const {
    return origin;
}

Date Fruit::getExpiryDate() const {
    return expiry_date;
}

int Fruit::getQuantity() const {
    return quantity;
}

double Fruit::getPrice() const {
    return price;
}

string Fruit::getProducer() const {
    return producer;
}


void Fruit::setName(const string &newName) {
    name = newName;
}

void Fruit::setOrigin(const string &newOrigin) {
    origin = newOrigin;
}

void Fruit::setExpiryDate(const Date &newExpiryDate) {
    expiry_date = newExpiryDate;
}

void Fruit::setQuantity(int newQuantity) {
    quantity = newQuantity;
}


void Fruit::setPrice(double newPrice) {
    price = newPrice;
}

void Fruit::setProducer(const string &newProducer) {
    producer = newProducer;
}



std::string Entity::Fruit::getFruitAsString() const {

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << price;
    std::string formatPrice = oss.str();

    return name + ',' + origin + ',' + producer + ',' + expiry_date.getDateAsString() + ',' + std::to_string(quantity) + ',' + formatPrice;
}

//void Fruit::printFruit() {
//    cout << "Name: " + name << endl;
//    cout << "Origin: " + origin << endl;
//    cout << "Producer: " + producer << endl;
//    cout << "Expiry date: " + expiry_date.getDateAsString() << endl;
//    cout << "Quantity: " + to_string(quantity) << endl;
//    cout << "Price: " + to_string(price) << endl;
//}

bool Entity::Fruit::operator==(const Fruit &other) const {
    return (producer == other.producer);
}

bool Entity::Fruit::operator!=(const Fruit& other) const {
    return !(*this == other);
}

Fruit &Fruit::operator=(const Fruit &other) = default;

bool Entity::Fruit::operator<(const Fruit &other) const {
    return (expiry_date < other.expiry_date);
}

bool Entity::Fruit::operator>(const Fruit &other) const {
    return (expiry_date > other.expiry_date);
}

bool Entity::Fruit::operator<=(const Fruit &other) const {
    return (*this < other) || (*this == other);
}

bool Entity::Fruit::operator>=(const Fruit &other) const {
    return (*this > other) || (*this == other);
}

std::ostream &Entity::operator<<(std::ostream &os, const Fruit &fruit) {
    os << "Name: " + fruit.name + "\n";
    os << "Origin: " + fruit.origin + "\n";
    os << "Producer: " + fruit.producer + "\n";
    os << "Expiration Date: " + fruit.expiry_date.getDateAsString() + "\n";
    os << "Quantity: " + std::to_string(fruit.quantity) + "\n";
    os << "Price: " + std::to_string(fruit.price) + "\n";
    return os;
}