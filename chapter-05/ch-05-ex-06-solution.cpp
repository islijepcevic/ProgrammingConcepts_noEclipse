/*
 * chapter-05-exercise-06.cpp
 *
 * Modification of previous exercise: this time it performs M x v, v x M,
 * s * M, M * s, with M(nxm), v(n), s
 *
 * - run the exercise as: ./ch-05-ex-05-solutions A.dat v1.dat v2.dat s
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "ArrayUtil.hpp"

int main(int argc, char* argv[])
{
	if (argc != 5) {
		std::cout << "Missing arguments. Please run the exercise as:\n"
				  << "       ./ch-05-ex-05-solutions A.dat v1.dat v2.dat s"
				  << std::endl;
		return -1;
	}

	const char* file_name_A = argv[1];
	const char* file_name_v1 = argv[2];
	const char* file_name_v2 = argv[3];
	const double s = atoi(argv[4]);

	double** A;
	double *v1;
	double *v2;
	int m, n;

	Read(file_name_A, A, m, n);
	Read(file_name_v1, v1, m);
	Read(file_name_v2, v2, n);

	double* w1;
	Allocate(w1, n);
	Multiply(v1, A, m, n, w1);

	double* w2;
	Allocate(w2, m);
	Multiply(A, v2, m, n, w2);

	double** B;
	Allocate(B, m, n);
	Multiply(A, s, m, n, B);

	std::cout << "Matrix A: " << std::endl;
	Print(A, m, n, std::cout);

	std::cout << "Vector v1: " << std::endl;
	Print(v1, m, std::cout, false);

	std::cout << "Vector v2: " << std::endl;
	Print(v2, n, std::cout, true);

	std::cout << "Vector w1 = v1 * A: " << std::endl;
	Print(w1, n, std::cout, false);

	std::cout << "Vector w2 = A * v2: " << std::endl;
	Print(w2, m, std::cout, true);

	std::cout << "s = " << s << std::endl;

	std::cout << "Matrix B = s * A: " << std::endl;
	Print(B, m, n, std::cout);

	Delete(A, m);
	Delete(B, n);
	Delete(v1);
	Delete(v2);
	Delete(w1);
	Delete(w2);

	return 0;
}

