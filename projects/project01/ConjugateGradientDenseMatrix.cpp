/*
 * ConjugateGradientDenseMatrix.cpp
 *
 * Conjugate gradient solver that uses a dense matrix
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#include "ConjugateGradientDenseMatrix.hpp"

#include <iostream>

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
								 const int maxIter)
{
	Vector r = b - A * x;
	Vector p = r;
	double res_old = r.dot(r);
	double res_new;

	int iter = 0;
	do {
		Vector Ap = A * p;
		double alpha = res_old / (p.dot(Ap));
		x = x + (p * alpha);
		r = r - (Ap * alpha);
		res_new = r.dot(r);
		p = r + p * (res_new / res_old);
		res_old = res_new;
		iter++;

		std::cout << "Iteration: " << iter << " , " << "res = " << res_new
				  << "\n";
	} while ((res_new > tol) && iter < maxIter);

	if (iter >= maxIter) {
		std::cout << "Maximum number of iterations reached without convergence."
				  << "\nAborting." << std::endl;
		return -iter;
	}

	return iter;
}
