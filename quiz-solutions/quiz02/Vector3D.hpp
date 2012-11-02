/*
 * Vector3D.hpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include<iostream>

class Vector3D
{
public:
	// Constructors
	// Empty constructor. Initializes to 0
	Vector3D();
	// Constructor that takes the x,y,z components as doubles
	Vector3D(const double x, const double y, const double z);
	// Copy constructor
	Vector3D(const Vector3D& v);

	// Destructor
	virtual ~Vector3D();

	// Accessor methods
	double GetX() const;
	double GetY() const;
	double GetZ() const;

	// Set methods
	void SetX(const double x);
	void SetY(const double y);
	void SetZ(const double z);

	// Operations
	// Assignment operator
	Vector3D& operator=(const Vector3D& v);
	// Unary minus operator
	Vector3D operator-() const;
	// Binary addition operator
	Vector3D operator+(const Vector3D& v) const;
	// Binary substraction operator
	Vector3D operator-(const Vector3D& v) const;
	// Binary vector * double operator
	Vector3D operator*(const double d) const;
	// Dot product of two vectors
	double dot(const Vector3D& v) const;
	// Cross product of two vectors
	Vector3D cross(const Vector3D& v) const;

	// Other public methods
	void Print(std::ostream& s = std::cout);

	// Friend functions
	friend std::ostream& operator<<(std::ostream& output, const Vector3D& v);

private:
	// Data members
	double mX;
	double mY;
	double mZ;
};

#endif /* VECTOR3D_HPP_ */
