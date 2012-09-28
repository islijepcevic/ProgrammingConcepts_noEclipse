/*
 * exercise_2_6.cpp
 *
 * Newton-Rapson iteration
 *
 * Created on: Sept 27, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cassert>
//#include <vector>
#include <cmath>

using namespace std;

/**
 * the given function for the exercise
 * @param x input variable
 * @return the value of the function
 */
double f(double x) {
    return exp(x) + pow(x, 3.) - 5;
}

/**
 * the derivation of the given function over x
 * @param x input variable
 * @return the value of the function
 */
double f_prime(double x) {
    return exp(x) + 2 * pow(x, 2.);
}

/**
 * the next step of Newton-Rapson iteration
 * @param oldX previous value of x
 * @return next value of x
 */
double computeNextX(double oldX) {
    return oldX - f(oldX) / f_prime(oldX);
}


int main(int argc, char* argv[]) {


    double epsilon = 1e-15;
    double x_prev = 0.;
    double x_next = 1000007;

    while (fabs( f(x_next) ) > epsilon) {

        x_next = computeNextX( x_prev );
        assert(fabs( f(x_next) ) < fabs( f(x_prev) ));

        cout << "xi=" << x_next << "\tf(xi)=" << f(x_next)
            << "\tf'(xi)=" << f_prime(x_next) << endl;

        x_prev = x_next;
    }

    return 0;
}


