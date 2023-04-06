//
// Created by Luca Tudor on 06.04.2023.
//

#include <stdexcept>
#include <iostream>

template <typename T>
class GeometricForm {
public:
    virtual T calculateArea();
    virtual void printDescription();
};

//use template to avoid code duplication
template <typename T>
T GeometricForm<T>::calculateArea() {
    return 0;
}

template <typename T>
void GeometricForm<T>::printDescription() {
    std::cout << "Geometric form" << std::endl;

}

//use template to avoid code duplication
template <typename T>
class Circle : public GeometricForm<T> {
private:
    T radius;
public:
    explicit Circle(T r): radius(r) {
        if(radius < 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

    T calculateArea() override {
        return 3.14159 * radius * radius;
    }

    void printDescription() override {
        std::cout << "Circle with radius " << radius << std::endl;
    }
};

//use template to avoid code duplication
template <typename T>
class Square: public GeometricForm<T> {
private:
    T side;
public:
    explicit Square(T s): side(s) {
        if(side < 0) {
            throw std::invalid_argument("The sides must be positive");
        }
    }

    T calculateArea() override {
        return side * side;
    }

    void printDescription() override {
        std::cout << "Square with the side " << side << std::endl;
    }
};

void test_classes() {
    GeometricForm<int> *circle = new Circle(5);
    GeometricForm<int> *square = new Square(5);
    circle->printDescription();
    square->printDescription();
    std::cout << "Area of circle: " << circle->calculateArea() << std::endl;
    std::cout << "Area of square: " << square->calculateArea() << std::endl;
    delete circle;
    delete square;
}

int main() {
    test_classes();
    return 0;
}
