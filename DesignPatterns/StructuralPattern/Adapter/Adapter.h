//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef STRUCTURALPATTERN_ADAPTER_H
#define STRUCTURALPATTERN_ADAPTER_H

#include <string>
#include <iostream>


/**
 * The target defines the domain-specific interface used by the client code.
 */

class Target {
public:
    virtual ~Target() = default;
    [[nodiscard]] virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

/**
 * The adaptee contains some useful behaviour, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the client
 * code can use it.
 */

class Adaptee {
public:
    [[nodiscard]] std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};


//Single inheritance
class AdapterSingleInheritance : public Target {

private:
    Adaptee *adaptee_;

public:
    AdapterSingleInheritance(Adaptee *adaptee);
    std::string Request() const override;
};

//Multiple inheritance
class AdapterMultipleInheritance : public Target, public Adaptee {
public:
    AdapterMultipleInheritance();
    std::string Request() const override;
};


#endif //STRUCTURALPATTERN_ADAPTER_H
