/*
 * chapter-04-exercise-02.cpp
 *
 * Integer swap with pointers
 *
 * Created on: Sep 24, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	int i = 5, j = 10;

	std::cout << "i = " << i << " , j = " << j << std::endl;

	// Swap
	int *p1, *p2;
	p1 = &i;
	p2 = &j;

	*p1 = *p1 + *p2;
	*p2 = *p1 - *p2;
	*p1 = *p1 - *p2;

	// Check
	std::cout << "i = " << i << " , j = " << j << std::endl;

    return 0;
}

