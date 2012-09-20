/*
 * chapter-02-exercise-04.cpp
 *
 * Vector operations with loops
 *
 * Created on: Aug 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	double u[3] = {1.0, 2.0, 3.0};
	double v[3] = {6.0, 5.0, 4.0};
	double A[3][3] = {{1.0, 5.0, 0.0},
					  {7.0, 1.0, 2.0},
					  {0.0, 0.0, 1.0}};
	double B[3][3] = {{-2.0, 0.0, 1.0},
					  {1.0, 0.0, 0.0},
					  {4.0, 1.0, 0.0}};
	double w[3];
	for (int i = 0; i < 3; ++i) {
		w[i] = u[i] - 3.0 * v[i];
	}

	// x = u - v
	double x[3] = {0.0, 0.0, 0.0};
	for (int i = 0; i < 3; ++i) {
		x[i] = u[i] - v[i];
	}

	// y = Au
	double y[3] = {0.0, 0.0, 0.0};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			y[i] += A[i][j] * u[j];
		}
	}

	// z = Au - v
	double z[3] = {0.0, 0.0, 0.0};
	for (int i = 0; i < 3; ++i) {
		z[i] -= v[i];
		for (int j = 0; j < 3; ++j) {
			z[i] += A[i][j] * u[j];
		}
	}

	// C = 4A - 3B
	double C[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			C[i][j] = 4 * A[i][j] - 3 * B[i][j];
		}
	}

	// D = AB
	double D[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				D[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	// Print w
	std::cout << "w is: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << w[i] << " ";
	}
	std::cout << std::endl;

	// Print x
	std::cout << "x is: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

	// Print y
	std::cout << "y is: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << y[i] << " ";
	}
	std::cout << std::endl;

	// Print z
	std::cout << "z is: ";
	for (int i = 0; i < 3; ++i) {
		std::cout << z[i] << " ";
	}
	std::cout << std::endl;

	// Print C
	std::cout << "C is:" << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << C[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Print D
	std::cout << "D is:" << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << D[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
