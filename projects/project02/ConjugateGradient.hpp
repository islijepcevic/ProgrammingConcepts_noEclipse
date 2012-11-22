/*
 * ConjugateGradient.hpp
 *
 * Conjugate gradient solver that uses a the AbstractMatrix interface
 * Templated on the type of the matrix and vector elements
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef CONJUGATEGRADIENT_HPP_
#define CONJUGATEGRADIENT_HPP_

#include "Vector.hpp"
#include "AbstractMatrix.hpp"

#include <iostream>

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
template<typename ValueType>
int ConjugateGradient(const AbstractMatrix<ValueType>& A,
					  const Vector<ValueType>& b,
					  Vector<ValueType>& x,
					  const ValueType tol,
					  const int maxIter)
{
	Vector<ValueType> r = b - A * x;
	Vector<ValueType> p = r;
	ValueType res_old = r.dot(r);
	ValueType res_new;

	int iter = 0;
	do {
		Vector<ValueType> Ap = A * p;
		ValueType alpha = res_old / (p.dot(Ap));
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

#endif /* CONJUGATEGRADIENT_HPP_ */
