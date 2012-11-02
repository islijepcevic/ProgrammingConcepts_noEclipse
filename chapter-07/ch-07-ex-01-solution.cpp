/*
 * chapter-07-exercise-01.cpp
 *
 * Student management classes
 *
 * Created on: Oct 25, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhDStudent.hpp"

int main(int argc, char* argv[])
{
	Student bill("Bill", 255.75, 999.99);
	std::cout << "Bill owes: " << bill.MoneyOwed() << std::endl;

	Student jeff("Jeff", -50.2, 999.99);
	std::cout << "Jeff owes: " << jeff.MoneyOwed() << std::endl;

	GraduateStudent dave("Dave", 10000.99, false);
	std::cout << "Dave owes: " << dave.MoneyOwed() << std::endl;

	PhDStudent brian("Brian", true);
	std::cout << "Brian owes: " << brian.MoneyOwed() << std::endl;

    return 0;
}
