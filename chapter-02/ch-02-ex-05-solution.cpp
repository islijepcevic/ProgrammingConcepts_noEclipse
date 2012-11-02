/*
 * chapter-02-exercise-05.cpp
 *
 * Inverse for 2x2 matrix
 *
 * Created on: Aug 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
	double A[2][2] = {{4, 10}, {1, 1}};

	// Compute the determinant
	double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	assert(det != 0);

	// Compute the inverse
	double Ainv[2][2];
	Ainv[0][0] = A[1][1] / det;
	Ainv[0][1] = - A[0][1] / det;
	Ainv[1][0] = - A[1][0] / det;
	Ainv[1][1] = A[0][0] / det;

	// Print out inverse
	std::cout << "The inverse of A is:" << std::endl;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			std::cout << Ainv[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
