//
// Created by Luca Tudor on 13.04.2023.
//
#include "Fruit.h"

#include <utility>
#include <iostream>

using Entity::Fruit;
using std::cout;
using std::endl;
using std::to_string;

Fruit::Fruit(string name, string origin, string producer, string expiry_date, int quantity, double price) : name_(std::move(name)),
                                                                                               origin_(std::move(origin)),
                                                                                               producer_(std::move(producer)),
                                                                                               expiry_date_(std::move(expiry_date)),
                                                                                               quantity_(quantity),
                                                                                               price_(price) {}

string Fruit::getName() const {
    return name_;
}

const string &Fruit::getOrigin() const {
    return origin_;
}

const string &Fruit::getExpiryDate() const {
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

void Fruit::setExpiryDate(const string &expiryDate) {
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

void Fruit::printFruit() {
    cout << "Name: " << name_ << endl;
    cout << "Origin: " << origin_ << endl;
    cout << "Expiry date: " << expiry_date_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Price: " << price_ << endl;
}

string Fruit::toString() {
    return name_ + " " + origin_ + " " + expiry_date_ + " " + to_string(quantity_) + " " + to_string(price_);
}