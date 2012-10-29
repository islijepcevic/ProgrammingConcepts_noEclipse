#include <iostream>

#include "ComplexNumber.hpp"

#define ORDER 3

ComplexNumber** computeMatrixNaturalExp(ComplexNumber** matrix, int maxK = 10);
ComplexNumber** computeMatrixMultiply(ComplexNumber** mat1, ComplexNumber** mat2);
ComplexNumber** computeMatrixMultiply(ComplexNumber** matrix, double n);
void addMatrix(ComplexNumber** original, ComplexNumber** addition);

ComplexNumber** eye();

ComplexNumber** allocateMatrix();
void deleteMatrix(ComplexNumber** mat);

int main( int argc, char **argv )
{

    ComplexNumber** complexMatrix = allocateMatrix();

    // INPUT
    std::cout << "input complex matrix" << std::endl;
    for (int i = 0; i < ORDER; i++) {
        for (int j = 0; j < ORDER; j++) {
            std::cout << "element " << i << " " << j << ": ";
            double a, b;
            std::cin >> a >> b;

            // new ComplexNumber is created, and then copied over/to the
            // matrix element via assignment operator
            complexMatrix[i][j] = ComplexNumber(a, b);
        }
    }

    
    // COMPUTE EXPONENTIAL
    ComplexNumber** exponential = computeMatrixNaturalExp(complexMatrix);

    // OUTPUT
    for (int i = 0; i < ORDER; i++) {
        for (int j = 0; j < ORDER; j++) {
            std::cout << exponential[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    // CLEAN UP
    deleteMatrix(complexMatrix);
    deleteMatrix(exponential);
    
    return 0;
}

ComplexNumber** computeMatrixNaturalExp(ComplexNumber** matrix, int maxK) {

    ComplexNumber** exponential = allocateMatrix();
    ComplexNumber** currentPower = eye();

    for ( int step = 1; step < maxK; ++step )
    {
        // new power of the matrix
        ComplexNumber** newPow = computeMatrixMultiply(currentPower, matrix);
        ComplexNumber** tmp = currentPower;
        currentPower = newPow;
        delete tmp;

        // part of summation
        ComplexNumber** expPart = computeMatrixMultiply(currentPower, 1.0/step);
        addMatrix(exponential, expPart);
        deleteMatrix(expPart);
        
    }

    deleteMatrix(currentPower);

    return exponential;
}

/*
 * matrix multiply
 */
ComplexNumber** computeMatrixMultiply(ComplexNumber** mat1, ComplexNumber** mat2) {

    ComplexNumber** result = allocateMatrix();

    for (int i = 0; i < ORDER; i++)
    {
        for ( int j = 0; j < ORDER; ++j )
        {
            result[i][j] = 0;
            for ( int k = 0; k < ORDER; ++k )
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

ComplexNumber** computeMatrixMultiply(ComplexNumber** mat, double n)
{
    ComplexNumber** result = allocateMatrix();
    for (int i = 0; i < ORDER; i++) {
        for ( int j = 0; j < ORDER; ++j )
        {
            result[i][j] = mat[i][j] * n;
        }
    }

    return result;
}

void addMatrix(ComplexNumber** original, ComplexNumber** addition) {

    for (int i = 0; i < ORDER; i++) {
        for ( int j = 0; j < ORDER; ++j )
        {
            original[i][j] += addition[i][j];
        }
    }
}

ComplexNumber** eye()
{
    ComplexNumber** mat = allocateMatrix();
    for ( int i = 0; i < ORDER; ++i )
    {
        mat[i][i] = ComplexNumber(1);
    }

    return mat;
}

/*
 * MATRIX MEMORY ALLOCATION
 */
ComplexNumber** allocateMatrix() {
    ComplexNumber** complexMatrix = new ComplexNumber* [ORDER];
    for (int i = 0; i < ORDER; i++) {

        // creates an array of ComplexNumber objects, calling their default
        // (or empty) constructor
        complexMatrix[i] = new ComplexNumber[3];
    }

    return complexMatrix;
}

/*
 * matrix deletion
 */
void deleteMatrix(ComplexNumber** mat) {
    for ( int i = 0; i < ORDER; ++i )
    {
        delete [] mat[i];
    }

    delete [] mat;
}
