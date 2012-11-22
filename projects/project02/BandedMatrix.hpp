/*
 * BandedMatrix.hpp
 *
 * Concrete derived class of AbstractMatrix implementing a banded storage format
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef BANDEDMATRIX_HPP_
#define BANDEDMATRIX_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

template<typename ValueType>
class BandedMatrix : public AbstractMatrix<ValueType> {
public:
	/*
	 *  Constructor with parameters:
	 *  	size - dimension of the matrix
	 *  	p - left bandwidth
	 *  	r - right bandwidth
	 */
	BandedMatrix(const int size,
				 const int p,
				 const int r);

	// Destructor
	~BandedMatrix();

	// Set method
	// Implementation of pure virtual method in base class
	void SetElement(const int row, const int col,
			 	    const ValueType value);

	// Operators
	Vector<ValueType> operator*(const Vector<ValueType>& v) const;

	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	ValueType** mMatrix;
	int mSize;
	int mP;
	int mR;
};

// Constructors

template<typename ValueType>
BandedMatrix<ValueType>::BandedMatrix(const int size,
										   const int p,
										   const int r)
	: mSize(static_cast<int>(size)),
	  mP(p),
	  mR(r)
{
	mMatrix = new ValueType*[mSize];
	for (int i = 0; i < mSize; ++i) {
		mMatrix[i] = new ValueType[mP + mR + 1];
		mMatrix[i] += mP;
		for (int j = -mP; j < mR + 1; ++j) {
			mMatrix[i][j] = 0.0;
		}
	}
}

// Destructor

template<typename ValueType>
BandedMatrix<ValueType>::~BandedMatrix()
{
	for (int i = 0; i < mSize; ++i) {
		mMatrix[i] -= mP;
		delete[] mMatrix[i];
	}
	delete[] mMatrix;
}

// Set method

template<typename ValueType>
void BandedMatrix<ValueType>::SetElement(const int row,
							 	 	 	 	const int col,
							 	 	 	 	const ValueType value)
{
	mMatrix[row][col - row] = value;
}


// Operators

template<typename ValueType>
Vector<ValueType>
BandedMatrix<ValueType>::operator*(const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = 0; i < mSize; ++i) {
		int ip = std::max(i - mP, 0);
		int ir = std::min(i + mR, mSize - 1);
		for (int j = ip; j < ir + 1; ++j) {
			w[i] += mMatrix[i][j - i] * v[j];
		}
	}

	return w;
}

// Other public methods

template<typename ValueType>
void BandedMatrix<ValueType>::Print(std::ostream& s)
{
	for (int i = 0; i < mSize; ++i) {
		for (int j = -mP; j < mR + 1; ++j) {
			s << mMatrix[i][j] << " ";
		}
		s << std::endl;
	}
}

#endif /* BANDEDMATRIX_HPP_ */
