#include <iostream>
#include "Adapter/Adapter.h"

void ClientCode(const Target *target) {
    std::cout << target->Request();
}

int main() {

    // ==================== SINGLE INHERITANCE Adapter ====================

    std::cout << "==================== SINGLE INHERITANCE Adapter ====================" << std::endl;

    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee has a weird interface. See, I do not understand it: \n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    AdapterSingleInheritance *adapter = new AdapterSingleInheritance(adaptee);
    ClientCode(adapter);
    std::cout << "\n\n";

    delete target;
    delete adaptee;
    delete adapter;

    // ==================== MULTIPLE INHERITANCE Adapter ====================

    std::cout << "==================== MULTIPLE INHERITANCE Adapter ====================" << std::endl;

    std::cout << "Client: I can work just fine and dandy with the Target objects: \n";
    Target *target2 = new Target;
    ClientCode(target2);
    std::cout << "\n\n";
    Adaptee *adaptee2 = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I do not understand it: \n";
    std::cout << "Adaptee: " << adaptee2->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    AdapterMultipleInheritance *adapter2 =  new AdapterMultipleInheritance;
    ClientCode(adapter2);
    std::cout << "\n\n";

    delete target2;
    delete adaptee2;
    delete adapter2;

    return 0;
}
