/*
 * exercise_5_6.cpp
 *
 * matrix multiplication
 *
 * Created on: Oct 24, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 *
 * REMARK: this will be made made just to compile, not to run or test
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
double* allocateVector(int size);
void deleteMatrix(double **mat, int r);
void deleteVector(double *vector);
double** multiply(double **A, double **B, int r1, int c1, int r2, int c2);
double* multiply(double **A, double *B, int r1, int c1, int r2);
double* multiply(double *A, double **B, int c1, int r2, int c2);
double** multiply(double A, double **B, int r2, int c2);
double** multiply(double **A, double B, int r1, int c1);

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

/*
 * function that multiplies matrix and a vector and returns new matrix over
 * pointer there are assertions to make sure that matrices can be multiplied
 * @param A first multiplicant (matrix)
 * @param B second multiplicant (a vector)
 * @param C pointer to new vector, memory will be allocated for this matrix
 * @param r1 number of rows of the matrix A
 * @param c1 number of columnts of the matrix A
 * @param r2 number of rows of the vector B
 */
double* multiply(double **A, double *B, int r1, int c1, int r2) {
    assert(c1 == r2);

    double *C = allocateVector(r1);

    for (int i = 0; i < r1; i++) {
        C[i] = 0;
        for (int k = 0; k < c1; k++) {
            C[i] = C[i] + (A[i][k] * B[k]);
        }
    }

    return C;
}


/*
 * function that multiplies a vector and a matrix and returns new matrix over
 * pointer there are assertions to make sure that matrices can be multiplied
 * @param A first multiplicant (vector)
 * @param B second multiplicant (matrix)
 * @param C pointer to new matrix, memory will be allocated for this matrix
 * @param c1 number of columnts of the vector A
 * @param r2 number of rows of the matrix B
 * @param c2 number of columnts of the matrix B
 */
double* multiply(double *A, double **B, int c1, int r2, int c2) {
    assert(c1 == r2);

    double *C = allocateVector(c2);

    for (int j = 0; j < c1; j++) {
        C[j] = 0;
        for (int k = 0; k < c2; k++) {
            C[j] = C[j] + (A[k] * B[k][j]);
        }
    }

    return C;
}

/*
 * function that multiplies matrix and a scalar and returns new matrix over
 * pointer there are assertions to make sure that matrices can be multiplied
 * @param A first multiplicant (matrix)
 * @param B second multiplicant (a vector)
 * @param C pointer to new matrix, memory will be allocated for this matrix
 * @param r2 number of rows of the matrix B
 * @param c2 number of columnts of the matrix B
 */
double** multiply(double A, double **B, int r2, int c2) {

    double **C = allocateMatrix(r2, c2);

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = A * B[i][j];
        }
    }

    return C;
}

/*
 * function that multiplies a scalar with a matrix and returns new matrix over
 * pointer there are assertions to make sure that matrices can be multiplied
 * @param A first multiplicant (matrix)
 * @param B second multiplicant (a vector)
 * @param C pointer to new matrix, memory will be allocated for this matrix
 * @param r1 number of rows of the matrix A
 * @param c1 number of columnts of the matrix A
 */
double** multiply(double **A, double B, int r1, int c1) {
    return multiply(B, A, r1, c1);
}

