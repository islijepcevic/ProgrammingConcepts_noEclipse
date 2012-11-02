/*
 * chapter-02-exercise-05.cpp
 *
 * Newton-Raphson iteration for f(x) = exp(x) + x^3 + 5 = 0; x0 = 0;
 *
 * Created on: Aug 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	// Define a stopping precision
	double epsilon = 1e-6;
	int max_iter = 1000;
	double x_prev = 0.0;
	double x_next = 0.0;

	int num_iter = 0;
	do {
		x_prev = x_next;
		x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) + 5)
				/ (exp(x_prev) + 3 * pow(x_prev, 2));
		++num_iter;
		std::cout << "x[" << num_iter << "] = " << x_next << std::endl;
	} while ((std::abs(x_next - x_prev) > epsilon) && (num_iter < max_iter));

	if ((num_iter == max_iter) && (std::abs(x_next - x_prev) > epsilon)) {
		std::cout << "Max number of iterations reached without convergence"
				  << std::endl;
	} else {
		std::cout << "The solution to exp(x) + x^3 + 5 = 0 is: "
				  << x_next << std::endl;
	}

	return 0;
}
