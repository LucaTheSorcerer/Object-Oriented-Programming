//
// Created by Luca Tudor on 08.03.2023.
//
/*
 * This solution uses a single contiguous block of memory to represent the matrices instead of an array of pointers
 * It can improve cache locality and reduce the number of memory allocations
 */

#include <iostream>
#include <cstring>

using namespace std;

const int M = 2; // Define M as a constant
const int N = 3; // Define N as a constant
const int P = 2; // Define P as a constant

void multiply_matrices(int **first, int **second, int **result)
{
    // Allocate contiguous block of memory for matrices
    int *data_first = new int[M * N];
    int *data_second = new int[N * P];
    int *data_result = new int[M * P];

    // Copy data from input matrices to contiguous blocks of memory
    memcpy(data_first, *first, M * N * sizeof(int));
    memcpy(data_second, *second, N * P * sizeof(int));
    memset(data_result, 0, M * P * sizeof(int));

    // Create pointers to rows of contiguous memory block
    int **mat_first = new int*[M];
    int **mat_second = new int*[N];
    int **mat_result = new int*[M];

    for (int i = 0; i < M; i++) {
        mat_first[i] = data_first + i * N;
        mat_result[i] = data_result + i * P;
    }

    for (int i = 0; i < N; i++) {
        mat_second[i] = data_second + i * P;
    }

    // Compute matrix multiplication
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += mat_first[i][k] * mat_second[k][j];
            }
            mat_result[i][j] = sum;
        }
    }

    // Copy data from contiguous block of memory to output matrix
    memcpy(*result, data_result, M * P * sizeof(int));

    // Free memory
    delete[] mat_first;
    delete[] mat_second;
    delete[] mat_result;
    delete[] data_first;
    delete[] data_second;
    delete[] data_result;
}

int main() {
    int **first = new int *[M];
    for (int i = 0; i < M; i++) {
        first[i] = new int[N];
        for (int j = 0; j < N; j++) {
            first[i][j] = i * N + j + 1;
        }
    }

    for(int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << first[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    int **second = new int *[N];
    for (int i = 0; i < N; i++) {
        second[i] = new int[P];
        for (int j = 0; j < P; j++) {
            second[i][j] = i * P + j + 7;
        }
    }

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++)
            cout << second[i][j] << " ";
        cout << endl;
    }

    cout << "\n";

    int **result = new int *[M];
    for (int i = 0; i < M; i++) {
        result[i] = new int[P];
    }

    multiply_matrices(first, second, result);

    // Print output matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}