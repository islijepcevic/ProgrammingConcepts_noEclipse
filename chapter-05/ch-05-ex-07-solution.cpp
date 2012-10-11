/*
 * chapter-05-exercise-07.cpp
 *
 * p-norm of a vector
 *
 * run the program as: ./ch-05-ex-06-solution v1.dat p
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "ArrayUtil.hpp"

/*
 * This is the prototype (declaration) of the function. This is needed to
 * define default values for function parameters. Some compilers will not allow
 * definining default values for parameter in the function implementation
 * (definition)
 */
double CalculateNorm(double* x, const int vecSize, const int p = 2);

// This is the function definition
double CalculateNorm(double* x, const int vecSize, const int p)
{
	double sum = 0.0;
	// Loop over the elements x_i of x, incrementing sum by |x_i|**p
	for (int i = 0; i < vecSize; ++i) {
		double temp = std::fabs(x[i]);
		sum += std::pow(temp, p);
	}
	// Return the p-th root of sum
	return std::pow(sum, 1.0 / p);
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Missing arguments. Please run program as: "
				  << "  ./ch-05-ex-06-solution v1.dat p\n"
				  << "The integer p is optional but the file name v1.dat is not"
				  << std::endl;
		return -1;
	}

	const char* file_name = argv[1];

	double* v;
	int size;
	Read(file_name, v, size);

	double norm;
	int p = 0;
	if (argc > 2) {
		p = atoi(argv[2]);
		norm = CalculateNorm(v, size, p);
	} else {
		// This is just to demonstrate default values for parameters
		norm = CalculateNorm(v, size);
		p = 2;
	}

	std::cout << "||v||_" << p << " = " << norm << std::endl;

	Delete(v);

	return 0;
}

