/*
 * Student.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include<string>

class Student {
public:
	// Default constructor
	Student();
	// Alternate constructors
	Student(const std::string& name);
	Student(const std::string& name, const double fines, const double fees);

	// Destructor
	virtual ~Student() {}

	// Get methods
	double GetFines() const;

	// Set methods
	void SetFines(const double fines);

	// Return the total money owed by the student
	virtual double MoneyOwed() const;

private:
	// Private data
	std::string name_;
	double fines_;
	double fees_;
};

#endif /* STUDENT_HPP_ */
