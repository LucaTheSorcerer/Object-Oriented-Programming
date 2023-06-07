//
// Created by Luca Tudor on 06.06.2023.
//

#include "Singleton.h"

Singleton* Singleton::singleton = nullptr;

//Static method should always be defined outside the class

Singleton *Singleton::GetInstance(const std::string& value) {
    if(singleton == nullptr) {
        singleton = new Singleton(value);
    }

    return singleton;
}

std::string Singleton::value() const {
    return value_;
}

