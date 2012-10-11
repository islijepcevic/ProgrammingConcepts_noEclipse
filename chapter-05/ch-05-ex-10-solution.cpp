/*
 * chapter-05-exercise-10.cpp
 *
 * Gauss with partial pivoting
 *
 * run the program as: ./ch-05-ex-10-solution Agauss.dat bgauss.dat
 *
 * Created on: Oct 11, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "ArrayUtil.hpp"
#include "Gauss.hpp"

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::cout << "Missing arguments. Please run program as: "
				  << "  ./ch-05-ex-06-solution Agauss.dat bgauss.dat"
				  << std::endl;
		return -1;
	}

	const char* file_name_A = argv[1];
	const char* file_name_b = argv[2];

	double** A;
	int m, n;
	Read(file_name_A, A, m, n);

	double* b;
	Read(file_name_b, b, n);

	double* x;
	Allocate(x, n);

	// Solve Ax = b
	GaussPartialPivoting(A, b, n);
	BackwardSolve(A, b, n, x);

	std::cout << "The matrix A is: " << std::endl;
	Print(A, m, n, std::cout);
	std::cout << "The rhs b is: " << std::endl;
	Print(b, n, std::cout, true);
	std::cout << "The solution x is: " << std::endl;
	Print(x, n, std::cout, true);

	Delete(A, m);
	Delete(b);
	Delete(x);

	return 0;
}

