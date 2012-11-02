/*
 * chapter-04-exercise-03.cpp
 *
 * Dynamic memory for vectors
 *
 * Created on: Sep 24, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// Do everything one billion times
	for (int n = 0; n < 1000000000; ++n) {
		// Allocate vectors
		double* v = new double[3];
		double* w = new double[3];

		// Assign values
		v[0] = 1.0; v[1] = 2.0; v[2] = 3.0;
		w[0] = 4.0; w[1] = 5.0; w[2] = 6.0;

		// Compute scalar product
		double s = 0;
		for (int i = 0; i < 3; ++i) {
			s += v[i] * w[i];
		}
		std::cout << "The scalar product of v and w is: " << s << std::endl;

		// Cleanup
		delete[] v;
		delete[] w;
	}

    return 0;
}

