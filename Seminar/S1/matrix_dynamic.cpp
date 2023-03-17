//
// Created by Luca Tudor on 08.03.2023.
//
#include <iostream>

using namespace std;

const int M = 2; // Define M as a constant
const int N = 3; // Define N as a constant
const int P = 2; // Define P as a constant


void multiply_matrices(int **first, int **second, int **result) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += first[i][k] * second[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // Define and initialize the matrices
    int first[M][N] = {{1, 2, 3},
                       {4, 5, 6}};

    int second[N][P] = {{7,  8},
                        {9,  10},
                        {11, 12}};

    int result[M][P];

    // Convert the matrices to dynamic arrays of pointers
    int **first_ptr = new int *[M];
    for (int i = 0; i < M; i++) {
        first_ptr[i] = new int[N];
        for (int j = 0; j < N; j++) {
            first_ptr[i][j] = first[i][j];
        }
    }

    int **second_ptr = new int *[N];
    for (int i = 0; i < N; i++) {
        second_ptr[i] = new int[P];
        for (int j = 0; j < P; j++) {
            second_ptr[i][j] = second[i][j];
        }
    }

    int **result_ptr = new int *[M];
    for (int i = 0; i < M; i++) {
        result_ptr[i] = new int[P];
    }

    // Perform matrix multiplication
    multiply_matrices(first_ptr, second_ptr, result_ptr);

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            cout << result_ptr[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory for the arrays
    for (int i = 0; i < M; i++) {
        delete[] first_ptr[i];
    }
    delete[] first_ptr;

    for (int i = 0; i < N; i++) {
        delete[] second_ptr[i];
    }
    delete[] second_ptr;

    for (int i = 0; i < M; i++) {
        delete[] result_ptr[i];
    }
    delete[] result_ptr;

    return 0;
}

