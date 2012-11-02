/*
 * Vector.hpp
 *
 * Dense vector class for the Conjugate gradient solver
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#include "Vector.hpp"

#include <cmath>

// Constructors

Vector::Vector(const unsigned long size)
	: mVector(size, 0.0),
	  mSize(mVector.size())
{}

Vector::Vector(const Vector& v)
	: mVector(v.GetRawVector()),
	  mSize(mVector.size())
{}

// Operators

Vector& Vector::operator=(const Vector& v)
{
	mVector = v.GetRawVector();
	mSize = mVector.size();

	return *this;
}

Vector Vector::operator+(const Vector& v) const
{
	Vector tempV(mSize);
	for (unsigned long i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] + v[i];
	}

	return tempV;
}

Vector Vector::operator-(const Vector& v) const
{
	Vector tempV(mSize);
	for (unsigned long i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] - v[i];
	}

	return tempV;
}

Vector Vector::operator*(const double d) const
{
	Vector tempV(mSize);
	for (unsigned long i = 0; i < mSize; ++i) {
		tempV[i] = mVector[i] * d;
	}

	return tempV;
}

// Const version of bracket operator
const double Vector::operator[](const unsigned long i) const
{
	return mVector[i];
}

// Non-const version of bracked operator
double& Vector::operator[](const unsigned long i)
{
	return mVector[i];
}

double Vector::dot(const Vector& v) const
{
	double p = 0.0;
	for (unsigned long i = 0; i < mSize; ++i) {
	p += mVector[i] * v[i];
	}

	return p;
}

void Vector::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mSize; ++i) {
		s << mVector[i] << "\n";
	}
}
