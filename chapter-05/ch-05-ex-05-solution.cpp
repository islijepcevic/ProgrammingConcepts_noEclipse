/*
 * chapter-05-exercise-05.cpp
 *
 * Matrix multiply of A(n x m) and B (p x q)
 * - matrices are each read from a text file passed as a command line parameter
 * - the file has the following format:
 * 		- first line n_rows n_cols
 * 		- following lines are the elements of the matrix
 * 		example:
 * 		4 3
 * 		1 2 3
 * 		4 5 6
 * 		7 8 9
 * 		10 11 12
 *
 * - run the exercise as: ./ch-05-ex-05-solutions A.dat B.dat
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <iostream>
#include <fstream>

#include "ArrayUtil.hpp"

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::cout << "Missing arguments. Please run the exercise as:\n"
				  << "       ./ch-05-ex-05-solutions A.dat B.dat"
				  << std::endl;
		return -1;
	}

	const char* file_name_A = argv[1];
	const char* file_name_B = argv[2];

	double** A;
	double** B;
	int m, n, p, q;

	Read(file_name_A, A, m, n);
	Read(file_name_B, B, p, q);

	double** C;
	Allocate(C, m, q);

	Multiply(A, B, m, n, p, q, C);

	std::cout << "Matrix A: " << std::endl;
	Print(A, m, n, std::cout);
	std::cout << "Matrix B: " << std::endl;
	Print(B, p, q, std::cout);
	std::cout << "Matrix C = A * B: " << std::endl;
	Print(C, m, q, std::cout);

	Delete(A, m);
	Delete(B, n);
	Delete(C, m);

	return 0;
}

