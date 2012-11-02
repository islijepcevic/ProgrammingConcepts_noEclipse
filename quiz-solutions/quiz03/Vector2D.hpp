/*
 * Vector2D.hpp
 *
 *  Created on: Oct 18, 2012
 *      Author: rpopescu
 */

#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include<iostream>

class Vector2D
{
public:
	// Constructors
	// Empty constructor. Initializes to 0
	Vector2D();
	// Constructor that takes the x and z components as doubles
	Vector2D(const double x, const double y);
	// Copy constructor
	Vector2D(const Vector2D& v);

	// Destructor
	~Vector2D();

	// Accessor methods
	double GetX() const;
	double GetY() const;

	// Set methods
	void SetX(const double x);
	void SetY(const double y);

	// Operations
	// Assignment operator
	Vector2D& operator=(const Vector2D& v);
	// Unary minus operator
	Vector2D operator-() const;
	// Binary addition operator
	Vector2D operator+(const Vector2D& v) const;
	// Binary substraction operator
	Vector2D operator-(const Vector2D& v) const;
	// Binary vector * double operator
	Vector2D operator*(const double d) const;
	// Dot product of two vectors
	double dot(const Vector2D& v) const;
	// The Euclidean norm
	double norm() const;

	// Friend functions
	friend std::ostream& operator<<(std::ostream& s, const Vector2D& v);

private:
	// Data members
	double mX;
	double mY;
};

#endif /* VECTOR2D_HPP_ */
