/*
 * exercise_5_5.cpp
 *
 * matrix multiplication
 *
 * Created on: Oct 05, 2012
 *  last edit: Oct 23, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cassert>

void fillMatrix(double **mat, int r, int c);
void printMatrix(double **mat, int r, int c);
double** allocateMatrix(int r, int c);
void deleteMatrix(double **mat, int r);
double** multiply(double **A, double **B, int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {

    int r1, r2, c1, c2;
    double **A = NULL, **B = NULL, **C = NULL;

    // init matrix A and B
    std::cout << "dimensions (r1, c1, r2, c2): ";
    std::cin >> r1 >> c1 >> r2 >> c2;

    A = allocateMatrix(r1, c1);
    B = allocateMatrix(r2, c2);
    std::cout << std::endl;

    std::cout << "fill elements of A:\n";
    fillMatrix(A, r1, c1);
    std::cout << std::endl;

    std::cout << "fill elements of B:\n";
    fillMatrix(B, r2, c2);
    std::cout << std::endl;
    
    // run methods to test
    C = multiply(A, B, r1, c1, r2, c2);

    std::cout << "print of matrix C:\n";
    printMatrix(C, r1, c2);
    std::cout << std::endl;

    // delete matrix A, B and C
    deleteMatrix(A, r1);
    deleteMatrix(B, r2);
    deleteMatrix(C, r1);

    return 0;
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
 * allocates matrix
 */
double** allocateMatrix(int r, int c) {

    double **mat = new double* [r];
    assert(mat != NULL);
    for (int row = 0; row < r; row++) {
        mat[row] = new double[c];
        assert(mat[row] != NULL);
    }

    return mat;
}

/*
 * deletes the matrix
 */
void deleteMatrix(double **mat, int r) {

    for (int row = 0; row < r; row++) {
        delete [] mat[row];
    }

    delete [] mat;
}

/*
 * function that multiplies matrices and returns new matrix over pointer
 * there are assertions to make sure that matrices can be multiplied
 * @param A first multiplicant
 * @param B second multiplicant
 * @param C pointer to new matrix, memory will be allocated for this matrix
 * @param r1 number of rows of the matrix A
 * @param c1 number of columnts of the matrix A
 * @param r2 number of rows of the matrix B
 * @param c2 number of columnts of the matrix B
 */
double** multiply(double **A, double **B, int r1, int c1, int r2, int c2) {
    assert(c1 == r2);

    double **C = allocateMatrix(r1, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) { 
            C[i][j] = 0;
            for (int k = 0; k < r2; k++) { 
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
     }

    return C;
}
