//
// Created by Luca Tudor on 14.06.2023.
//

#include "Adapter.h"

AdapterSingleInheritance::AdapterSingleInheritance(Adaptee *adaptee) {
    this->adaptee_ = adaptee;
}

std::string AdapterSingleInheritance::Request() const {
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "AdapterSingleInheritance: (TRANSLATED) " + to_reverse;
}

AdapterMultipleInheritance::AdapterMultipleInheritance() = default;

std::string AdapterMultipleInheritance::Request() const {
    std::string to_reverse = SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "AdapterMultipleInheritance: (TRANSLATED) " + to_reverse;
}
