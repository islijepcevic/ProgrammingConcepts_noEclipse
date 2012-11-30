/*
 * Vector.cpp
 *
 * Dense vector class for the Conjugate gradient solver.
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: Simone
 */

#include "Vector.hpp"

// IMPLEMENTATION

Vector::Vector(const int size)
	: mGlobalSize(size),
	  mLocalSize(0),
	  mVector(0)
{
	int N ( MPI::COMM_WORLD.Get_size());
	int k ( MPI::COMM_WORLD.Get_rank());

	mLocalSize = size/N + (k < size % N);

	mVector.resize(mLocalSize,0.0);

}

Vector::Vector(const Vector& v)
	:  mGlobalSize(v.mGlobalSize),
	   mLocalSize(v.mLocalSize),
       mVector(v.mVector)
{}

// Operators

Vector& Vector::operator=(const Vector& v)
{
	 mGlobalSize = v.mGlobalSize;
	 mLocalSize =v.mLocalSize;
	 mVector = v.mVector;

	 return *this;
}

Vector Vector::operator+(const Vector& v) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] += v.mVector[i];
	}

	return tempV;
}

Vector Vector::operator-(const Vector& v) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] -= v.mVector[i];
	}

	return tempV;
}

Vector Vector::operator*(const ValueType d) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] *= d;
	}

	return tempV;
}

// Const version of bracket operator. Uses the global numbering
const ValueType Vector::operator[](const int i) const
{

	return mVector[i];
}

// Non-const version of bracked operator
ValueType& Vector::operator[](const int i)
{
	return mVector[i];
}

ValueType Vector::dot(const Vector& v) const
{
	ValueType p = 0.0;
	for (unsigned int i = 0; i < mSize; ++i) {
	p += mVector[i] * v[i];
	}

	return p;
}

ValueType Vector::norm() const
{
	return std::sqrt(dot(*this));
}


void Vector::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mSize; ++i) {
		s << mVector[i] << "\n";
	}
}

