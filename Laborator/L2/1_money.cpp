//
// Created by Luca Tudor on 16.03.2023.
//
#include "1_money.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <utility>


Money::Money(double amount, std::string currency) {
    this->amount = amount;
    this->currency = std::move(currency);
}

/**
 * function get_value
 * @return the value of the curency
 */
double Money::get_value() const {
    return this->amount;
}

/**
 * function get_currency
 * @return the currency of the instance created
 */
std::string Money::get_currency() const {
    return this->currency;
}

/**
 * function add
 * @param other represents another object instanced passed as an argument
 * @return a new instance representing the addition of two other instances
 * @throw invalid_argument if the currencies of the two objects do not match
 */
Money Money::add(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    double sum = this->amount + other.amount;
    return {sum, this->currency};
}

Money Money::add_on_object(double value) const {
    double sum = this->amount + value;
    return {sum, this->currency};
}

void Money::add_to_object(double value) {
    this->amount += value;
}


//update the value and return a pointer to it
Money* Money::add_to_object_pointer(double value) {
    this->amount += value;
    return this;
}

//return a refernce to the same object
Money& Money::add_to_object_ref(double value) {
    this->amount += value;
    return *this;
}



/**
* function substract
* @param other represents another object instanced passed as an argument
* @return a new instance representing the substraction of two other instances
* @throw invalid_argument if the currencies of the two objects do not match
*/
Money Money::subtract(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    double diff = this->amount - other.amount;
    return {diff, this->currency};
}

/**
* function scale
* @param factor represents a double
* @return a new instance representing the multiplication between an instance and the factor
*/
Money Money::scale(double factor) const {
    double scaled_amount = this->amount * factor;
    return {scaled_amount, this->currency};
}

/**
* function divide
* @param divisor represents a double
* @return a new instance representing the division between an instance and the factor
* @throw invalid_argument if the divisor is 0
*/
Money Money::divide(double divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero is not allowed!");
    }

    double division_amount = this->amount / divisor;
    return {division_amount, this->currency};
}

/**
* function convert_to_string
* @return a string of the form "amount currency"
*/
std::string Money::convert_to_string() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << this->amount << " " << this->currency;
    return oss.str();
}

/**
* function compare
* @return -1, 0 or 1 based on the comparison of the money amounts of two instances
* @throw invalid_argument if the currencies of the two objects do not match
*/
int Money::compare(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    if (this->amount < other.amount) {
        return -1;
    } else if (this->amount == other.amount) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * function convert_currency_to
 * @details searches in the map implemented above the specified currency and its value for the conversion rate
 * @param new_currency the new currency given
 * @return the new_value and the new_currency in the form of a new instance of the class
 * @throw invalid_argument if in the map the conversion rate between two given currencies is not defined
 * @complexity: Worst case O(n)
 * @complexity: Best case θ(1)
 */
Money Money::convert_currency_to(const std::string &new_currency) const {
    if (new_currency == this->currency)
        return *this;
    else if (Money::conversion_table.find(this->currency + new_currency) == Money::conversion_table.end() &&
             Money::conversion_table.find(new_currency + this->currency) == Money::conversion_table.end()) {
        throw std::invalid_argument("Conversion rate is not defined from " + this->currency + " to " + new_currency);
    } else {
        double conversion_rate = conversion_table.at(this->currency + new_currency);
        double new_value = this->amount * conversion_rate;
        return {new_value, new_currency};
    }
}

/**
 * Overloading methods for the class
 * @throw invalid_argument if the given currencies of two instances do not match
 */
Money Money::operator+(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    double result = this->amount + other.amount;

    return {result, this->currency};
}

Money Money::operator-(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    double result = this->amount - other.amount;

    return {result, this->currency};
}

Money Money::operator*(double multiplier) const {
    double result = this->amount * multiplier;

    return {result, this->currency};
}

Money Money::operator/(double divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero is not permitted");
    }

    double result = this->amount / divisor;

    return {result, this->currency};
}

bool Money::operator==(const Money &other) const {
    return (this->amount == other.amount) && (this->currency == other.currency);
}

bool Money::operator!=(const Money &other) const {
    return (this->amount != other.amount) || (this->currency != other.currency);
}

bool Money::operator<(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    return this->amount < other.amount;
}

bool Money::operator<=(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    return this->amount <= other.amount;
}

bool Money::operator>(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    return this->amount > other.amount;
}

bool Money::operator>=(const Money &other) const {
    if (this->currency != other.currency) {
        throw std::invalid_argument("The given currencies do not match!");
    }

    return this->amount >= other.amount;
}