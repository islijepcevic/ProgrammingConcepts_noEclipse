/*
 * Scalar.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#include "Scalar.hpp"

#include <cmath>

// Constructors

Scalar::Scalar()
	: mX(0.0)
{}

Scalar::Scalar(const double x)
	: mX(x)
{}

Scalar::Scalar(const Scalar& v)
	: mX(v.GetX())
{}

// Destructor

Scalar::~Scalar()
{}

// Accessor methods

double Scalar::GetX() const
{
	return mX;
}

// Set methods

void Scalar::SetX(const double x)
{
	mX = x;
}

// Operations

Scalar& Scalar::operator=(const Scalar& v)
{
	mX = v.GetX();

	return *this;
}

Scalar Scalar::operator-() const
{
	Scalar v(- mX);

	return v;
}

Scalar Scalar::operator+(const Scalar& v) const
{
	Scalar w(mX + v.GetX());

	return w;
}

Scalar Scalar::operator-(const Scalar& v) const
{
	Scalar w(mX - v.GetX());

	return w;
}

Scalar Scalar::operator*(const double d) const
{
	Scalar v(d * mX);

	return v;
}

double Scalar::norm() const
{
	return std::sqrt(mX * mX );
}

// Friend functions

std::ostream& operator<<(std::ostream& s, const Scalar& v)
{
	s << "( " << v.mX << " )";

	return s;
}
