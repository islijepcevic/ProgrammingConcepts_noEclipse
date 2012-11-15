/*
 * chapter-09-exercise-02.cpp
 *
 * Exceptions 2
 *
 * Created on: Nov 15, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <cstdlib>

double* allocateVector(const long size)
{
	std::cout << "Trying to allocate " << size << " elements.\n";
	double* p;
	try {
		p = new double[size];
		std::cout << "Allocated " << size << " elements at address: " << p
				  << std::endl;
	}
	catch(std::bad_alloc& e) {
		std::cout << "Allocation failed, trying a smaller size.\n";
		p = allocateVector(size * 3 / 4);
	}

	return p;
}

int main(int argc, char* argv[])
{
	long size;
	if (argc == 2) {
		size = std::atol(argv[1]);
	} else {
		size = 10000000000L;
	}

	double* p_x = allocateVector(size);

	delete[] p_x;

	return 0;
}
