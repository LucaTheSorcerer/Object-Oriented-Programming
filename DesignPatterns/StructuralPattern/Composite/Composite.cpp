//
// Created by Luca Tudor on 14.06.2023.
//

#include "Composite.h"

#include <utility>

void Component::setParent(std::shared_ptr<Component> parent) {
    this->parent_ = std::move(parent);
}

std::shared_ptr<Component> Component::getParent() const {
    return this->parent_;
}



bool Component::isComposite() const {
    return false;
}



std::string Leaf::Operation() const {
    return "Leaf";
}

void Composite::Add(std::shared_ptr<Component> &component) {
    children_.push_back(component);
    component->setParent(std::shared_ptr<Component>(this));
}

void Composite::Remove(std::shared_ptr<Component> &component) {
    children_.remove(component);
    component->setParent(nullptr);
}

bool Composite::isComposite() const {
    return true;
}

std::string Composite::Operation() const {

    std::string result;

    for(const std::shared_ptr<Component>& c : children_) {
        if(c == children_.back()) {
            result += c->Operation();
        } else {
            result += c->Operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}
