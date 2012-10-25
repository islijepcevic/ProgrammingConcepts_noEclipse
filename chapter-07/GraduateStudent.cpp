/*
 * GraduateStudent.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent()
	: fullTime_(true)
{}

GraduateStudent::GraduateStudent(const std::string& name, const double fines,
								 const bool fullTime)
	: Student(name, fines, 0.0),
	  fullTime_(fullTime)
{}


double GraduateStudent::MoneyOwed() const
{
	return GetFines();
}
