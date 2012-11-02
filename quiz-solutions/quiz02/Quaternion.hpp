/*
 * Quaternion.hpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#ifndef QUATERNION_HPP_
#define QUATERNION_HPP_

#include <iostream>

#include "Vector3D.hpp"

class Quaternion {
public:
	// Constructors
	// Empty constructor
	Quaternion();
	// Constructor that takes the 4 components of the quaternion as separate
	// double floating point variables
	Quaternion(const double r, const double x, const double y, const double z);
	// Constructor that takes the scalar part and the vector part separately
	Quaternion(const double r, const Vector3D& v);
	// Copy constructor
	Quaternion(const Quaternion& q);

	// Destructor
	virtual ~Quaternion();

	// Accessor methods
	double GetScalarPart() const;
	Vector3D GetVectorPart() const;

	// Set methods
	void SetScalarPart(const double r);
	void SetVectorPart(const Vector3D& v);

	// Operations
	// Assignment operator
	Quaternion& operator=(const Quaternion& q);
	// Quaternion addition operator
	Quaternion operator+(const Quaternion& q) const;
	// Quaternion substraction operator
	Quaternion operator-(const Quaternion& q) const;
	// Quaternion multiplication operator (non-commutative)
	Quaternion operator*(const Quaternion& q) const;

	// Other public methods
	void Print(std::ostream& s = std::cout) const;

	// Friend functions
	friend std::ostream& operator<<(std::ostream& s, const Quaternion& q);

private:
	// Private data members
	double mScalarPart;
	Vector3D mVectorPart;
};

#endif /* QUATERNION_HPP_ */
