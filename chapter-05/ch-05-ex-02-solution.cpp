/*
 * chapter-05-exercise-02.cpp
 *
 * Pointers and functions #2
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

void f(int* const x)
{
	(*x)++;
}

int main(int argc, char* argv[])
{
	int x = 5;

	std::cout << "The value before calling f(x) is: " << x << std::endl;

	f(&x);

	std::cout << "The value after calling f(x) is: " << x << std::endl;

	return 0;
}

