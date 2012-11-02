/*
 * exercise04.cpp
 *
 * Declared four 2x2 floating point matrices A, B, C, D and computes:
 * C = A + B and D = AB
 *
 *  Created on: Jul 26, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// Declare A and assign values to it
	double A[2][2];
	A[0][0] = 0.5;
	A[0][1] = 2.0;
	A[1][0] = 1.5;
	A[1][1] = 4.0;

	// Declare B and initialize it at the same time
	double B[2][2] = {{5.0, 2.5}, {3.5, 7.5}};

	double C[2][2];
	double D[2][2];

	// Compute the values of C
	C[0][0] = A[0][0] + B[0][0];
	C[0][1] = A[0][1] + B[0][1];
	C[1][0] = A[1][0] + B[1][0];
	C[1][1] = A[1][1] + B[1][1];

	// Compute the values of D
	D[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	D[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	D[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	D[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	// Print the results
	std::cout << "The matrix C is: " << std::endl
			  << C[0][0] << " " << C[0][1] << std::endl
			  << C[1][0] << " " << C[1][1] << std::endl;
	std::cout << "The matrix D is: " << std::endl
			  << D[0][0] << " " << D[0][1] << std::endl
			  << D[1][0] << " " << D[1][1] << std::endl;

	return 0;
}
