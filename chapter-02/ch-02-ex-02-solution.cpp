/*
 * chapter-02-exercise-02.cpp
 *
 * Using the "if" clause
 *
 * Created on: Aug 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

int main(int argc, char* argv[])
{
	double p, q, x, y;
	int j;

	/*
	 * Read p
	 */
	std::cout << "Please input value of p (double): ";
	std::cin >> p;
	/*
	 * Read q
	 */
	std::cout << "Please input value of q (double): ";
	std::cin >> q;
	/*
	 * Read y
	 */
	std::cout << "Please input value of y (double): ";
	std::cin >> y;
	/*
	 * Read j
	 */
	std::cout << "Please input value of j (integer): ";
	std::cin >> j;

	/*
	 * Set x to 5 if either p is greater than or equal to q, or the variable
	 * j is not equal to 10
	 */
	if ((p >= q) || (j != 10)) {
		x = 5;
	}

	/*
	 * Set x to 5 if both y is greater than or equal to q, and the variable j
	 * is equal to 20. Otherwise set x to p
	 */
	if ((y >= q) && (j == 20)) {
		x = 5;
	} else {
		x = p;
	}

	/*
	 * Set x according to rule at ex 2.2.3
	 */
	if (p > q) {
		x = 0;
	} else if (j == 10) {
		x = 1;
	} else {
		x = 2;
	}

	// Print out x
	std::cout << "The value of x is: " << x << std::endl;

    return 0;
}

