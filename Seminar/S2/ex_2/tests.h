//
// Created by Luca Tudor on 19.03.2023.
//

#pragma once
#include "bank.h"
#include <cassert>
#include <iostream>
#include <fstream>

void testAll() {
    Bankaccount account1;
    Bankaccount account2(20.0);

    assert(account1.account_balance() == 0.0);
    assert(account2.account_balance() == 20.0);

    account1.deposit(100.0);
    assert(account1.account_balance() == 100.0);

    account2.withdraw(10.0);
    assert(account2.account_balance() == 10.0);

    try {
        account1.withdraw(50.0);
        //assert(false && "Expected exception not thrown!");
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "The bank account's balance cannot be negative");
    }

    std::cout << "The Account1's balance is: " << account1.account_balance() << std::endl;


    Bankaccount account3;
    account3.deposit(100.0);
    account3.withdraw(50.0);
    account3.deposit(10.0);
    account3.saveTransactionsToFile("transaction.txt");
    std::ifstream in("transaction.txt");
    std::string line;
    std::getline(in, line);
    assert(line == "IN 100.00 100.00");
    std::cout << "OKAY" << std::endl;
}
