//
// Created by Luca Tudor on 06.06.2023.
//
#include <string>
#include <utility>

#ifndef CREATIONALPATTERNS_SINGLETON_H
#define CREATIONALPATTERNS_SINGLETON_H


class Singleton {
protected:

    explicit Singleton(std::string  value) : value_(std::move(value)) {}
    static Singleton* singleton;
    std::string value_;

public:

    //Singletons should not be cloneable

    Singleton(Singleton &other) = delete;

    //Singletons should not be assignable

    void operator=(const Singleton &) = delete;

    //The below method is a static method allowing the user to create an instance of the class
    //On the first run, a singleton object is created and on subsequent runs, the same object is returned

    static Singleton *GetInstance(const std::string& value);

    //Some business logic

    std::string value() const;
};


#endif //CREATIONALPATTERNS_SINGLETON_H
