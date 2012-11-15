/*
 * chapter-09-exercise-01.cpp
 *
 * Exceptions
 *
 * Created on: Nov 15, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "Exception.hpp"
#include "FileNotOpenException.hpp"

typedef std::vector<double> Vector;

void ReadFile(const std::string& fileName, Vector x, Vector y)
{
    std::ifstream read_file(fileName.c_str());
    if (read_file.is_open() == false) {
        throw FileNotOpenException("File can’t be opened");
    }

    // Since the vectors are allocated with 3 elements, when i = 3
    // the at(i) method will throw a std::out_of_range exception
    for (int i=0; i<6; i++) {
        read_file >> x.at(i) >> y.at(i);
    }

    read_file.close();

    std::cout << fileName <<" read successfully\n";
}

int main(int argc, char* argv[])
{
	// Allocating a smaller vector than required
    std::vector<double> x(3);
	std::vector<double> y(3);
    try	{
	ReadFile("Output.dat", x, y);
    }
    catch (FileNotOpenException& error) {
        error.PrintDebug();
        std::cout << "Couldn’t open Output.dat\n";
        std::cout << "Give alternative location\n";
        std::string file_name;
        std::cin >> file_name;
        ReadFile(file_name, x, y);
    }
    catch (std::out_of_range& error) {
        error.what();
        std::cout << "Accessing element out of range.\n";
    }
    catch (Exception& error) {
        error.PrintDebug();
        std::cout << "Program exiting.\n";
    }

    return 0;
}
