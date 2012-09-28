/*
 * exercise_3_1.cpp
 *
 * file i/o
 *
 * Created on: Sept 28, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cassert>
#include <fstream>

void writeVector(std::ofstream &outStream, double vector[], int size) {

    for (int i = 0; i < size; i++) {
        outStream << vector[i] << " ";
    }
    outStream << std::endl;
    outStream.flush();
}

int main(int argc, char* argv[]) {

    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    std::ofstream outStream("x_and_y.dat");
    assert(outStream.is_open());

    outStream.setf(std::ios::scientific);
    outStream.setf(std::ios::showpos);
    outStream.precision(9);

    writeVector(outStream, x, 4);
    writeVector(outStream, y, 4);

    outStream.close();

    return 0;
}

