/*
 * ConjugateGradient.hpp
 *
 * Conjugate gradient solver that uses any matrix
 *
 *  Created on: Nov 2, 2012
 *      Author: islijepcevic
 */

#ifndef CONJUGATEGRADIENT_HPP_
#define CONJUGATEGRADIENT_HPP_

#include "Vector.hpp"
#include "AbstractMatrix.hpp"

/*
 * Conjugate gradient solver for dense matrices
 *
 * Parameters:
 * 		A - the linear system matrix (of type DenseMatrix)
 * 		b - the right hand side vector (of type Vector)
 * 		x - the solution vector; can initially be loaded with an initial guess
 * 		    (of type Vector)
 * 		tol - the desired accuracy (double)
 * 		maxIter - the maximum number of iterations to be performed (int)
 */
int ConjugateGradient(const AbstractMatrix& A,
                                     const Vector& b,
                                     Vector& x,
                                     const double tol,
                                     const int maxIter);

#endif /* CONJUGATEGRADIENT_HPP_ */

