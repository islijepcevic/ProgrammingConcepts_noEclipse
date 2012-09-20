/*
 * exercise-02.cpp
 *
 * Read two integers from the keyboard and write their product on the screen.
 *
 *  Created on: Jul 26, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// Read the two numbers from the keyboard
	std::cout << "Please input the first number. a= ";
	// Declare an integer variable and read a value from the keyboard
	int a;
	std::cin >> a;
	std::cout << "Please input the second number. b= ";
	// Same thing for the second number
	int b;
	std::cin >> b;

	// Compute and print the product;
	std::cout << "The product of " << a << " and " << b << " is: "
			  << a * b << std::endl;

	return 0;
}
