/*
 * Functions.hpp
 *
 * This object represents one of the functions for the Newton solver
 * f:R^2 -> R^2;
 *        | e^{x1^2 + x2^2) - 1 |
 * f(x) = |                     |
 *        | e^(x1^2 - x2^2) - 1 |
 *
 * The zero of the function is at (0, 0)
 *
 * The object's interface must contain an Evaluate method and a SolveJacobian
 * method
 *
 *  Created on: Oct 27, 2012
 *      Author: radu
 */

#ifndef VECTORFUNCTIONOBJECT_HPP_
#define VECTORFUNCTIONOBJECT_HPP_

#include "Vector2D.hpp"
#include "Scalar.hpp"

// This method computes f(x)
Scalar ScalarFunction(const Scalar& x);

// returns w = J^(-1)(x)*v
Scalar ScalarSolveJacobian(const Scalar& x, const Scalar& v);


// This method computes f(x)
Vector2D VectorFunction(const Vector2D& x);

// returns w = J^(-1)(x)*v
Vector2D VectorSolveJacobian(const Vector2D& x, const Vector2D& v) ;

#endif /* VECTORFUNCTIONOBJECT_HPP_ */
