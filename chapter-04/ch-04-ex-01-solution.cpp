/*
 * chapter-04-exercise-01.cpp
 *
 * Dynamic memory 1
 *
 * Created on: Sep 24, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// We declare an integer variable ...
	int i = 5;
	// And a pointer to an integer which holds the address of the first int
	int* p_j;
	p_j = &i;

	// Now we change the value of the integer through the pointer
	std::cout << "Value of i before: " << i << std::endl;
	// Next line is equivalent to *p_j = *p_j * 5;
	*p_j *= 5;
	std::cout << "Value of i after: " << i << std::endl;

	// We dynamically allocate an integer now
	int* p_k = new int;
	*p_k = i;

	std::cout << "Value stored at p_k: " << *p_k << std::endl;

	// Cleanup is very important with dynamic memory
	delete p_k;

    return 0;
}

