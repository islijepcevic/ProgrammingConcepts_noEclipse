/*
 * GaussSeidel.hpp
 *
 * Gauss-Seidel solver that uses a the AbstractMatrix interface
 * Templated on the type of the matrix and vector elements
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef GAUSSSEIDEL_HPP_
#define GAUSSSEIDEL_HPP_

#include "Vector.hpp"
#include "AbstractMatrix.hpp"

#include <iostream>

/*
 * Gauss-Seidel solver for dense matrices
 *
 * Parameters:
 * 		A - the linear system matrix
 * 		b - the right hand side vector
 * 		x - the solution vector; can initially be loaded with an initial guess
 * 		tol - the desired accuracy
 * 		maxIter - the maximum number of iterations to be performed
 */
template<typename ValueType>
int GaussSeidel(const AbstractMatrix<ValueType>& A,
				const Vector<ValueType>& b,
				Vector<ValueType>& x,
				const ValueType tol,
				const int maxIter)
{

    int numIter = 0;

    Vector<ValueType> xk(b);

    while (true) {

        Vector<ValueType> xkk(xk.GetSize());

        xkk = A.ApplyInvLowerTr((b - A.ApplyUpperTr(xk)));

        Vector<ValueType> diff = xkk - xk;
        xk = xkk;

        numIter++;

        if (diff.norm() < tol) {
            break;
        }
    }

    x = xk;

    return numIter;
}

#endif /* GAUSSSEIDEL_HPP_ */
