/*
 * exercise_3_3.cpp
 *
 * implicit Euler method
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

int main(int argc, char* argv[]) {

    double N;
    std::cout << "Enter number of grid points: ";
    std::cin >> N;

    double h = 1.0 / N;

    double x = 0;
    double y = 1;

    std::ofstream outStream("xy.dat");
    assert(outStream.is_open());

    while (x <= 1.) {

        // output
        outStream << x << "\t" << y <<  std::endl;

        // step of the euler method
        y = - y / (1 + h);
        x += h;
    }
    outStream.close();

    return 0;
}

