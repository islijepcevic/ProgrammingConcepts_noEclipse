/*
 * Vector2D.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#include "Vector2D.hpp"

#include <cmath>

// Constructors

Vector2D::Vector2D()
	: mX(0.0),
	  mY(0.0)
{}

Vector2D::Vector2D(const double x, const double y)
	: mX(x),
	  mY(y)
{}

Vector2D::Vector2D(const Vector2D& v)
	: mX(v.GetX()),
	  mY(v.GetY())
{}

// Destructor

Vector2D::~Vector2D()
{}

// Accessor methods

double Vector2D::GetX() const
{
	return mX;
}

double Vector2D::GetY() const
{
	return mY;
}

// Set methods

void Vector2D::SetX(const double x)
{
	mX = x;
}

void Vector2D::SetY(const double y)
{
	mY = y;
}

// Operations

Vector2D& Vector2D::operator=(const Vector2D& v)
{
	mX = v.GetX();
	mY = v.GetY();

	return *this;
}

Vector2D Vector2D::operator-() const
{
	Vector2D v(- mX, - mY);

	return v;
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	Vector2D w(mX + v.GetX(), mY + v.GetY());

	return w;
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
	Vector2D w(mX - v.GetX(), mY - v.GetY());

	return w;
}

Vector2D Vector2D::operator*(const double d) const {
	Vector2D v(d * mX, d * mY);

	return v;
}

double Vector2D::dot(const Vector2D& v) const {
	return mX * v.GetX() + mY * v.GetY();
}

double Vector2D::norm() const {
	return std::sqrt(mX * mX + mY * mY);
}

// Friend functions

std::ostream& operator<<(std::ostream& s, const Vector2D& v)
{
	s << "( " << v.mX << " , " << v.mY <<  " )";

	return s;
}
