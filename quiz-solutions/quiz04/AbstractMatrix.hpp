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
	virtual void SetElement(const unsigned long row, const unsigned long col,
			 	    		const ValueType value) = 0;

	// Public methods
	/*
	 * Perform w = U * v, where U is the upper triangular part of the matrix
	 */
	virtual Vector<ValueType> ApplyUpperTr(const Vector<ValueType>& v) const = 0;

	/*
	 * Solve L x = y for x, where L is the lower triangular part of the matrix,
	 * including the diagonal part
	 */
	virtual Vector<ValueType> ApplyInvLowerTr(const Vector<ValueType>& v) const = 0;

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
