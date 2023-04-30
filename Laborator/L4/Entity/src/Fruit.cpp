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

Fruit::Fruit(string name, string origin, string producer, const Date& expiry_date, int quantity, double price) : name_(std::move(name)),
                                                                                               origin_(std::move(origin)),
                                                                                               producer_(std::move(producer)),
                                                                                               expiry_date_(expiry_date),
                                                                                               quantity_(quantity),
                                                                                               price_(price) {}

string Fruit::getName() const {
    return name_;
}

const string &Fruit::getOrigin() const {
    return origin_;
}

Date Fruit::getExpiryDate() const {
    return expiry_date_;
}

int Fruit::getQuantity() const {
    return quantity_;
}

double Fruit::getPrice() const {
    return price_;
}

string Fruit::getProducer() const {
    return producer_;
}


void Fruit::setName(const string &name) {
    name_ = name;
}

void Fruit::setOrigin(const string &origin) {
    origin_ = origin;
}

void Fruit::setExpiryDate(const Date &expiryDate) {
    expiry_date_ = expiryDate;
}

void Fruit::setQuantity(int quantity) {
    quantity_ = quantity;
}


void Fruit::setPrice(double price) {
    price_ = price;
}

void Fruit::setProducer(const string &newProducer) {
    producer_ = newProducer;
}



std::string Entity::Fruit::getFruitAsString() const {

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << price_;
    std::string formatPrice = oss.str();

    return name_ + ',' + origin_ + ',' + producer_ + ',' + expiry_date_.getDateAsString() + ',' + to_string(quantity_) + ',' + formatPrice;
}



bool Fruit::operator==(const Fruit &other) const {
    return (producer_ == other.producer_);
}

bool Fruit::operator!=(const Fruit &other) const {
    return !(*this == other);
}

Fruit &Fruit::operator=(const Fruit &other) = default;

bool Fruit::operator<(const Fruit &other) const {
    return (expiry_date_ < other.expiry_date_);
}

bool Fruit::operator>(const Fruit &other) const {
    return (expiry_date_ > other.expiry_date_);
}

bool Fruit::operator<=(const Fruit &other) const {
    return (*this < other) || (*this == other);
}

bool Fruit::operator>=(const Fruit &other) const {
    return (*this > other) || (*this == other);
}

std::ostream &Entity::operator<<(std::ostream &os, const Fruit &fruit) {
    os << "Name: " + fruit.name_ << endl;
    os << "Origin: " + fruit.origin_ << endl;
    os << "Producer: " + fruit.producer_ << endl;
    os << "Expiry date: " + fruit.expiry_date_.getDateAsString() << endl;
    os << "Quantity: " + to_string(fruit.quantity_) << endl;
    os << "Price: " + to_string(fruit.price_) << endl;
    return os;

}