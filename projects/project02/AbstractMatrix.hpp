/*
 * AbstractMatrix.hpp
 *
 * Abstract base class for the matrix of the system to be solved using CG
 * Templated on the type of values
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef ABSTRACTMATRIX_HPP_
#define ABSTRACTMATRIX_HPP_

#include <iostream>

#include "Vector.hpp"

template<typename ValueType>
class AbstractMatrix {
public:
	// Constructors
	AbstractMatrix() {}

	// Destructor
	virtual ~AbstractMatrix() {}

	/*
	 *  Set method used for insering elements into an empty matrix
	 *
	 *  Parameters:
	 *  	row, col - position in the matrix of the new element
	 *  	value    - values of the element to be inserted
	 */
	virtual void SetElement(const int row, const int col,
			 	    		   const ValueType value) = 0;

	// Methods for direct solvers
	/* Compute the Cholesky factorization, such that A = RR^T
	 * Parameters:
	 *    R : a pointer to AbstractMatrix passed as reference.
	 *        The method assumes that R is null at input
	 *        and allocates a new AbstractMatrix of whichever type needed
	 */
	virtual void CholeskyFactorization(AbstractMatrix<ValueType>*& R) const = 0;

	// Compute the LU factorization, such that A = LU
	virtual void LUFactorization(AbstractMatrix<ValueType>*& L,
								 AbstractMatrix<ValueType>*& U) = 0;

	/*
	 *  In the case that the object is a a lower triangular factor, apply
	 *  its inverse to a vector, such that w = L^-1 v
	 *
	 *  This represents a forward substitution solve
	 */
	virtual Vector<ValueType> ApplyLowerInv(const Vector<ValueType>& v) const = 0;

	/*
	 *  In the case that the object is a a lower triangular factor, apply
	 *  the inverse of its transpose to a vector, such that w = (L^T)^-1 v
	 *
	 *  This represents a back substitution solve using the transpose
	 */
	virtual Vector<ValueType> ApplyLowerTranspInv(const Vector<ValueType>& v) const = 0;

	/*
	 *  In the case that the object is a an upper triangular factor, apply
	 *  its inverse to a vector, such that w = U^-1 v
	 *
	 *  This represents a back substitution solve
	 */
	virtual Vector<ValueType> ApplyUpperInv(const Vector<ValueType>& v) = 0;

	// Operators
	/*
	 * Allows performing w = M * v, with v,w of type Vector
	 * and M of type AbstractMatrix
	 */
	virtual Vector<ValueType> operator*(const Vector<ValueType>& v) const = 0;

	// Public methods
	virtual void Print(std::ostream& s = std::cout) = 0;
};

#endif /* ABSTRACTMATRIX_HPP_ */
