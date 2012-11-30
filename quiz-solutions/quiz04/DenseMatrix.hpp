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

	// Public methods
	/*
	 * Perform w = U * v, where U is the upper triangular part of the matrix
	 */
	Vector<ValueType> ApplyUpperTr(const Vector<ValueType>& v) const;

	/*
	 * Solve L x = y for x, where L is the lower triangular part of the matrix,
	 * including the diagonal part
	 */
	Vector<ValueType> ApplyInvLowerTr(const Vector<ValueType>& v) const;

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

// apply methods 

/*
 * Perform w = U * v, where U is the upper triangular part of the matrix
 */
template<typename ValueType>
Vector<ValueType> DenseMatrix<ValueType>::ApplyUpperTr(const Vector<ValueType>& v) const {

    Vector<ValueType> result(v.GetSize());

    for (unsigned int row = 0; row < mSize; row++) {
        ValueType elem = 0;
        for (unsigned int col = row + 1; col < mSize; col++) {
            elem = elem + mMatrix[row][col] * v[col];
        }
        result[row] = elem;
    }

    return result;
}

/*
 * Solve L x = y for x, where L is the lower triangular part of the matrix,
 * including the diagonal part
 *
 * applying forward substitution
 */
template<typename ValueType>
Vector<ValueType> DenseMatrix<ValueType>::ApplyInvLowerTr(const Vector<ValueType>& v) const {
    
    Vector<ValueType> result(v.GetSize());

    for (unsigned int row = 0; row < mSize; row++) {
        ValueType sum = 0;
        for (unsigned int col = 0; col < row; col++) {
            sum = sum + result[col] * mMatrix[row][col];
        }

        ValueType elem = (v[row] - sum) / mMatrix[row][row];
        result[row] = elem;
    }

    return result;
}

// Operators

template<typename ValueType>
Vector<ValueType>
DenseMatrix<ValueType>::operator*(const Vector<ValueType>& v) const
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

//template<typename ValueType>
//Vector<ValueType> DenseMatrix<ValueType>::ApplyUpperTr(
//		const Vector<ValueType>& v) const
//{
//	Vector<ValueType> w(mSize);
//
//	for (unsigned long i = 0; i < mSize; ++i) {
//		for (unsigned long j = i + 1; j < mSize; ++j) {
//			w[i] += mMatrix[i][j] * v[j];
//		}
//	}
//
//	return w;
//}

//template<typename ValueType>
//Vector<ValueType> DenseMatrix<ValueType>::ApplyInvLowerTr(
//		const Vector<ValueType>& v) const
//{
//	Vector<ValueType> w(mSize);
//
//	for (unsigned long i = 0; i < mSize; ++i) {
//		w[i] = v[i];
//		for (unsigned long j = 0; j < i; ++j) {
//			w[i] -= mMatrix[i][j] * w[j];
//		}
//		w[i] /= mMatrix[i][i];
//	}
//
//	return w;
//}

#endif /* DENSEMATRIX_HPP_ */
