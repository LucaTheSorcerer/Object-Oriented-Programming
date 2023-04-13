//
// Created by Luca Tudor on 13.04.2023.
//
#include "Fruit.h"

#include <utility>
#include <iostream>
using namespace std;

Fruit::Fruit(string name, string origin, string expiry_date, int quantity, double price) : name_(std::move(name)), origin_(std::move(origin)), expiry_date_(std::move(expiry_date)), quantity_(quantity), price_(price) {}

string Fruit::getName() {
    return name_;
}

void Fruit::setName(const string &name) {
    name_ = name;
}

const string &Fruit::getOrigin() const {
    return origin_;
}

void Fruit::setOrigin(const string &origin) {
    origin_ = origin;
}

const string &Fruit::getExpiryDate() const {
    return expiry_date_;
}

void Fruit::setExpiryDate(const string &expiryDate) {
    expiry_date_ = expiryDate;
}

int Fruit::getQuantity() const {
    return quantity_;
}

void Fruit::setQuantity(int quantity) {
    quantity_ = quantity;
}

double Fruit::getPrice() const {
    return price_;
}

void Fruit::setPrice(double price) {
    price_ = price;
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
