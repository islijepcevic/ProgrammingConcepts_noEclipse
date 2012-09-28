/*
 * exercise_1_4.cpp
 *
 * matrices
 *
 * Created on: Sept 27, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>

#define N 2

void inputMatrix(double (*M)[2]) {

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            std::cout << "enter a[" << i << "][" << j << "]: ";
            //std::cin >> *(M + N*i + j);
            std::cin >> M[i][j];
        }
    }
}

void printMatrix(double (*M)[2]) {

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            //std::cout << *(M + N*i + j) << "\t";
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addMatrix(double (*A)[2], double (*B)[2], double (*C)[2]) {

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            //C[N*i + j] = A[N*i + j] + B[N*i + j];
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrix(double (*A)[2], double (*B)[2], double (*C)[2]) {

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            //C[N*i + j] = 0;
            C[i][j] = 0;
            for (int k = 1; k <= 2; k++) {
                //C[N*i + j] = C[N*i + j] + (A[N*i + k] * B[N*k + j]);
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    
    double A[N][N];
    double B[N][N];
    double C[N][N];
    double D[N][N];

    std::cout << "Matrix A" << std::endl;
    inputMatrix(A);

    std::cout << "Matrix B" << std::endl;
    inputMatrix(B);

    addMatrix(A, B, C);
    multiplyMatrix(A, B, D);

    std::cout << "Matrix C = A + B" << std::endl;
    printMatrix(C);

    std::cout << "Matrix D = AB" << std::endl;
    printMatrix(D);

    return 0;
}

