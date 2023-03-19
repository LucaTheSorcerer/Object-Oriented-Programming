//
// Created by Luca Tudor on 19.03.2023.
//

#pragma once

#include <string>

class Bankaccount {
private:
    double account;
    int numTransactions;
    double* transactions;
    void addTransaction(const std::string& type, double amount);

public:
    Bankaccount();
    Bankaccount(double account);
    void deposit(double amount);
    void withdraw(double amount);
    double account_balance() const;
    void printTransactions() const;
    void saveTransactionsToFile(const std::string& filename) const;
    void loadTransactionsFromFile(const std::string& filename);

};
