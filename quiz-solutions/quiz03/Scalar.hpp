/*
 * Scalar.hpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#ifndef SCALAR_HPP_
#define SCALAR_HPP_

#include<iostream>

class Scalar
{
public:
	// Constructors
	// Empty constructor. Initializes to 0
	Scalar();
	// Constructor that takes the scalar value as a double
	Scalar(const double x);
	// Copy constructor
	Scalar(const Scalar& v);

	// Destructor
	~Scalar();

	// Accessor methods
	double GetX() const;

	// Set methods
	void SetX(const double x);

	// Operations
	// Assignment operator
	Scalar& operator=(const Scalar& v);
	// Unary minus operator
	Scalar operator-() const;
	// Binary addition operator
	Scalar operator+(const Scalar& v) const;
	// Binary substraction operator
	Scalar operator-(const Scalar& v) const;
	// Binary vector * double operator
	Scalar operator*(const double d) const;
	// The Euclidean norm
	double norm() const;

	// Friend functions
	friend std::ostream& operator<<(std::ostream& s, const Scalar& v);

private:
	// Data members
	double mX;
};

#endif /* Scalar_HPP_ */
