/*
 * exercise_3_2.cpp
 *
 * file input
 *
 * Created on: Sept 28, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open()) {
        return 1;
    }

    int number_of_rows = 0;
    while (!read_file.eof()) {
        double dummy1, dummy2, dummy3, dummy4;
        read_file >> dummy1 >> dummy2 >> dummy3 >> dummy4;
        number_of_rows++;
    }

    if (read_file.fail()) {
        number_of_rows--;
    }

    std::cout << "Number of rows = " << number_of_rows << std::endl;

    read_file.close();
    return 0;
}

