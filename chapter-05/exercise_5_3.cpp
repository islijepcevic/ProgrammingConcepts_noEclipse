/*
 * exercise_5_3.cpp
 *
 * swapping functions
 *
 * Created on: Oct 05, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
using namespace std;

/*
 * function that swaps values using pointers
 */
void swapP(double *x, double *y) {
    double tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
 * function that swaps values using references
 */
void swapR(double &x, double &y) {
    double tmp = x;
    x = y;
    y = tmp;
}

int main(int argc, char* argv[]) {

    double x = 1.0, y = 2.0;

    cout << "before: x=" << x << " y=" << y << endl;

    swapP(&x, &y);
    cout << "first: x=" << x << " y=" << y << endl;

    swapR(x, y);
    cout << "second: x=" << x << " y=" << y << endl;

    return 0;
}

