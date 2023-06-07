#include <iostream>
#include "Singleton/Singleton.h"
#include "FactoryMethod/FactoryMethod.h"

void Foo() {
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << std::endl;
}

void Bar() {
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << std::endl;
}

//==================================================================================================
// The client code works with an instance of a concrete creator, albeit through its base interface.
//Code for FactoryMethod
void ClientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
}
//==================================================================================================

int main() {

    //==================================================================================================
    // Singleton

    std::cout << "Singleton Example: " << std::endl;
    Foo();
    Bar();

    //==================================================================================================

    //FactoryMethod

    std::cout << std::endl;

    std::cout << "Factory Method Example: " << std::endl;

    std::cout << "App: Launched with the ConcreteCreator1." << std::endl;
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    std::cout << std::endl;

    std::cout << "App: Launched with the ConcreteCreator2." << std::endl;
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator;
    delete creator2;

    //==================================================================================================

    return 0;
}



