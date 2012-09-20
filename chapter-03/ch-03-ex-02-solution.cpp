/*
 * chapter-03-exercise-02.cpp
 *
 * Count number of rows in a file
 *
 * Created on: Sep 2, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream read_file("x_and_y.dat");
	if(!read_file.is_open()) {
		std::cout << "Error opening file." << std::endl;
		return 1;
	}

	int number_of_rows = 0;

	// This loop will read an empty line between the final EOL and the EOF
	// characters
	while(!read_file.eof()) {
		double dummy1, dummy2, dummy3, dummy4;
		read_file >> dummy1 >> dummy2 >> dummy3 >> dummy4;
		number_of_rows++;
	}
	std::cout << "Number of rows = "
			  << number_of_rows <<  " (false)" << std::endl;

	// We try again
	number_of_rows = 0;
	read_file.clear();
	read_file.seekg(std::ios::beg);
	while(!read_file.eof()) {
		std::string line;
		getline(read_file, line);
		if (line.compare("") != 0) {
			number_of_rows++;
		}
	}
	std::cout << "Number of rows = "
			  << number_of_rows << " (true)" << std::endl;

	read_file.close();

	return 0;
}

