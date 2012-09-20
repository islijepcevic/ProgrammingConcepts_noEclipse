/*
 * chapter-02-exercise-04.cpp
 *
 * Using the while loop
 *
 * Created on: Aug 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	int number = 0, sum = 0;

	/*
	 * Point 1. Terminate reading numbers when -1 is input by the user
	 */
	while (number >= 0) {
		sum += number;
		std::cout << "Please input numbers. Terminate with -1 :";
		std::cin >> number;
	}
	std::cout << "The sum of the numbers is: " << sum << std::endl;

	/*
	 * Point 2. Terminate reading numbers when -1 is input by the user
	 * or when sum exceedes 100.
	 */
	do {
		std::cout << "Please input numbers. Terminate with -1 :";
		std::cin >> number;
		if (number != -1) sum += number;
	} while ((number >= 0) && (sum <= 100));
	std::cout << "The sum of the numbers is: " << sum << std::endl;

	/*
	 * Point 3. Reset sum by inputting -2
	 */
	do {
		std::cout << "Please input numbers. Terminate with -1. Reset with -2 :";
		std::cin >> number;
		switch (number) {
		case -1:
			break;
		case -2:
			sum = 0;
			break;
		default:
			sum += number;
			break;
		}
	} while ((number >= 0) && (sum <= 100));
	std::cout << "The sum of the numbers is: " << sum << std::endl;

    return 0;
}

