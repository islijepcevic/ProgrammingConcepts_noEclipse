/*
 * chapter-03-exercise-03.cpp
 *
 * Implements the backward Euler method to solve:
 * 		dy / dx = -y, y_0 = 1, 0 <= x <= 1
 *
 * 	The discretization for N grid points is:
 * 		- step size: h = 1 / (N - 1)
 * 		- grid points: x_n = n * h
 * 		- solution: y_(n) - y_(n-1) / h = - y_n ; n = 1,2,...N-1
 *
 *
 * Created on: Sep 2, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[])
{
	// Read from the command line the number of grid points to use
	int N;
	std::cout << "Please input the number of grid points. N = ";
	std::cin >> N;
	assert(N > 1);

	// Calculate step size h
	double h = 1.0 / (N - 1);
	std::cout << "Computed step size. h = " << h << std::endl;

	// Start computing the grid points and the solution in these points
	// At each step, we output the solution to disk
	std::ofstream output_file("xy.dat");
	if (!output_file.is_open()) {
		std::cout << "Error opening output file." << std::endl;
		return 1;
	}
	output_file.setf(std::ios::scientific);
	output_file.setf(std::ios::showpos);
	output_file.precision(9);

	// x_(n-1) = x_0 = 0
	double x_prev = 0;
	// x_(n) = x_1 = h;
	double x_next = h;
	// y_(n-1) = y_0 = 1;
	double y_prev = 1;
	double y_next;

	output_file << x_prev << " " << y_prev << std::endl;

	while (x_next <= 1.0) {
		y_next = y_prev / (h + 1.0);
		output_file << x_next << " " << y_next << std::endl;
		y_prev = y_next;
		x_prev = x_next;
		x_next = x_prev + h;
	}

	output_file.close();

	return 0;
}

