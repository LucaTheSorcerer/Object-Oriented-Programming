//
// Created by Luca Tudor on 19.03.2023.
//
#include "bank.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

Bankaccount::Bankaccount() {
    account = 0;
}

Bankaccount::Bankaccount(double account_) {
    account= account_;
}

void Bankaccount::deposit(double amount) {
    account += amount;
}

void Bankaccount::withdraw(double amount) {
    if (amount > account)
        throw std::runtime_error("Not enough currency!");

    account -= amount;
}

double Bankaccount::account_balance() const {
    return account;
}

void Bankaccount::printTransactions() const {
    for(int i = 0; i < numTransactions; i++) {
        std::cout << transactions[i] << std::endl;
    }
}

void Bankaccount::saveTransactionsToFile(const std::string &filename) const {
    std::ofstream outfile(filename);
    if(outfile.is_open()) {
        for(int i = 0; i < numTransactions; i++) {
            outfile << transactions[i] << std::endl;
        }
        outfile.close();
    } else {
        throw std::runtime_error("The file could not be opened!");
    }
}

void Bankaccount::loadTransactionsFromFile(const std::string &filename) {
    std::ifstream in_file(filename);
    if (in_file.is_open()) {
        std::string type;
        double amount;
        while (in_file >> type >> amount) {
            if (type == "IN") {
                deposit(amount);
            } else if (type == "OUT") {
                withdraw(amount);
            } else {
                throw std::runtime_error("The transaction is invalid!");
            }
        }
        in_file.close();
    } else
        throw std::runtime_error("The file could not be opened!");

}

void Bankaccount::addTransaction(const std::string &type, double amount) {
    auto *temp = new double[numTransactions + 2];
    if(numTransactions > 0) {
        std::copy(transactions, transactions + numTransactions, temp);
        delete[] transactions;
    }
    temp[numTransactions] = amount;
    temp[numTransactions + 1] = account;
    transactions = temp;
    numTransactions++;
}
