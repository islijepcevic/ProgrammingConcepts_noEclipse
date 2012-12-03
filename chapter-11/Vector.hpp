/*
 * Vector.hpp
 *
 * Dense vector class for the Conjugate gradient solver.
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: Simone
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <limits>
#include <mpi.h>

typedef double ValueType;

class Vector {
public:
	// Constructor that allows specifying the dimension of the vector
	Vector(const int size);
	// Copy constructor
	Vector(const Vector& v);

	// Destructor
	~Vector() {}

	// Operators
	// Assignment operator
	Vector& operator=(const Vector& v);
	// Binary addition operator
	Vector operator+(const Vector& v) const;
	// Binary substraction operator
	Vector operator-(const Vector& v) const;
	// Binary vector * ValueType operator
	Vector operator*(const ValueType d) const;
	// Square bracket (const and non-const versions)
	const ValueType operator[](const int i) const;
	ValueType& operator[](const int i);
	// Dot product of two vectors
	ValueType dot(const Vector& v) const;
	// Euclidean norm of vector
	ValueType norm() const;


	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	unsigned long mGlobalSize;
	unsigned long mLocalSize;

	std::vector<ValueType> mVector;
};

#endif /* VECTOR_HPP_ */
