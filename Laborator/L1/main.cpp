//
// Created by Luca Tudor on 01.03.2023.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

//=======================================
//Point a)
//Function used to solve Point a)
/*
 * We start with the initial guess x = 1, and compute the next guess using the formula
 * x = (x + number/x)/2
 * We repeat the step above until the difference between two successive "guesses" is less than
 * a small given value, like 0.0001
 * annahmen erproben
 */

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
//=======================================


//=======================================
//Functions used to solve Point b)
/*
 * We use this function to check if a number is prime by checking
 * if the modulo of the number divided with all number until sqrt(number)
 * is 0. If it is 0 then it is not prime, otherwise it is prime
 */
bool isPrime(int number)
{
    int i;
    if (number <= 1)
        return false;
    for(i = 2; i <= sqrt(number); i++)
        if(number % i == 0) return false;
    return true;
}

/*
 * We use this function to find the longest subsequence in the given array
 * We use two for loops to compute the length of the sequence and the indexes
 * We use references so that we can use the indexes from fain to display the sequence
 */
int longest_subsequence(int array_numbers[], int number, int &start_index, int &end_index)
{
    int max_length = 1, i, j;
    start_index = 0, end_index = 0;
    for(i = 0; i < number; i ++)
    {
        int current_length = 1, current_start = i;
        for(j = i + 1; j < number; j++)
        {
            int difference = abs(array_numbers[j] - array_numbers[j-1]);
            if(isPrime(difference)) //if the number is prime then we increase the length of the sequence
                current_length++;
            else break; //otherwise we break
        }

        if(current_length > max_length) //we compute the indexes in order to display the sequence and to determine the
        {                               //sequence's length
            max_length = current_length;
            start_index = current_start;
            end_index = current_start + current_length - 1;
        }
    }
    return max_length;
}
//=======================================

int main() {

    //=======================================
    //Code used for Point a)
    double number;
    cout << "Enter a positive number: ";
    cin >> number;

    if (number < 0) {
        cout << "Error: Input must be a positive number." << endl;
        return 1;
    }

    double result = squareRoot(number);
    cout << "Square root of " << number << " is: " << result << endl;
    //=======================================


    //=======================================
    //Code used for Point b)

    int n, i, start_index, end_index;
    cout << "Enter the desired number of numbers: ";
    cin >> n;

    int nums_array[n];
    cout << "Enter the desired numbers for your array: ";
    for(i = 0; i < n; i++)
        cin >> nums_array[i];

    int length_sequence = longest_subsequence(nums_array, n, start_index, end_index);
    cout << "The longest continuous subsequence of numbers where their sum is a prime number is: " << length_sequence << endl;

    cout << "The subsequence is: ";

    //we use a for loop from the start index to the end index in order to the diplay only the desired subsequence
    for(i = start_index; i <= end_index; i++)
        cout << nums_array[i] <<  " ";
    cout << endl;
    //=======================================

    return 0;
}
