/*
 * Vector.hpp
 *
 * Dense vector class for the Conjugate gradient solver.
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <limits>

template<typename ValueType>
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

	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	std::vector<ValueType> mVector;
	unsigned long mSize;
};

// IMPLEMENTATION

template<typename ValueType>
Vector<ValueType>::Vector(const int size)
	: mVector(size, 0.0),
	  mSize(mVector.size())
{}

template<typename ValueType>
Vector<ValueType>::Vector(const Vector& v)
	: mVector(v.mVector),
	  mSize(mVector.size())
{}

// Operators

template<typename ValueType>
Vector<ValueType>& Vector<ValueType>::operator=(const Vector& v)
{
	mVector = v.mVector;
	mSize = mVector.size();

	return *this;
}

template<typename ValueType>
Vector<ValueType> Vector<ValueType>::operator+(const Vector& v) const
{
	assert(mSize <= static_cast<unsigned long>(std::numeric_limits<int>::max()));
	Vector tempV(static_cast<int>(mSize));
	for (unsigned int i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] + v[i];
	}

	return tempV;
}

template<typename ValueType>
Vector<ValueType> Vector<ValueType>::operator-(const Vector& v) const
{
	assert(mSize <= static_cast<unsigned long>(std::numeric_limits<int>::max()));
	Vector tempV(static_cast<int>(mSize));
	for (unsigned int i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] - v[i];
	}

	return tempV;
}

template<typename ValueType>
Vector<ValueType> Vector<ValueType>::operator*(const ValueType d) const
{
	assert(mSize <= static_cast<unsigned long>(std::numeric_limits<int>::max()));
	Vector tempV(static_cast<int>(mSize));
	for (unsigned int i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] * d;
	}

	return tempV;
}

// Const version of bracket operator
template<typename ValueType>
const ValueType Vector<ValueType>::operator[](const int i) const
{
	return mVector[i];
}

// Non-const version of bracked operator
template<typename ValueType>
ValueType& Vector<ValueType>::operator[](const int i)
{
	return mVector[i];
}

template<typename ValueType>
ValueType Vector<ValueType>::dot(const Vector& v) const
{
	ValueType p = 0.0;
	for (unsigned int i = 0; i < mSize; ++i) {
	p += mVector[i] * v[i];
	}

	return p;
}

template<typename ValueType>
void Vector<ValueType>::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mSize; ++i) {
		s << mVector[i] << "\n";
	}
}

#endif /* VECTOR_HPP_ */
