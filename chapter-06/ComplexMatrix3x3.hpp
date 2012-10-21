/*
 * ComplexMatrix3x3.hpp
 *
 *  Created on: Oct 19, 2012
 *      Author: rpopescu
 */

#ifndef COMPLEXMATRIX3X3_HPP_
#define COMPLEXMATRIX3X3_HPP_

#include <iostream>

#include "ComplexNumber.hpp"

class ComplexMatrix3x3 {
public:
	// Constructors and destructor
	ComplexMatrix3x3();
	ComplexMatrix3x3(const ComplexMatrix3x3& m);
	virtual ~ComplexMatrix3x3();

	// Get methods
	ComplexNumber Get(const int i, const int j) const;

	// Set methods
	void Set(const int i, const int j, const ComplexNumber& value);

	// Public methods
	bool IsZero() const;
	ComplexMatrix3x3 PowerOverFact(const int n) const;
	void Exponential(ComplexMatrix3x3& E, const int power) const;
	void Print(std::ostream& s = std::cout);

	// Operators
	ComplexMatrix3x3& operator=(const ComplexMatrix3x3& m);
	ComplexMatrix3x3 operator*(const double d) const;
	ComplexMatrix3x3 operator+(const double d) const;
	ComplexMatrix3x3 operator+(const ComplexMatrix3x3& m) const;
	ComplexMatrix3x3 operator*(const ComplexMatrix3x3& m) const;

private:
	ComplexNumber** mMatrix;
};

#endif /* COMPLEXMATRIX3X3_HPP_ */
