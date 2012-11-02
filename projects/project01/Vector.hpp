/*
 * Vector.hpp
 *
 * Dense vector class for the Conjugate gradient solver
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <vector>

class Vector {
public:
	// Constructor that allows specifying the dimension of the vector
	Vector(const unsigned long size);
	// Copy constructor
	Vector(const Vector& v);

	// Destructor
	~Vector() {}

	// Get methods
	// Get access to the std::vector which holds all the elements
	const std::vector<double>& GetRawVector() const { return mVector; }

	// Operators
	// Assignment operator
	Vector& operator=(const Vector& v);
	// Binary addition operator
	Vector operator+(const Vector& v) const;
	// Binary substraction operator
	Vector operator-(const Vector& v) const;
	// Binary vector * double operator
	Vector operator*(const double d) const;
	// Square bracket (const and non-const versions)
	const double operator[](const unsigned long i) const;
	double& operator[](const unsigned long i);
	// Dot product of two vectors
	double dot(const Vector& v) const;

	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	std::vector<double> mVector;
	unsigned long mSize;
};

#endif /* VECTOR_HPP_ */
