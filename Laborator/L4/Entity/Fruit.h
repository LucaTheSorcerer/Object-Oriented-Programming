//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once
#include <string>
using std::string;
using std::stringstream;

namespace Entity {
    class Fruit {
    private:
        string name_;
        string origin_;
        string expiry_date_;
        string producer_;
        int quantity_;
        double price_;

    public:
        Fruit(string name, string origin, string producer, string expiry_date, int quantity, double price);

        //Copy constructor
        Fruit(const Fruit &other);

        //Destructor
        ~Fruit() = default;

        //Getters
        [[nodiscard]] string getName() const;

        [[nodiscard]] int getQuantity() const;

        [[nodiscard]] const string &getOrigin() const;

        [[nodiscard]] const string &getExpiryDate() const;

        [[nodiscard]] double getPrice() const;

        [[nodiscard]] string getProducer() const;

        //Setters
        void setName(const string &name);

        void setOrigin(const string &origin);

        void setExpiryDate(const string &expiryDate);

        void setQuantity(int quantity);

        void setPrice(double price);

        void setProducer(const string &newProducer);

        void printFruit();

        //Function to transform to string
        string toString();

        //Overloaded operators
        Fruit &operator=(const Fruit &other);

        bool operator==(const Fruit &other) const;

        bool operator!=(const Fruit &other) const;

        bool operator<(const Fruit &other) const;

        bool operator>(const Fruit &other) const;

        bool operator<=(const Fruit &other) const;

        bool operator>=(const Fruit &other) const;

        friend ostream &operator<<(ostream &os, const Fruit &fruit);

        friend istream &operator>>(istream &is, Fruit &fruit);

    };
}

