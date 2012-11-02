/*
 * CsrMatrix.hpp
 *
 * Concrete derived class of AbstractMatrix implementing a compresses sparse
 * row (CSR) storage format
 *
 * The CSR matrix has two states:
 *
 * 1. Unlocked - the matrix will be in this state after building it. In
 * 			this state it is possible to insert elements use the Set method
 *
 * 2. Locked - after all the elements have been inserted it is necessary to
 * 			call the Lock() method which compresses the storage and allows
 * 			to perform linear algebra operations (like matrix x vector)
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef CSRMATRIX_HPP_
#define CSRMATRIX_HPP_

#include <iostream>
#include <vector>

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

class CsrMatrix : public AbstractMatrix {
public:
	// Constructors
	/*
	 * The constructor takes two parameters:
	 * 		size - the dimension of the matrix
	 * 		nnz - and estimate of the number of non zero values
	 * 			  this is used to reserve space for the internal data
	 * 			  structures, for performance reasons
	 */
	CsrMatrix(const unsigned long size, const unsigned long nnz);

	// Destructor
	~CsrMatrix();

	// Set method
	// Implementation of pure virtual method
	void SetElement(const unsigned long row, const unsigned long col,
			 	    const double value);

	// Operators
	// The Lock() method must be called before using this operator
	Vector operator*(const Vector& v) const;

	// Public methods
	// Method which compresses the internal storage and allows performing
	// linear algebra operations
	void Lock();

	void Print(std::ostream& s = std::cout);

	// Private data
	// Dimension of the matrix
	unsigned long mSize;
	// Number of non zero elements
	unsigned long mNnz;
	// Row indices
	std::vector<unsigned long> mRows;
	// Column indices - clm for CSR
	std::vector<unsigned long> mCols;
	// fnz for CSR
	std::vector<unsigned long> mFnz;
	// Values - sra for CSR
	std::vector<double> mValues;
};

#endif /* CSRMATRIX_HPP_ */
