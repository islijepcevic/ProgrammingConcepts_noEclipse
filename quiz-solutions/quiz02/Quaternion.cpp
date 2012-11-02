/*
 * Quaternion.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#include "Quaternion.hpp"

// Constructors

Quaternion::Quaternion()
	: mScalarPart(0.0),
	  mVectorPart()
{}

Quaternion::Quaternion(const double r, const double x, const double y,
					   const double z)
	: mScalarPart(r),
	  mVectorPart(Vector3D(x, y, z))
{}

Quaternion::Quaternion(const double r, const Vector3D& v)
	: mScalarPart(r),
	  mVectorPart(v)
{}

Quaternion::Quaternion(const Quaternion& q)
	: mScalarPart(q.GetScalarPart()),
	  mVectorPart(q.GetVectorPart())
{}

// Destructor

Quaternion::~Quaternion()
{}

// Accessor methods

double Quaternion::GetScalarPart() const
{
	return mScalarPart;
}

Vector3D Quaternion::GetVectorPart() const
{
	return mVectorPart;
}

// Set methods

void Quaternion::SetScalarPart(const double r)
{
	mScalarPart = r;
}

void Quaternion::SetVectorPart(const Vector3D& v)
{
	mVectorPart = v;
}

// Operations

Quaternion& Quaternion::operator=(const Quaternion& q)
{
	mScalarPart = q.GetScalarPart();
	mVectorPart = q.GetVectorPart();

	return *this;
}

Quaternion Quaternion::operator+(const Quaternion& q) const
{
	Quaternion t(mScalarPart + q.GetScalarPart(),
				 mVectorPart + q.GetVectorPart());

	return t;
}

Quaternion Quaternion::operator-(const Quaternion& q) const
{
	Quaternion t(mScalarPart - q.GetScalarPart(),
				 mVectorPart - q.GetVectorPart());

	return t;
}

Quaternion Quaternion::operator*(const Quaternion& q) const
{
	Quaternion t;
	const double& r1 = mScalarPart;
	const double& r2 = q.GetScalarPart();
	const Vector3D& v1 = mVectorPart;
	const Vector3D& v2 = q.GetVectorPart();

	t.SetScalarPart(r1 * r2 - v1.dot(v2));
	t.SetVectorPart((v2 * r1) + (v1 * r2) + v1.cross(v2));

	return t;
}

// Other public methods

void Quaternion::Print(std::ostream& s) const
{
	s << "( " << mScalarPart << " , " << mVectorPart.GetX() << " , "
	  << mVectorPart.GetY() << " , " << mVectorPart.GetZ() << " )";
}

// Friend functions

std::ostream& operator<<(std::ostream& s, const Quaternion& q)
{
	q.Print(s);

	return s;
}
