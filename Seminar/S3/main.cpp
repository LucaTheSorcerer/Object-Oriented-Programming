#include <iostream>
#include "Test.h"
using namespace std;


enum class Wochentag {
    Montag,
    Dienstag,
    Mittwoch,
    Donnerstag,
    Freitag,
    Samstag,
    Sonntag
};

Wochentag lookup(int num) {
    //First check if number is valid
    if (num < 1 || num > 7) {
        throw std::invalid_argument("Invalid number");
    }
    else {
        return static_cast<Wochentag>(num - 1);
    }
}



Wochentag lookup(const std::string &name) {
    if (name == "Montag") return Wochentag::Montag;
    if (name == "Dienstag") return Wochentag::Dienstag;
    if (name == "Mittwoch") return Wochentag::Mittwoch;
    if (name == "Donnerstag") return Wochentag::Donnerstag;
    if (name == "Freitag") return Wochentag::Freitag;
    if (name == "Samstag") return Wochentag::Samstag;
    if (name == "Sonntag") return Wochentag::Sonntag;
    throw std::invalid_argument("Invalid name");
}

std::string lookup_string(Wochentag day) {
    switch (day) {
        case Wochentag::Montag:
            return "Montag";
        case Wochentag::Dienstag:
            return "Dienstag";
        case Wochentag::Mittwoch:
            return "Mittwoch";
        case Wochentag::Donnerstag:
            return "Donnerstag";
        case Wochentag::Freitag:
            return "Freitag";
        case Wochentag::Samstag:
            return "Samstag";
        case Wochentag::Sonntag:
            return "Sonntag";
    }
}
//int main() {
//
//    std::cout << static_cast<int>(Wochentag::Montag) << std::endl;  // 0
//    std::cout << static_cast<int>(Wochentag::Dienstag) << std::endl;  // 1
//
//    std::cout << static_cast<int>(lookup("Montag")) << std::endl;  // 0
//    std::cout << static_cast<int>(lookup("Dienstag")) << std::endl;  // 1
//
//    std::cout << static_cast<int>(lookup(1)) << std::endl;  // 0
//    std::cout << static_cast<int>(lookup(2)) << std::endl;  // 1
//
//    std::cout << lookup_string(Wochentag::Montag) << std::endl;  // Montag
//    std::cout << lookup_string(Wochentag::Dienstag) << std::endl;  // Dienstag
//
//    return 0;
//}