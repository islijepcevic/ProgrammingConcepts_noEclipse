/*
 * Vector3D.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#include "Vector3D.hpp"

// Constructors

Vector3D::Vector3D()
	: mX(0.0),
	  mY(0.0),
	  mZ(0.0)
{}

Vector3D::Vector3D(const double x, const double y, const double z)
	: mX(x),
	  mY(y),
	  mZ(z)
{}

Vector3D::Vector3D(const Vector3D& v)
	: mX(v.GetX()),
	  mY(v.GetY()),
	  mZ(v.GetZ())
{}

// Destructor

Vector3D::~Vector3D()
{}

// Accessor methods

double Vector3D::GetX() const
{
	return mX;
}

double Vector3D::GetY() const
{
	return mY;
}

double Vector3D::GetZ() const
{
	return mZ;
}

// Set methods

void Vector3D::SetX(const double x)
{
	mX = x;
}

void Vector3D::SetY(const double y)
{
	mY = y;
}

void Vector3D::SetZ(const double z)
{
	mZ = z;
}

// Operations

Vector3D& Vector3D::operator=(const Vector3D& v)
{
	mX = v.GetX();
	mY = v.GetY();
	mZ = v.GetZ();

	return *this;
}

Vector3D Vector3D::operator-() const
{
	Vector3D v(- mX, - mY, - mZ);

	return v;
}

Vector3D Vector3D::operator+(const Vector3D& v) const
{
	Vector3D w(mX + v.GetX(), mY + v.GetY(), mZ + v.GetZ());

	return w;
}

Vector3D Vector3D::operator-(const Vector3D& v) const
{
	Vector3D w(mX - v.GetX(), mY - v.GetY(), mZ - v.GetZ());

	return w;
}

Vector3D Vector3D::operator*(const double d) const {
	Vector3D v(d * mX, d * mY, d * mZ);

	return v;
}

double Vector3D::dot(const Vector3D& v) const {
	return mX * v.GetX() + mY * v.GetY() + mZ * v.GetZ();
}

Vector3D Vector3D::cross(const Vector3D& v) const {
	Vector3D w(mY * v.GetZ() - v.GetY() * mZ,
			   v.GetX() * mZ - mX * v.GetZ(),
			   mX * v.GetY() - v.GetX() * mY);

	return w;
}

// Other public methods

void Vector3D::Print(std::ostream& s)
{
	s << "( " << mX << " , " << mY << " , " << mZ << " )";
}

// Friend functions

std::ostream& operator<<(std::ostream& output, const Vector3D& v)
{
	output << "( " << v.GetX() << " , " << v.GetY() << " , " << v.GetZ()
		   << " )";

	return output;
}
