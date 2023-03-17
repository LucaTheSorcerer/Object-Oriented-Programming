//
// Created by Luca Tudor on 17.03.2023.
//
#include "1_money.h"
#include <cassert>

#pragma once

/**
 * Test function that tests all the functionalities of the class Money and its methods
 */
void testAll() {
    Money amount1(100.00, "USD");
    Money amount2(50.00, "USD");
    Money m1(100.00, "USD");
    Money m2(50.00, "USD");

    Money r1 = m1.add(m2);
    Money r2 = m1.subtract(m2);

    assert(r1.get_value() == 150.00);
    assert(r2.get_value() == 50.00);

    assert(r2.convert_to_string() == "50.00 USD");
    assert(r1.convert_to_string() == "150.00 USD");

    assert(amount1.get_value() == 100.00);
    assert(amount1.get_currency() == "USD");

    Money sum = amount1 + amount2;
    Money diff = amount1 - amount2;
    assert(sum.get_value() == 150.00);
    assert(diff.get_value() == 50.00);

    Money scaled = amount1.scale(2.00);
    Money divided = amount1.divide(2.00);
    assert(scaled.get_value() == 200.00);
    assert(divided.get_value() == 50.00);

    assert(amount1.convert_to_string() == "100.00 USD");

    assert(amount1.compare(amount2) == 1);
    assert (amount1.compare(amount2) != -1);
    assert(amount1.compare(amount2) != 0);

    Money result_operators = amount1 + amount2 * 2.00 - amount2 / 2.0;
    assert(result_operators.get_value() == 175.00);

    Money amount3(100, "EUR");
    Money amount4 = amount3.convert_currency_to("USD");
    assert(amount4.get_currency() == "USD");
    assert(amount4.get_value() == 118.90);


    Money amount5(1000, "RON");
    assert(amount5.get_value() == 1000);
    assert(amount5.get_currency() == "RON");

    Money amount6 = amount5.convert_currency_to("EUR");
    assert(std::abs(amount6.get_value() - 243) < 0.01); // use a tolerance threshold
    assert(amount6.get_currency() == "EUR");



// Invalid conversion
    try {
        amount5.convert_currency_to("GBP");
        assert(false); // should not reach here
    } catch (const std::invalid_argument &) {
// expected exception
    }
}
