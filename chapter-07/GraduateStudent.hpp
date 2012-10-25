/*
 * GraduateStudent.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef GRADUATESTUDENT_HPP_
#define GRADUATESTUDENT_HPP_

#include "Student.hpp"

class GraduateStudent: public Student {
public:
	GraduateStudent();
	GraduateStudent(const std::string& name, const double fines = 0.0,
					const bool fullTime = true);

	virtual ~GraduateStudent() {}

	// Total money owed by graduate student
	virtual double MoneyOwed() const;
private:
	// Private data
	bool fullTime_;
};

#endif /* GRADUATESTUDENT_HPP_ */
