#include <iostream>
#include <cassert>
#include <cmath>

#include "matrix_operations.hpp"

int solve(double** A, double* b, int n);
void simplify(double** A, double* b, int n, int i);
bool pivoting(double **A, double* b, int n, int i);
double* reconstructSolutions(double **A, double* b, int n);

int main() {

    // init and input
    int n;
    double **A, *b;

    std::cout << "n: ";
    std::cin >> n;
    std::cout << std::endl;

    A = allocateMatrix(n, n);
    b = allocateVector(n);

    std::cout << "fill A\n";
    fillMatrix(A, n, n);
    std::cout << std::endl;

    std::cout << "fill b\n";
    fillVector(b, n);
    std::cout << std::endl;
    
    // solve system
    int result = solve(A, b, n);

    //extract solutions
    if (result == 0) {
        double *x = reconstructSolutions(A, b, n);
        std::cout << "solution x\n";

        for (int i = 0; i < n; i++) {
            std::cout << x[i] << " ";
        }
        std::cout << "\n";

        deleteVector(x);
    } else {
        std::cout << "no solution\n";
    }

    // delete and finish
    deleteMatrix(A, n);
    deleteVector(b);

    return 0;
}

/*
 * solves system Ax = b
 *
 * returns 0 if system has a solution
 *         1 if system has no solution
 *         2 if there are infinite solutions (will never happen, system is n x n)
 */
int solve(double** A, double* b, int n) {

    for (int i = 0; i < n-1; i++) {

        // check if pivoting needed
        if (fabs(A[i][i]) < 1e-6) {
            bool result = pivoting(A, b, n, i);
            if (!result) {
                return 1;
            }
        }

        // remove xi from all equations > i
        simplify(A, b, n, i);
    }

    return 0;
}

/**
 * makes all values below (i,i) -> 0
 */
void simplify(double** A, double* b, int n, int i) {

    // for all rows below i-th
    for (int j = i+1; j < n; j++) {
        double factor = A[j][i] / A[i][i];

        // for all elements in j-th row after the column i
        for (int k = i; k < n; k++) {
            A[j][k] -= factor * A[i][k];
        }
        b[j] -= factor * b[i];
    }
}

/*
 * pivoting for the i-th column
 */
bool pivoting(double **A, double* b, int n, int i) {

    // find row k to substitute
    bool kFound = false;
    int k;
    for (k = i+1; k < n; k++) {
        if (fabs(A[k][i]) > 1e-6) {
            kFound = true;
            break;
        }
    }
    if (!kFound) {
        return kFound;
    }

    // change rows i and k
    for (int j = i; j < n; j++) {
        double tmp = A[i][j];
        A[i][j] = A[k][j];
        A[k][j] = tmp;
    }
    double tmp = b[i];
    b[i] = b[k];
    b[k] = tmp;

    return kFound;
}

/*
 * solution x
 */
double* reconstructSolutions(double **A, double* b, int n) {

    double *x = allocateVector(n);

    for (int k = n - 1; k >= 0; k--) {
        x[k] = b[k];
        for (int i = k + 1; i < n; i++) {
            x[k] -= A[k][i] * x[i];
        }
        x[k] /= A[k][k];
    }

    return x;
}
