/*
 * exercise_1_3.cpp
 *
 * computes scalar product and euclidian norm of vectors of length 3
 *
 * Created on: Sept 24, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cmath>

#define N 3

void vectorInput(double vector[]) {
    for (int i = 0; i < N; i++) {
        std::cout << "vector[" << i << "]: ";
        std::cin >> vector[i];
    }
}

double scalarProduct(double vector1[], double vector2[]) {

    double theProduct = 0;

    for (int i = 0; i < N; i++) {
        theProduct = theProduct + (vector1[i] * vector2[i]);
    }

    return theProduct;
}

double euclidianNorm(double vector[]) {

    double theNorm = 0;

    for (int i = 0; i < N; i++) {
        theNorm += pow(vector[i], 2);
    }

    return pow(theNorm, 1./2);  //works
    //return sqrt(theNorm);     //works
}

int main(int argc, char* argv[]) {

    // vector definition
    double vector1[N];
    double vector2[N];
    
    // vector input (ugly)
    std::cout << "vector1 input" << std::endl;
    vectorInput( vector1 );
    
    std::cout << "vector2 input" << std::endl;
    vectorInput( vector2 );

    // scalar product
    std::cout << "the scalar product: " << scalarProduct(vector1, vector2) << std::endl;

    // Euclidian norms
    std::cout << "The Euclidian norm of vector1: " << euclidianNorm(vector1) << std::endl;
    std::cout << "The Euclidian norm of vector2: " << euclidianNorm(vector2) << std::endl;

    return 0;
}

