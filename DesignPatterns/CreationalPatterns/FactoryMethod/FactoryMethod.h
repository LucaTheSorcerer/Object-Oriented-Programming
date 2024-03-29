//
// Created by Luca Tudor on 06.06.2023.
//

#ifndef CREATIONALPATTERNS_FACTORYMETHOD_H
#define CREATIONALPATTERNS_FACTORYMETHOD_H

#include <string>

/**
 * The Product interface declares the operations that all concrete products must implement.
 */
class Product {
public:
    virtual ~Product() {};
    virtual std::string Operation() const = 0;
};

/**
 * Concrete Products provide various implementations of the Product interface.
 */

class ConcreteProduct1 : public Product {
public:
    std::string Operation() const override;
};

class ConcreteProduct2 : public Product {
public:
    std::string Operation() const override;
};

/**
 * The Creator class declares the factory method that is supposed to return an object of a Product class.
 * The Creator's subclasses usually provide the implementation of this method.
 */

class Creator {
    /**
     * Note that the Creator may also provide some default implementation of the factory method.
     */

public:
    virtual ~Creator()= default;
    [[nodiscard]] virtual Product* FactoryMethod() const = 0;

    [[nodiscard]] std::string SomeOperation() const {
        // Call the factory method to create a Product object.
        Product* product = this->FactoryMethod();
        // Now, use the product.
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

/**
 * Concrete Creators override the factory method in order to change the resulting product's type.
 */

class ConcreteCreator1 : public Creator {
    /**
     * Note that the signature of the method still uses the abstract product type,
     * even though the concrete product is actually returned from the method.
     * This way the Creator can stay independent of concrete product classes.
     */

public:
    [[nodiscard]] Product* FactoryMethod() const override;
};

class ConcreteCreator2 : public Creator {
public:
    [[nodiscard]] Product* FactoryMethod() const override;
};



#endif //CREATIONALPATTERNS_FACTORYMETHOD_H
