/*
 * exercise-03.cpp
 *
 * Declares two vectors of floating point values, computes the scalar product
 * and the Euclidean norm of both vectors
 *
 *  Created on: Jul 26, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
/*
 * We are using the functions pow and sqrt from the C/C++ standard library.
 * We need to include the "cmath" header
 */
#include <cmath>

int main(int argc, char* argv[])
{
	// Declare the vector v1 and assign values
	double v1[3];
	v1[0] = 1.0;
	v1[1] = -1.0;
	v1[2] = 2.0;

	// Declare the vector v2 and initialize it at the same time
	double v2[3] = {3.0, 4.5, 5.0};

	// Calculate the scalar product of the two vectors and print it on
	// the screen
	double scalar_prod = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	std::cout << "The scalar product is: " << scalar_prod << std::endl;

	// Calculate the Euclidean norm of the two vectors and print it
	double norm1 = std::sqrt(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);

	// Let's calculate the second norm using the pow function
	double norm2 = std::sqrt(std::pow(v2[0],2) + std::pow(v2[1],2)
							 + std::pow(v2[2],2));

	std::cout << "The Euclidean norm of the first vector is: "
			  << norm1 << std::endl
			  << "The Euclidean norm of the second vector is: "
			  << norm2 << std::endl;

	return 0;
}
