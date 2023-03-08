//
// Created by Luca Tudor on 01.03.2023.
//
#include <iostream>
using namespace std;

double squareRoot(double number) {
    double x = 1.0;
    double diff = 1.0;

    while (diff > 0.0001) {
        double prev = x;
        x = (x + number / x) / 2;
        diff = abs(x - prev);
    }

    return x;
}

int main() {
    double number;
    while (true) {
        cout << "Enter a positive number to compute its square root: ";
        cin >> number;

        if (number < 0) {
            cout << "Error: You entered a negative number. The number must pe positive." << endl;
        } else {
            double result = squareRoot(number);
            cout << "The square root of " << number << " is: " << result << endl;
            break;
        }
    }

    return 0;
}
