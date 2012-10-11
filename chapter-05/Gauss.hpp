/*
 * Gauss.hpp
 *
 *  Created on: Oct 11, 2012
 *      Author: rpopescu
 */

#ifndef GAUSS_H
#define GAUSS_H

/*
 * Function that performs Gaussian elimination with partial pivoting on
 * the matrix A and the rhs vector b
 *
 * Parameters:
 *     A - the linear system matrix
 *     b - the right-hand side vector
 *     n - the size of the linear system
 */
void GaussPartialPivoting(double**& A, double*& b, const int n);

/*
 * Function that finds the largest pivot at step k and performs the pivoting
 * on matrix A and vector b
 */
void Pivot(double**& A, double*& b, const int k, const int n);

/*
 * Function that performs backware substition on the
 */
void BackwardSolve(double**& A, double*& b, const int n, double*& x);

#endif // GAUSS_H
