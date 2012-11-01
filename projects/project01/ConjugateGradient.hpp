/*
 * ConjugateGradient.hpp
 *
 * Conjugate gradient solver that uses a the AbstractMatrix interface
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef CONJUGATEGRADIENT_HPP_
#define CONJUGATEGRADIENT_HPP_

#include "Vector.hpp"
#include "DenseMatrix.hpp"

/*
 * Conjugate gradient solver for dense matrices
 *
 * Parameters:
 * 		A - the linear system matrix
 * 		b - the right hand side vector
 * 		x - the solution vector; can initially be loaded with an initial guess
 * 		tol - the desired accuracy
 * 		maxIter - the maximum number of iterations to be performed
 */
int ConjugateGradient(const AbstractMatrix& A, const Vector& b, Vector& x,
					  const double tol, const int maxIter);

#endif /* CONJUGATEGRADIENT_HPP_ */
