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
	// Copy constructor
	BandedMatrix(const BandedMatrix<ValueType>& M);

	// Destructor
	~BandedMatrix();

	// Set method
	// Implementation of pure virtual method in base class
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

	// Compute the LU factorization, such that A = LU
	void LUFactorization(AbstractMatrix<ValueType>*& L,
						 AbstractMatrix<ValueType>*& U);

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

	/*
	 *  In the case that the object is a an upper triangular factor, apply
	 *  its inverse to a vector, such that w = U^-1 v
	 *
	 *  This represents a back substitution solve
	 */
	Vector<ValueType> ApplyUpperInv(const Vector<ValueType>& v);

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

template<typename ValueType>
BandedMatrix<ValueType>::BandedMatrix(const BandedMatrix<ValueType>& M)
	: mSize(static_cast<int>(M.mSize)),
	  mP(M.mP),
	  mR(M.mR)
{
	mMatrix = new ValueType*[mSize];
	for (int i = 0; i < mSize; ++i) {
		mMatrix[i] = new ValueType[mP + mR + 1];
		mMatrix[i] += mP;
		for (int j = -mP; j < mR + 1; ++j) {
			mMatrix[i][j] = M.mMatrix[i][j];
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
void BandedMatrix<ValueType>::SetElement(const int row, const int col, 
                                        const ValueType value)
{
	mMatrix[row][col - row] = value;
}

// factorization methods

template<typename ValueType>
void BandedMatrix<ValueType>::LUFactorization(AbstractMatrix<ValueType>*& L,
                                            AbstractMatrix<ValueType>*& U) const 
{          

    BandedMatrix<ValueType>* BandedL = new BandedMatrix<ValueType>(mSize, mP, 0);
    BandedMatrix<ValueType>* BandedU = new BandedMatrix<ValueType>(*this);

    ValueType** l(BandedL->mMatrix);
    ValueType** u(BandedU->mMatrix);

    // make L an identity matrix
    for (int i = 0; i < mSize; i++) {
        BandedL->SetElement(i, i, 1.0);
    }

    // perform factorization
    for (int k = 0; k < mSize; k++) {

        // check if pivoting needed
        assert(u[k][0] != 0.0);

        for (int i = k+1; i < mSize; i++) {

            int lCol = std::max(k-i, -mP);
            l[i][lCol] = u[i][lCol] / u[k][0];

            for (int j = k+1; j < mSize; j++) {

                int uCol = std::min(j - i, mR - 1);
                int uCol2 = std::min(j - k, mR - 1);
                u[i][uCol] = u[i][uCol] - (l[i][lCol] * u[k][uCol2]);
            }
        }
    }

    // "return"
    L = BandedL;
    U = BandedU;
}

template<typename ValueType>
void BandedMatrix<ValueType>::CholeskyFactorization(
		AbstractMatrix<ValueType>*& R) const
{
	// Need to first create a pointer to the DenseMatrix. Otherwise I can not work
	// with the entries.


	BandedMatrix<ValueType>* BandedR =
			new BandedMatrix<ValueType>(mSize, mP, 0);

	ValueType** r(BandedR->mMatrix);
	ValueType s;

	for (int i = 0; i < mSize; ++i) {
		int ip = std::max(i - mP, 0);
		for (int j = ip; j < i; ++j) {
			s = 0;
			for (int k = ip; k < j; ++k) {
				s += r[i][k - i] * r[j][k - j];
			}
			r[i][j - i] = (mMatrix[i][j - i] - s) / r[j][0];
		}

		s = 0;
		for (int k = ip; k < i; ++k) {
			s += r[i][k - i] * r[i][k - i];
		}
		r[i][0] = std::sqrt(mMatrix[i][0] - s);

	}

	R = BandedR;
}

template<typename ValueType>
void BandedMatrix<ValueType>::LUFactorization(
		AbstractMatrix<ValueType>*& L, AbstractMatrix<ValueType>*& U)
{
	BandedMatrix<ValueType>* BandedL =
			new BandedMatrix<ValueType>(mSize, mP, 0);
	BandedMatrix<ValueType>* BandedU =
			new BandedMatrix<ValueType>(*this);

	ValueType** l(BandedL->mMatrix);
	ValueType** u(BandedU->mMatrix);

	for (int k = 0; k < mSize; ++k) {
		l[k][0] = 1.0;
		int ip = std::max(k - mP, 0);
		for (int i = ip; i <= k; ++i) {
			double s = 0.0;
			for (int j = ip; j < i; ++j) {
				s += u[j][k - j] * l[i][j - i];
			}
			u[i][k - i] = mMatrix[i][k - i] - s;
		}
		int ir = std::min(k + mR, mSize -1);
		for (int i = k; i < ir + 1; ++i) {
			double s = 0.0;
			for (int j = ip; j < k; ++j) {
				s += u[j][k - j] * l[i][j - i];
			}
			l[i][k - i] = (mMatrix[i][k - i] - s) / u[k][0];
		}
	}

	L = BandedL;
	U = BandedU;
}

template<typename ValueType>
Vector<ValueType>
BandedMatrix<ValueType>::ApplyLowerInv(const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = 0; i < mSize; ++i) {
		w[i] = v[i];
		int ip = std::max(i - mP, 0);
		for (int j = ip; j < i; ++j) {
			w[i] -= mMatrix[i][j - i] * w[j];
		}
		w[i] /= mMatrix[i][0];
	}

	return w;
}

template<typename ValueType>
Vector<ValueType>
BandedMatrix<ValueType>::ApplyLowerTranspInv(const Vector<ValueType>& v) const
{
	Vector<ValueType> w(mSize);

	for (int i = mSize - 1; i >= 0; --i) {
		w[i] = v[i];
		/*
		 *  We are transposing the lower triangular matrix. mR is 0, so we
		 *  are using mP for the maximum value of j
		 */
		int ir = std::min(i + mP, mSize - 1);
		for (int j = i + 1; j < ir + 1; ++j) {
			w[i] -= mMatrix[j][i - j] * w[j];
		}
		w[i] /= mMatrix[i][0];
	}

	return w;
}

template<typename ValueType>
Vector<ValueType>
BandedMatrix<ValueType>::ApplyUpperInv(const Vector<ValueType>& v)
{
	Vector<ValueType> w(mSize);

	for (int i = mSize - 1; i >= 0; --i) {
		w[i] = v[i];
		int ir = std::min(i + mR, mSize - 1);
		for (int j = i + 1; j < ir + 1; ++j) {
			w[i] -= mMatrix[i][j - i] * w[j];
		}
		w[i] /= mMatrix[i][0];
	}

	return w;
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
