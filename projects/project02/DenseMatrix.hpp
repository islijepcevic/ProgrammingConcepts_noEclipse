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
#include <cmath>

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

template<typename ValueType>
class DenseMatrix : public AbstractMatrix<ValueType> {
public:
	// Constructors
	// The sole parameter of the constructor is the dimension of the matrix
	DenseMatrix(const int size);
	// Copy constructor
	DenseMatrix(const DenseMatrix<ValueType>& M);

	// Destructor
	~DenseMatrix();

	// Set method
	// Implementation of pure virtual method
	void SetElement(const int row, const int col,
			 	    const ValueType value);

	// Methods for direct solvers

	/* Compute the Cholesky factorization, such that A = RR^T
	 * Parameters:
	 *    R : a pointer to AbstractMatrix passed as reference.
	 *        The method assumes that R is null at imput
	 *        and allocates a new AbstractMatrix of whichever type needed
	 */
	void CholeskyFactorization(AbstractMatrix<ValueType>*& R) const;

	/*
	 *  In the case that the object is a a lower triangular factor, apply
	 *  its inverse to a vector, such that w = L^-1 v
	 *
	 *  This represents a forward substitution solve
	 */
	Vector<ValueType> ApplyLowerInv(const Vector<ValueType>& v) const;

	/*
	 *  In the case that the object is a a lower triangular factor, apply
	 *  the inverse of its transpose to a vector, such that w = (L^T)^-1 v
	 *
	 *  This represents a back substitution solve using the transpose
	 */
	Vector<ValueType> ApplyLowerTranspInv(const Vector<ValueType>& v) const;

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
	int mSize;
};

// Constructors

template<typename ValueType>
DenseMatrix<ValueType>::DenseMatrix(const int size)
	: mSize(size)
{
	mMatrix.resize(mSize);
	//mMatrix = new ValueType*[mSize];
	for (int i = 0; i < mSize; ++i) {
		mMatrix[i].resize(mSize, 0.0);
	}
}

template<typename ValueType>
DenseMatrix<ValueType>::DenseMatrix(const DenseMatrix<ValueType>& M)
	: mMatrix(M.mMatrix),
	  mSize(M.mSize)
{}

// Destructor

template<typename ValueType>
DenseMatrix<ValueType>::~DenseMatrix()
{}

// Set method

template<typename ValueType>
void DenseMatrix<ValueType>::SetElement(const int row,
							 const int col,
							 const ValueType value)
{
	mMatrix[row][col] = value;
}

// Methods for direct solvers

template<typename ValueType>
void DenseMatrix<ValueType>::CholeskyFactorization(
		AbstractMatrix<ValueType>*& R) const
{
	// Need to first create a pointer to the DenseMatrix. Otherwise I can not work
	// with the entries.

	// This is not a good idea since then we can not access the entries of the matrix.
	// R =  new DenseMatrix<ValueType>(mSize);

	DenseMatrix<ValueType>* DenseR = new DenseMatrix<ValueType>(mSize);

	std::vector<std::vector<ValueType> >& r (DenseR->mMatrix);
	std::vector<std::vector<ValueType> > const& a (mMatrix);


	// r_ij => DenseR->mMatrix[i][j] => r[i][j]

	ValueType s;
	for (int i = 0; i < mSize; ++i) {
		for (int j = 0; j < i; ++j) {
			s = 0;
			for (int k = 0; k < j; ++k) {
				s += r[i][k] * r[j][k];
			}

			r[i][j] = (a[i][j] - s) / r[j][j];
		}
		s = 0;
		for (int k = 0; k < i; ++k) {
					s += r[i][k] * r[i][k];
		}

		r[i][i] = a[i][i] - s;

		// Check that the entries are positive
		assert(r[i][i] > 0); //matrix has to be positive definite!

		r[i][i] = std::sqrt(r[i][i]);

	}

	R = DenseR;
}

template<typename ValueType>
Vector<ValueType> DenseMatrix<ValueType>::ApplyLowerInv(
		const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = 0; i < mSize; ++i) {
		w[i] = v[i];
		for (int j = 0; j < i; ++j) {
			w[i] -= mMatrix[i][j] * w[j];
		}
		w[i] /= mMatrix[i][i];
	}

	return w;
}

template<typename ValueType>
Vector<ValueType> DenseMatrix<ValueType>::ApplyLowerTranspInv(
		const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = 0; i < mSize; ++i) {
		int row = mSize - i - 1;
		w[row] = v[row];
		for (int j = row + 1; j < mSize; ++j) {
			w[row] -= mMatrix[j][row] * w[j];
		}
		w[row] /= mMatrix[row][row];
	}

	return w;
}

// Operators

template<typename ValueType>
Vector<ValueType>
DenseMatrix<ValueType>::operator *(const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = 0; i < mSize; ++i) {
		for (int j = 0; j < mSize; ++j) {
			w[i] += mMatrix[i][j] * v[j];
		}
	}

	return w;
}

// Other public methods

template<typename ValueType>
void DenseMatrix<ValueType>::Print(std::ostream& s)
{
	for (int i = 0; i < mSize; ++i) {
		for (int j = 0; j < mSize; ++j) {
			s << mMatrix[i][j] << " ";
		}
		s << std::endl;
	}
}

#endif /* DENSEMATRIX_HPP_ */