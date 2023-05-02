//
// Created by Luca Tudor on 13.04.2023.
//
#include "FruitException.h"

using namespace Exception;

/**
 * Constructor for FruitException that takes a message as a parameter
 * @param message
 */
FruitException::FruitException(const string &message) {
    this->message = message;
}

/**
 * Returns the message of the exception
 * @return
 */
const char *FruitException::what() const noexcept {
    return this->message.c_str();
}

