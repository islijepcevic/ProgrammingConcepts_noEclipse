/*
 * exercise_1_2.cpp
 *
 * writes product of two input integers
 *
 * Created on: Sept 24, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>

int main(int argc, char* argv[]) {

    int a, b;

    std::cout << "enter first number: ";
    std::cin >> a;

    std::cout << "enter second number: ";
    std::cin >> b;
    

    std::cout << a << " * " << b << " = " << a * b << endl;

    return 0;
}

