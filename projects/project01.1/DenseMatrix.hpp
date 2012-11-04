/*
 * DenseMatrix.hpp
 *
 * Concrete derived class of AbstractMatrix implementing a dense storage format
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#ifndef DENSEMATRIX_HPP_
#define DENSEMATRIX_HPP_

#include <iostream>
#include <vector>

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

template<typename ValueType>
class DenseMatrix : public AbstractMatrix<ValueType> {
public:
	// Constructors
	// The sole parameter of the constructor is the dimension of the matrix
	DenseMatrix(const unsigned long size);

	// Destructor
	~DenseMatrix();

	// Set method
	// Implementation of pure virtual method
	void SetElement(const unsigned long row, const unsigned long col,
			 	    const ValueType value);

	// Operators
	Vector<ValueType> operator*(const Vector<ValueType>& v) const;

	// Public methods
	void Print(std::ostream& s = std::cout);

	// Private data
private:
	/*
	 * The elements could also be stored in a ValueType** matrix, but since
	 * we don't perform any pointer arithmetics, using std::vector can be
	 * more convenient
	 */
	std::vector<std::vector<ValueType> > mMatrix;
	unsigned long mSize;
};

// Constructors

template<typename ValueType>
DenseMatrix<ValueType>::DenseMatrix(const unsigned long size)
	: mSize(size)
{
	mMatrix.resize(mSize);
	//mMatrix = new ValueType*[mSize];
	for (unsigned long i = 0; i < mSize; ++i) {
		mMatrix[i].resize(mSize, 0.0);
	}
}

// Destructor

template<typename ValueType>
DenseMatrix<ValueType>::~DenseMatrix()
{}

// Set method

template<typename ValueType>
void DenseMatrix<ValueType>::SetElement(const unsigned long row,
							 const unsigned long col,
							 const ValueType value)
{
	mMatrix[row][col] = value;
}

// Operators

template<typename ValueType>
Vector<ValueType>
DenseMatrix<ValueType>::operator *(const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (unsigned long i = 0; i < mSize; ++i) {
		for (unsigned long j = 0; j < mSize; ++j) {
			w[i] += mMatrix[i][j] * v[j];
		}
	}

	return w;
}

// Other public methods

template<typename ValueType>
void DenseMatrix<ValueType>::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mSize; ++i) {
		for (unsigned long j = 0; j < mSize; ++j) {
			s << mMatrix[i][j] << " ";
		}
		s << std::endl;
	}
}

#endif /* DENSEMATRIX_HPP_ */
