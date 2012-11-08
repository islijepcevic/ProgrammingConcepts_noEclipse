/*
 * CsrMatrix.cpp
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
 * 			to perform linear algebra operations (like matrix x vector) *
 *  Created on: Oct 31, 2012
 *      Author: radu
 */

#include "CsrMatrix.hpp"

// Constructors

CsrMatrix::CsrMatrix(const unsigned long size, const unsigned long nnz)
	: mSize(size),
	  mNnz(nnz),
	  mRows(0),
	  mCols(0),
	  mValues(0)
{
	mRows.reserve(mNnz);
	mCols.reserve(mNnz);
	mValues.reserve(mNnz);
}

// Destructor

CsrMatrix::~CsrMatrix() {}

// Set method

void CsrMatrix::SetElement(const unsigned long row,
							 const unsigned long col,
							 const double value)
{
	mRows.push_back(row);
	mCols.push_back(col);
	mValues.push_back(value);
}

// Operators

Vector CsrMatrix::operator *(const Vector& v) const
{
	Vector w(mSize);

	for (unsigned long i = 0; i < mSize; ++i) {
		for (unsigned long j = mFnz[i]; j < mFnz[i + 1]; ++j) {
			w[i] += mValues[j] * v[mCols[j]];
		}
	}

	return w;
}

// Other public methods

void CsrMatrix::Lock()
{
	mFnz.resize(mSize + 1);

	unsigned long i = 0;
	unsigned long r = 0;
	mFnz[0] = 0;
	mFnz[mSize] = mRows.size();

	while (i < mRows.size()) {
		if (r != mRows[i]) {
			++r;
			mFnz[r] = i;
		}
		++i;
	}

	mRows.resize(0);
}

void CsrMatrix::Print(std::ostream& s)
{
	// This method should be called after Lock() is called
	s << "sra vector (size " << mValues.size() << "):\n";
	for (unsigned long i = 0; i < mValues.size(); ++i) {
		s << mValues[i] << " ";
	}
	s << "\n";
	s << "clm vector (size " << mCols.size() << "):\n";
	for (unsigned long i = 0; i < mCols.size(); ++i) {
		s << mCols[i] << " ";
	}
	s << "\n";
	s << "fnz vector (size " << mFnz.size() << "):\n";
	for (unsigned long i = 0; i < mFnz.size(); ++i) {
		s << mFnz[i] << " ";
	}
	s << "\n";
}
