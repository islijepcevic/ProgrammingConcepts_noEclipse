/*
 * exercise05.cpp
 *
 * Input your first and last name as two separate strings and
 * use them to print your full name on the screen.
 *
 *  Created on: Jul 27, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
// We are using std::string variables, so we need to include the string header
#include <string>

int main(int argc, char* argv[])
{
	// Read the first and last name as two separate strings
	std::string first_name;
	std::cout << "Please input your first name: ";
	std::cin >> first_name;
	std::string last_name;
	std::cout << "Please input your last name: ";
	std::cin >> last_name;

	// Print the full name as two arguments to std::cout
	std::cout << "Your full name is " << first_name << " " << last_name
			  << std::endl;

	// Or concatenate the two strings and print the new variable
	std::string full_name = first_name + " " + last_name;
	std::cout << "Your full name is " << full_name << std::endl;

    return 0;
}
