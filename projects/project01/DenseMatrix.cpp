/*
 * DenseMatrix.hpp
 *
 * Concrete derived class of AbstractMatrix implementing a dense storage format
 *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#include "DenseMatrix.hpp"

// Constructors

DenseMatrix::DenseMatrix(const unsigned long size)
	: mSize(size)
{
	mMatrix = new double*[mSize];
	for (unsigned long i = 0; i < mSize; ++i) {
		mMatrix[i] = new double[mSize];
	}
}

// Destructor

DenseMatrix::~DenseMatrix()
{
	for (unsigned long i = 0; i < mSize; ++i) {
		delete[] mMatrix[i];
	}
	delete[] mMatrix;
}

// Set method

void DenseMatrix::SetElement(const unsigned long row,
							 const unsigned long col,
							 const double value)
{
	mMatrix[row][col] = value;
}

// Operators

Vector DenseMatrix::operator *(const Vector& v) const
{
	Vector w(mSize);

	for (unsigned long i = 0; i < mSize; ++i) {
		for (unsigned long j = 0; j < mSize; ++j) {
			w[i] += mMatrix[i][j] * v[j];
		}
	}

	return w;
}

// Other public methods

void DenseMatrix::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mSize; ++i) {
		for (unsigned long j = 0; j < mSize; ++j) {
			s << mMatrix[i][j] << " ";
		}
		s << std::endl;
	}
}
