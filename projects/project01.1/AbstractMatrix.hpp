/*
 * AbstractMatrix.hpp
 *
 * Abstract base class for the matrix of the system to be solved using CG
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef ABSTRACTMATRIX_HPP_
#define ABSTRACTMATRIX_HPP_

#include <iostream>

#include "Vector.hpp"

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
			 	    		const double value) = 0;

	// Operators
	/*
	 * Allows performing w = M * v, with v,w of type Vector
	 * and M of type AbstractMatrix
	 */
	virtual Vector operator*(const Vector& v) const = 0;

	// Public methods
	virtual void Print(std::ostream& s = std::cout) = 0;
};

#endif /* ABSTRACTMATRIX_HPP_ */
