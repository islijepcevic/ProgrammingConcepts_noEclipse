/*
 * chapter-05-exercise-01.cpp
 *
 * Pointers and functions #1
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

void f(const int* const x)
{
	std::cout << "The value is: " << *x << std::endl;
}

int main(int argc, char* argv[])
{
	const int x = 5;

	f(&x);

    return 0;
}

