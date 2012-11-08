/*
 * CsrMatrix.cpp
 *
 * implementation of sparse matrix
 *
 * Created on: Nov 2, 2012
 *      Author: islijepcevic
 */

#include "CsrMatrix.hpp"
#include <cassert>

/*
 * basic constructor
 * sets sizes
 */
CsrMatrix::CsrMatrix(const unsigned long size, const unsigned long nnz) {

    mSize = size;
    mNnz = nnz;

    mRows.reserve(mNnz);
    mCols.reserve(mNnz);
    mFnz.reserve(mSize + 1);
    mValues.reserve(mNnz);

    locked = false;
}

/*
 * destructor (default)
 * nothing to delete
 */
CsrMatrix::~CsrMatrix() {}

/*
 * set element of the matrix
 */
void CsrMatrix::SetElement(const unsigned long row, const unsigned long col,
                            const double value) {

    assert(!locked);

    mRows.push_back(row);
    mCols.push_back(col);
    mValues.push_back(value);
}

/*
 * method that gets the element of given row and column of a matrix
 */
double CsrMatrix::GetElement(const unsigned long row, const unsigned long col) {

    unsigned long rowStart = mFnz[row];
    unsigned long nextRow = mFnz[row+1];

    for (unsigned int i = rowStart; i < nextRow; i++) {
        if (mCols[i]  == col) {
            return mValues[i];
        } else if (mCols[i] > col) {
            break;
        }
    }

    return 0.0;
}

/*
 * matrix-vector multiplication
 */
Vector CsrMatrix::operator*(const Vector& v) const {

    assert(locked);

    Vector w(mSize);

    for (unsigned long row = 0; row < mSize; row++) {
        for (unsigned long valueIndex = mFnz[row]; valueIndex < mFnz[row + 1]; 
                valueIndex++) {

            w[row] += mValues[valueIndex] * v[mCols[valueIndex]];
        }
    }

    return w;
}

/*
 * locks the matrix, compresses the storage
 */
void CsrMatrix::Lock() {

    unsigned long rowIndex = 0;
    mFnz.push_back(0);

    // could be fastened with some binary search
    for (unsigned long i = 0; i < mRows.size(); i++) {
        if (mRows[i] > rowIndex) {
            rowIndex++;
            mFnz.push_back(i);
        }
    }

    mFnz.push_back( mValues.size() );

    mSize = mFnz.size() - 1;
    mNnz = mValues.size();
    
   locked = true;
}

/*
 * print
 */
void CsrMatrix::Print(std::ostream& s) {
    assert(locked);

    for (unsigned long row = 0; row < mSize; row++) {
        for (unsigned long col = 0; col < mSize; col++) {
            s << GetElement(row, col) << "\t";
        }
        s << std::endl;
    }
}
