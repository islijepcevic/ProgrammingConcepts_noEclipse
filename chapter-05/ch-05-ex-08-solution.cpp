/*
 * chapter-05-exercise-08.cpp
 *
 * Determinant of a matrix
 *
 * run the program as: ./ch-05-ex-06-solution M.mat
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

void ExtractMinor(double** M, const int size, const int col, double**& minor)
{
	for (int row = 1; row < size; ++row) {
		for (int k = 0; k < col; ++k) {
			minor[row - 1][k] = M[row][k];
		}
		for (int k = col + 1; k < size; ++k) {
			minor[row - 1][k - 1] = M[row][k];
		}
	}
}

double Determinant(double** M, const int size)
{
	if (size == 2) {
		return M[0][0] * M[1][1] - M[0][1] * M[1][0];
	} else {
		double det = 0;
		for (int col = 0; col < size; ++col) {
			double** minor;
			Allocate(minor, size - 1, size - 1);
			ExtractMinor(M, size, col, minor);
			det += M[0][col] * std::pow(-1.0, col)
				   * Determinant(minor, size - 1);
			Delete(minor, size - 1);
		}
		return det;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Missing arguments. Please run program as: "
				  << "  ./ch-05-ex-06-solution M.dat"
				  << std::endl;
		return -1;
	}

	const char* file_name = argv[1];

	double** M;
	int m, n;
	Read(file_name, M, m, n);

	std::cout << "The matrix is: " << std::endl;
	Print(M, m, n, std::cout);
	std::cout << "The determinant is: " << Determinant(M, m) << std::endl;

	Delete(M, m);

	return 0;
}

