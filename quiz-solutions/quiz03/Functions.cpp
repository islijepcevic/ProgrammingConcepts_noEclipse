/*
 * Functions.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: radu
 */

#include "Functions.hpp"

#include <cmath>

// This method computes f(x)
Scalar ScalarFunction(const Scalar& x)
{
	Scalar result;
	result.SetX(std::sin(2 * x.GetX()) + x.GetX());

	return result;
}

// returns w = J^(-1)(x)*v
Scalar ScalarSolveJacobian(const Scalar& x, const Scalar& v)
{
	Scalar result;

	result.SetX( v.GetX() / (2 * std::cos(2 * x.GetX()) + 1) );
	return result;
}


// This method computes f(x)
Vector2D VectorFunction(const Vector2D& v)
{
	double x1 = v.GetX();
	double x2 = v.GetY();
	return Vector2D(std::exp(x1 * x1 + x2 * x2) - 1,
					std::exp(x1 * x1 - x2 * x2) - 1);
}

// returns w = J^(-1)(x)*v
Vector2D VectorSolveJacobian(const Vector2D& x, const Vector2D& v)
{
	// Compute Jacobian J and its determinant detJ
	double x1 = x.GetX();
	double x2 = x.GetY();
	double J[2][2];
	J[0][0] =  2 * x1 * std::exp(x1 * x1 + x2 * x2);
	J[0][1] =  2 * x2 * std::exp(x1 * x1 + x2 * x2);
	J[1][0] =  2 * x1 * std::exp(x1 * x1 - x2 * x2);
	J[1][1] = -2 * x1 * std::exp(x1 * x1 - x2 * x2);

	double detJ = J[0][0] * J[1][1] - J[0][1] * J[1][0];

	// Compute inverse of J
	double invJ[2][2];
	invJ[0][0] =  J[1][1] / detJ;
	invJ[0][1] = -J[0][1] / detJ;
	invJ[1][0] = -J[1][0] / detJ;
	invJ[1][1] =  J[0][0] / detJ;

	// Compute the solution w = J^(-1) v
	double v1 = v.GetX();
	double v2 = v.GetY();
	return Vector2D(invJ[0][0] * v1 + invJ[0][1] * v2,
					invJ[1][0] * v1 + invJ[1][1] * v2);
}
