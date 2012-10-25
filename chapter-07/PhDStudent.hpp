/*
 * PhDStudent.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef PHDSTUDENT_HPP_
#define PHDSTUDENT_HPP_

#include "GraduateStudent.hpp"

class PhDStudent: public GraduateStudent {
public:
	PhDStudent() {}
	PhDStudent(const std::string& name, const bool fullTime);
	virtual ~PhDStudent() {}

	// PhD students don't owe money?
	virtual double MoneyOwed();
};

#endif /* PHDSTUDENT_HPP_ */
