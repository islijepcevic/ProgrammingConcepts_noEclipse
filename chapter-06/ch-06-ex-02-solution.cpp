/*
 * chapter-06-exercise-02.cpp
 *
 * Test for class of 2x2 double precision matrix
 *
 * Created on: Oct 21, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "DoubleMatrix2x2.hpp"

int main(int argc, char* argv[])
{
	// Build a matrix with the empty constructor
	DoubleMatrix2x2 A;
	std::cout << "Matrix A is:\n" << A << std::endl;

	// Build a matrix with the non-empty constructor
	DoubleMatrix2x2 B(1.0, 2.0, 3.0, 4.0);
	std::cout << "Matrix B is:\n" << B << std::endl;

	// Build a matrix with the copy constructor
	DoubleMatrix2x2 C(B);
	std::cout << "Matrix C is:\n" << C << std::endl;

	// Test the determinant method
	std::cout << "The determinant of C is: " << C.Determinant() << std::endl;

	// Test inverse
	DoubleMatrix2x2 InvC = C.Inverse();
	std::cout << "The inverse of C is:\n" << InvC << std::endl;

	// Test the assignment operator
	DoubleMatrix2x2 D;
	D = C;
	std::cout << "Matrix D is:\n" << D << std::endl;

	// Testing some operators
	DoubleMatrix2x2 E(-D);
	E = E + D;
	E = E - D;
	E.Multiply(2.0);
	std::cout << "Matrix E is:\n" << E << std::endl;

    return 0;
}
