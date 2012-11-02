/*
 * DenseMatrix.hpp
 *
 * Concrete derived class of AbstractMatrix implementing a dense storage format
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef DENSEMATRIX_HPP_
#define DENSEMATRIX_HPP_

#include <iostream>

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

class DenseMatrix : public AbstractMatrix {
public:
	// Constructors
	// The sole parameter of the constructor is the dimension of the matrix
	DenseMatrix(const unsigned long size);

	// Destructor
	~DenseMatrix();

	// Set method
	// Implementation of pure virtual method
	void SetElement(const unsigned long row, const unsigned long col,
			 	    const double value);

	// Operators
	Vector operator*(const Vector& v) const;

	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	double** mMatrix;
	unsigned long mSize;
};

#endif /* DENSEMATRIX_HPP_ */
