/*
 * quiz-02-solution.cpp
 *
 * Quaternion operations
 *
 * Created on: Oct 18, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "Quaternion.hpp"
#include "Vector3D.hpp"

int main(int argc, char* argv[])
{
	// Declare two quaternions
	Quaternion q1(1.0, 0.0, 2.0, 3.0);

	// For the second quaternion, we can use another type of constructor
	Vector3D v2(1.0, 1.0, -1.0);
	Quaternion q2(2.0, v2);

	// a = q1 + q2
	Quaternion a(q1 + q2);
	std::cout << "a = q1 + q2: " << a << std::endl;

	// b = q1 - q2
	Quaternion b;
	b = q1 - q2;
	std::cout << "b = q1 - q2: " <<	b << std::endl;

	// c = q1 * q2
	Quaternion c = q1 * q2;
	std::cout << "c = q1 * q2: " << c << std::endl;

	// d = q2 * q1
	Quaternion d(q2 * q1);
	std::cout << "d = q2 * q1: " << d << std::endl;

    return 0;
}

