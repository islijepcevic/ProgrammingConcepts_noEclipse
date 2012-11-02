/*
 * chapter-04-exercise-04.cpp
 *
 * Dynamic memory for 2D matrices
 *
 * Created on: Sep 24, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// Do everything one billion times
	for (int n = 0; n < 1000000000; ++n) {
		// Allocate matrices
		double** A = new double*[2];
		double** B = new double*[2];
		double** C = new double*[2];
		for (int i = 0; i < 2; ++i) {
			A[i] = new double[2];
			B[i] = new double[2];
			C[i] = new double[2];
		}

		// Assign values to A and B
		A[0][0] = 1.0; A[0][1] = 2.0; A[1][0] = 3.0; A[1][1] = 4.0;
		B[0][0] = 1.0; B[0][1] = 2.0; B[1][0] = 3.0; B[1][1] = 4.0;

		// Compute C = A + B
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		std::cout << "The matrix C is: " << std::endl;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				std::cout << C[i][j] << " ";
			}
			std::cout << std::endl;
		}

		// Cleanup
		for (int i = 0; i < 2; ++i) {
			delete[] A[i];
			delete[] B[i];
			delete[] C[i];
		}
		delete[] A;
		delete[] B;
		delete[] C;
	}

    return 0;
}

