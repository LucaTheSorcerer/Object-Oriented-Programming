//
// Created by Luca Tudor on 13.04.2023.
//
#include "FruitException.h"

using namespace Exception;

FruitException::FruitException(const string &message) {
    this->message = message;
}

const char *FruitException::what() const noexcept {
    return this->message.c_str();
}

