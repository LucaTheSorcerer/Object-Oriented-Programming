//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once
#include <string>
#include "/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L4/Date/src/Date/Date.h"
using std::string;
using std::stringstream;
using Time::Date;

namespace Entity {
    class Fruit {
    private:
        string name;
        string origin;
        Date expiry_date;
        string producer;
        int quantity;
        double price;

    public:
        explicit Fruit(string name_, string origin_="Romania", string producer_="Gicu de la Craiova", const Date &expiry_date_ = Date(2024, 1, 1), int quantity_=1, double price_=1);

        //Copy constructor
        Fruit(const Fruit &other) = default;

        //Destructor
        ~Fruit() = default;

        //Getters
        [[nodiscard]] string getName() const;
        [[nodiscard]] int getQuantity() const;
        [[nodiscard]] const string &getOrigin() const;
        [[nodiscard]] Date getExpiryDate() const;
        [[nodiscard]] double getPrice() const;
        [[nodiscard]] string getProducer() const;
        [[nodiscard]] std::string getFruitAsString() const;

        //Setters
        void setName(const string &name);
        void setOrigin(const string &origin);
        void setExpiryDate(const Date &expiryDate);
        void setQuantity(int quantity);
        void setPrice(double price);
        void setProducer(const string &newProducer);
        void printFruit();

        //Function to transform to string

        //Overloaded operators
        Fruit &operator=(const Fruit &other);
        bool operator==(const Fruit &other) const;
        bool operator!=(const Fruit &other) const;
        bool operator<(const Fruit &other) const;
        bool operator>(const Fruit &other) const;
        bool operator<=(const Fruit &other) const;
        bool operator>=(const Fruit &other) const;

        friend std::ostream &operator<<(std::ostream &os, const Fruit &fruit);

        friend std::istream &operator>>(std::istream &is, Fruit &fruit);

    };
}

