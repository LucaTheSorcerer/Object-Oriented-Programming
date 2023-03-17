//
// Created by Luca Tudor on 08.03.2023.
//
#include <iostream>

using namespace std;

const int M = 2;
const int N = 3;
const int P = 2;
//void multiply_matrices(int first_matrix, int second_matrix, int result);

void multiply_matrices(int first_matrix[M][N], int second_matrix[N][P], int result_matrix[M][P]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            int sum = 0;
            for (k = 0; k < N; k++)
                sum += first_matrix[i][k] * second_matrix[k][j];
            result_matrix[i][j] = sum;
        }
    }
}

int main() {
    int first_matrix[M][N] = {{1, 2, 3},
                              {4, 5, 6}};
    int second_matrix[N][P] = {{7,  8},
                               {9,  10},
                               {11, 12}};
    int result_matrix[M][P] = {0};

    multiply_matrices(first_matrix, second_matrix, result_matrix);

    cout << "Your multiplied matrix is: " << endl;

    int i, j;

    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            cout << result_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

