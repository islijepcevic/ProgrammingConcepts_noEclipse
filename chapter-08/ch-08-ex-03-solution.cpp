/*
 * chapter-08-exercise-03.cpp
 *
 * STL vector of complex numbers
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "ComplexNumber.hpp"

int main(int argc, char* argv[])
{
	std::vector<ComplexNumber> numbers;

	numbers.reserve(6);
	numbers.push_back(ComplexNumber(1.0, 2.0));
	numbers.push_back(ComplexNumber(2.0, -1.0));
	numbers.push_back(ComplexNumber(0.0, 0.0));

	std::cout << "Length of vector is "	<< numbers.size() << "\n";
	std::cout << "Entries of vector are\n";
	for (int i=0; i<3; i++)	{
		std::cout << numbers[i] << "\n";
	}

	std::vector<ComplexNumber>::const_iterator c;
	for (c=numbers.begin(); c!=numbers.end(); c++) {
		std::cout << *c << "\n";
	}

	numbers.insert(numbers.begin(), ComplexNumber(5.0, 5.0));
	numbers.insert(numbers.begin()+1, ComplexNumber(-1.1, -2.0));
	numbers.push_back(ComplexNumber(0.0, -2.0));

	std::cout << "Length of vector is "	<< numbers.size() << "\n";
	std::cout << "Entries of vector are\n";
	for (c=numbers.begin(); c!=numbers.end(); c++) {
		std::cout << *c << "\n";
	}

	numbers.erase(numbers.begin()+3,
	numbers.end());
	std::cout << "Length of vector is " << numbers.size() << "\n";
	std::cout << "Entries of vector are\n";
	for (c=numbers.begin(); c!=numbers.end(); c++) {
		std::cout << *c << "\n";
	}

	std::sort(numbers.begin(), numbers.end());
	std::cout << "Length of vector is "	<< numbers.size() << "\n";
	std::cout << "Entries of vector are\n";
	for (c=numbers.begin(); c!=numbers.end(); c++) {
		std::cout << *c << "\n";
	}

	return 0;
}
