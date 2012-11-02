/*
 * Student.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "Student.hpp"

#include<iostream>

Student::Student()
	: name_(),
	  fines_(0.0),
	  fees_(0.0)
{}

Student::Student(const std::string& name)
	: name_(name),
	  fines_(0.0),
	  fees_(0.0)
{}

Student::Student(const std::string& name, const double fines,
				 const double fees)
	: name_(name),
	  fines_(fines),
	  fees_(fees)
{
	SetFines(fines);
}

double Student::GetFines() const
{
	return fines_;
}

void Student::SetFines(const double fines)
{
	if (fines >= 0.0) {
		fines_ = fines;
	} else {
		std::cout << "The fines owed by a student must "
				  << "be a non-negative number. Setting fines to zero."
				  << std::endl;
		fines_ = 0.0;
	}
}

double Student::MoneyOwed() const
{
	return fines_ + fees_;
}
