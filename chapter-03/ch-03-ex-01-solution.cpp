/*
 * chapter-03-exercise-01.cpp
 *
 * Print to file with a given precision
 *
 * Created on: Sep 2, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	double x[4] = {0.0, 1.0, 1.0, 0.0};
	double y[4] = {0.0, 0.0, 1.0, 1.0};

	std::ofstream output_file("x_and_y.dat");
	// Check that file is properly openened.
	if (!output_file.is_open()) {
		std::cout << "Error opening output file." << std::endl;
		return 1;
	}

	// Output in scientific format with 10 significant figures
	// and always showing sign
	output_file.setf(std::ios::scientific);
	output_file.setf(std::ios::showpos);
	output_file.precision(10);
	// Write x vector ending with a new line
	for(int i = 0; i < 4; ++i) {
		output_file << x[i] << " ";
	}
	output_file << "\n";
	// Flush after writing vector x
	output_file.flush();
	// Do the same for y vector
	for(int i = 0; i < 4; ++i) {
		output_file << y[i] << " ";
	}
	output_file << "\n";
	// Flush after writing vector y
	output_file.flush();
	// Close the file when finished
	output_file.close();

    return 0;
}

