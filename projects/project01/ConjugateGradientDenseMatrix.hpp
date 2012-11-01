/*
 * ConjugateGradientDenseMatrix.hpp
 *
 * Conjugate gradient solver that uses a dense matrix
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef CONJUGATEGRADIENTDENSEMATRIX_HPP_
#define CONJUGATEGRADIENTDENSEMATRIX_HPP_

#include "Vector.hpp"
#include "DenseMatrix.hpp"

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
int ConjugateGradientDenseMatrix(const DenseMatrix& A,
								 const Vector& b,
								 Vector& x,
								 const double tol,
								 const int maxIter);

#endif /* CONJUGATEGRADIENTDENSEMATRIX_HPP_ */
