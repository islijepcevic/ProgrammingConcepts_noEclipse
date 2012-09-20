/*
 * exercise-06.cpp
 *
 * Record the number of cars passing past your house each day for five
 * consecutive days and calculate the average.
 *
 *  Created on: Jul 27, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	// Store the five values in an integer array
	int number_of_cars[5];

	// Read in the five values
	std::cout << "Enter the number of cars on day one: ";
	std::cin >> number_of_cars[0];
	std::cout << "Enter the number of cars on day two: ";
	std::cin >> number_of_cars[1];
	std::cout << "Enter the number of cars on day three: ";
	std::cin >> number_of_cars[2];
	std::cout << "Enter the number of cars on day four: ";
	std::cin >> number_of_cars[3];
	std::cout << "Enter the number of cars on day five: ";
	std::cin >> number_of_cars[4];

	// Total number of cars that passed
	int total_cars = number_of_cars[0] + number_of_cars[1] + number_of_cars[2]
					 + number_of_cars[3] + number_of_cars[4];

	/* To compute the average we need to convert the total number of cars to a
	 * double
	 */
	double average = ((double) total_cars) / 5;

	/*
	 * NOTE: it is enough that one term of the division is a double. The
	 * following statement is equivalent to the previous:
	 * double average = total_cars / 5.0;
	 */

	std::cout << "The average number of cars is: " << average << std::endl;

	return 0;
}
