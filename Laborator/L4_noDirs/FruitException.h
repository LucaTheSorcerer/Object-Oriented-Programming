//
// Created by Luca Tudor on 13.04.2023.
//

#pragma once

#include <string>
#include <vector>
#include <exception>

using namespace std;

namespace Exception {
    class FruitException : public exception {
    private:
        string message;
    public:
        explicit FruitException(const string &message);

        [[nodiscard]] const char *what() const noexcept override;

    };
}
