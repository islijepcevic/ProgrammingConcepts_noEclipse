#include <iostream>
#include <cassert>

#include "matrix_operations.hpp"

double computeDeterminant(double** mat, int order, int column = 0);
double** getSmallerMatrix(double** original, int order, int row, int column);

int main() {

    int order;
    double **A = NULL;

    // init matrix A and B
    std::cout << "order of the matrix: ";
    std::cin >> order;

    A = allocateMatrix(order, order);
    std::cout << std::endl;

    std::cout << "fill elements of A:\n";
    fillMatrix(A, order, order);
    std::cout << std::endl;

    
    // determinant
    std::cout << "determinant is: " << computeDeterminant(A, order) << std::endl;

    // finishing
    deleteMatrix(A, order);

    return 0;
}

/**
 * recursively computes determinant of the matrix, on the given column
 * @param mat - the matrix whose determinant is computed
 * @param order - the order of the matrix
 * @param column - column by which to compute determinant, default 0
 */
double computeDeterminant(double** mat, int order, int column) {
    assert(column < order);
    assert(order >= 1);

    if (order == 1) {
        return mat[0][0];
    }

    double determinant = 0;
    int sign = 1;

    for (int i = 0; i < order; i++) {

        double **tempMat = getSmallerMatrix(mat, order, i, column);

        determinant += sign * mat[i][column] 
                            * computeDeterminant(tempMat, order - 1);

        deleteMatrix(tempMat, order - 1);

        sign *= -1;
    }

    return determinant;
}

/*
 * function that creates new smaller matrix without row 'row' and column
 * 'column' from the matrix 'original'
 */
double** getSmallerMatrix(double** original, int order, int row, int column) {

    double **smallMat = allocateMatrix(order - 1, order - 1);

    int additionRow = 0, additionCol = 0;
    
    for (int i = 0; i < order; i++) {
        if (i == row) {
            additionRow++;
            continue;
        }

        additionCol = 0;

        for (int j = 0; j < order; j++) {
            if (j == column) {
                additionCol++;
                continue;
            }

            smallMat[i - additionRow][j - additionCol] = original[i][j];
        }
    }

    return smallMat;
}

