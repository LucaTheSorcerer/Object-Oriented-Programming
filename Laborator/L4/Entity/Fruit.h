//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once
#include <string>
using namespace std;

class Fruit {
private:
    string name_;
    string origin_;
    string expiry_date_;
    int quantity_;
    double price_;

public:
    Fruit(string name, string origin, string expiry_date, int quantity, double price);

    string getName();
    void setName(const string &name);
    [[nodiscard]] const string &getOrigin() const;
    void setOrigin(const string &origin);
    [[nodiscard]] const string &getExpiryDate() const;
    void setExpiryDate(const string &expiryDate);
    [[nodiscard]] int getQuantity() const;
    void setQuantity(int quantity);
    [[nodiscard]] double getPrice() const;
    void setPrice(double price);
    void printFruit();

    //Function to transform to string
    string toString();

};