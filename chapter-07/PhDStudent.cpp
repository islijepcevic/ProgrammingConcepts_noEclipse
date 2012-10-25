/*
 * PhDStudent.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "PhDStudent.hpp"

PhDStudent::PhDStudent(const std::string& name, const bool fullTime)
	: GraduateStudent(name, 0.0, fullTime)
{}

double PhDStudent::MoneyOwed()
{
	return 0.0;
}
