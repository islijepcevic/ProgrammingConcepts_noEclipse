/*
 * chapter-05-exercise-03.cpp
 *
 * Swap functions
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

void swap1(double* const x, double* const y)
{
	const double temp = *x;
	*x = *y;
	*y = temp;
}

void swap2(double& x, double& y)
{
	const double temp = x;
	x = y;
	y = temp;
}

int main(int argc, char* argv[])
{
	double x =  2.73;
	double y = -3.141592;

	std::cout << "The numbers are: " << x << " " << y << std::endl;

	swap1(&x, &y);

	std::cout << "We've swapped the numbers: " << x << " " << y << std::endl;

	swap2(x, y);

	std::cout << "And swapped them back: " << x << " " << y << std::endl;

	return 0;
}

