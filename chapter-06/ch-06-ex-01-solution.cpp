/*
 * chapter-06-exercise-01.cpp
 *
 * Complex matrix exponential
 *
 * Created on: Oct 18, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "ComplexMatrix3x3.hpp"

int main(int argc, char* argv[])
{
	// Allocate matrix A
	ComplexMatrix3x3 A;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)	{
			A.Set(i, j, ComplexNumber(i, j));
		}
	}

	// Calculate the exponential
	ComplexMatrix3x3 E;
	// There is a bug. Result doesn't correspond to Matlab
	A.Exponential(E, 1000);

	std::cout << "The matrix A is: \n";
	A.Print(std::cout);
	std::cout << "Exponential matrix is: \n";
	E.Print(std::cout);
	std::cout << std::endl;

    return 0;
}

