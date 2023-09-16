#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Adapter/Adapter.h"
#include "Composite/Composite.h"


void ClientCode(const Target *target) {
    std::cout << target->Request();
}

void ClientCodeComposite(std::shared_ptr<Component> component) {
    std::cout << "RESULT: " << component->Operation();
}

void ClientCodeComposite2(std::shared_ptr<Component> component1, std::shared_ptr<Component> component2) {
    if(component1->isComposite()) {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
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

    // ==================== COMPOSITION Adapter ====================

    std::cout << "==================== COMPOSITE ====================" << std::endl;

    std::shared_ptr<Component> simple = std::make_shared<Leaf>();
    std::cout << "Client: I've got a simple component:\n";
    ClientCodeComposite(std::shared_ptr<Component>(simple));
    std::cout << "\n\n";

    std::shared_ptr<Component> tree = std::make_shared<Composite>();
    std::shared_ptr<Component> branch1 = std::make_shared<Composite>();

    std::shared_ptr<Component> leaf_1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_2 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_3 = std::make_shared<Leaf>();

    branch1->Add(leaf_1);
    branch1->Add(leaf_2);

    std::shared_ptr<Component> branch2 = std::make_shared<Composite>();
    branch2->Add(leaf_3);

    tree->Add(branch1);
    tree->Add(branch2);

    std::cout << "Client: Now I've got a composite tree:\n";

    ClientCodeComposite(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";

    ClientCodeComposite2(tree, simple);
    std::cout << "\n";




    return 0;
}
