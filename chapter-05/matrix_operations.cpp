#include "matrix_operations.hpp"

#include <iostream>
#include <cassert>

/*
 * allocates matrix
 */
double** allocateMatrix(int r, int c) {

    double **mat = new double* [r];
    assert(mat != NULL);
    for (int row = 0; row < r; row++) {
        mat[row] = allocateVector(c);
    }

    return mat;
}

/*
 * allocates vector
 */
double* allocateVector(int size) {
    double *vector = new double[size];
    assert(vector != NULL);

    return vector;
}

/*
 * deletes the matrix
 */
void deleteMatrix(double **mat, int r) {

    for (int row = 0; row < r; row++) {
        deleteVector(mat[row]);
    }

    delete [] mat;
}

/*
 * deletes vector
 */
void deleteVector(double *vector) {
    delete [] vector;
}

/*
 * fils matrix from std input
 */
void fillMatrix(double **mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> mat[i][j];
        }
    }
}

/*
 * fils vector from std input
 */
void fillVector(double *vector, int r) {
    for (int i = 0; i < r; i++) {
            std::cin >> vector[i];
    }
}

/*
 * prints matrix
 */
void printMatrix(double **mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*
 * prints vector
 */
void printVector(double *vect, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << vect[i] << "\n";
    }
    std::cout << std::endl;
}
