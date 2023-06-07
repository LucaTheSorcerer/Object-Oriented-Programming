//
// Created by Luca Tudor on 06.06.2023.
//

#include "FactoryMethod.h"

std::string ConcreteProduct1::Operation() const {
    return "{Result of the ConcreteProduct1}";
}

std::string ConcreteProduct2::Operation() const {
    return "{Result of the ConcreteProduct2}";}

Product *ConcreteCreator1::FactoryMethod() const {
    return new ConcreteProduct1();}

Product *ConcreteCreator2::FactoryMethod() const {
    return new ConcreteProduct2();
}
