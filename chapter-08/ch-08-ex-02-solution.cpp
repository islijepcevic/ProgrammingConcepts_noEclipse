/*
 * chapter-08-exercise-02.cpp
 *
 * Homebrew abs function
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

template<typename T>
T absolute(const T x)
{
	return (x >= 0) ? x : -1 * x;
}

// Same thing, but computation is done at compile time. Not possible for double
// type
template<int x>
struct absolute2
{
	const static int val = ((x >= 0) ? x : -1 * x);
};

int main(int argc, char* argv[])
{
	const int x1 = -2;
	const int x2 = -3;
	const double x3 = -7.39;
	std::cout << "The absolute value of " << x1 << " is " << absolute(x1)
			  << std::endl;
	std::cout << "The absolute value of " << x2 << " is " << absolute2<x2>::val
			  << " (computed at compile-time)" << std::endl;
	std::cout << "The absolute value of " << x3 << " is " << absolute(x3)
			  << std::endl;

    return 0;
}
