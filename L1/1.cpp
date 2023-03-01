//
// Created by Luca Tudor on 01.03.2023.
//
#include<stdio.h>
#include<math.h>
#include <stdbool.h>

// Recursive function that returns square root of a number with precision upto 5 decimal places
// We use binary search to find the square root
double Square(double n, double i, double j)
{
    double mid = (i + j) / 2;
    double mul = mid * mid;

    // If mid  is the square root then we return mid
    // fabs gives back the absolute value
    if ((mul == n) || (fabs(mul - n) < 0.00001))
        return mid;

        // If mul is less than n, recur second half
    else if (mul < n)
        return Square(n, mid, j);

        // else search in the first half
    else
        return Square(n, i, mid);
}

// Function to find the square root of n
void findSqrt(double n)
{
    double i = 1;

    // While the square root is not found
    bool found = false;
    while (!found) {

        // If n is a perfect square then we simply return the value of i
        if (i * i == n) {
            printf("%.0lf",i);
            found = true;
        }
        else if (i * i > n) {

            // Square root will lie in the interval i-1 and i
            double res = Square(n, i - 1, i);
            printf("%.5lf", res);
            found = true;
        }
        i++;
    }
}



int main() {
    double n = 3;
    findSqrt(n);
    return 0;
}