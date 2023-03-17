//
// Created by Luca Tudor on 15.03.2023.
//
#pragma once

#include <string>
#include <map>

/**
 * @brief Money header file
 * @param value represents the value of the currency
 * @param currency represents a string where we save which currency we use (EUR, RON, USD etc.)
 * @param conversion_table We use a map so that we can store the conversion rates and the currencies that we need for
 * the convert_to_currency method
 * @details This is the Money header file where we define the Money class, the variables and the class members/methods
 * Theoretically the time complexity of each function is constant, so θ(1), apart from the function convert_currency_to
 * where the time comlexity is O(n) in the worst case because it has to search through the conversion_table map.
 */
class Money {
private:
    double amount;
    std::string currency;
    std::map<std::string, double> conversion_table = {
            {"USDUSD", 1.00},
            {"USDEUR", 0.840},
            {"USDRON", 4.91},
            {"EURUSD", 1.189},
            {"EUREUR", 1.00},
            {"EURRON", 4.122},
            {"RONUSD", 0.203},
            {"RONEUR", 0.243},
            {"RONRON", 1.00},
            {"EUREUR", 0.475},
            {"EUR",    0.24},
            {"HUF",    81.55},
            {"RON",    1.0},
            {"USD",    2.0}
    };


public:
    Money(double value, std::string currency);

    [[nodiscard]] double get_value() const;

    [[nodiscard]] std::string get_currency() const;

    [[nodiscard]] Money add(const Money &other) const;

    [[nodiscard]] Money subtract(const Money &other) const;

    [[nodiscard]] Money scale(double factor) const;

    [[nodiscard]] Money divide(double divisor) const;

    [[nodiscard]] std::string convert_to_string() const;


    [[nodiscard]] int compare(const Money &other) const;

    //Bonus points functions

    [[nodiscard]] Money convert_currency_to(const std::string &new_currency) const;

    Money operator+(const Money &other) const;

    Money operator-(const Money &other) const;

    Money operator/(double divisor) const;

    Money operator*(double multiplier) const;

    bool operator==(const Money &other) const;

    bool operator!=(const Money &other) const;

    bool operator<(const Money &other) const;

    bool operator<=(const Money &other) const;

    bool operator>(const Money &other) const;

    bool operator>=(const Money &other) const;
};
