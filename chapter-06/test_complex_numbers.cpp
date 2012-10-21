/*
 * test_complex_numbers.cpp
 *
 * Complex matrix exponential
 *
 * Created on: Oct 19, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "ComplexNumber.hpp"

int main(int argc, char* argv[])
{
	ComplexNumber a(1.0, 0.0);
	std::cout << "a = " << a << std::endl;
	std::cout << "Re(a) = " << a.GetRealPart() << " Im(a) = "
			  << a.GetImaginaryPart() << std::endl;
	ComplexNumber b(0.0, -1.0);
	std::cout << "b = " << b << std::endl;
	ComplexNumber c(2.0, 3.0);
	std::cout << "c = " << c << std::endl;

	ComplexNumber d = a + b;
	std::cout << "d = a + b = " << d << std::endl;
	ComplexNumber e(a * b);
	std::cout << "e = a * b = " << e << std::endl;
	ComplexNumber f;
	f = b * c;
	std::cout << "f = b * c = " << f << std::endl;

	return 0;
}

