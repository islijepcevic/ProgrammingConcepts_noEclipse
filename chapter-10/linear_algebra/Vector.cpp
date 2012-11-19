/*
 * Vector.cpp
 *
 * implementation file for Vector class
 *
 * created by: Ivan Slijepcevic
 *              12 Nov, 2012
 */

#include <cmath>
#include <iostream>
//#include <cassert>

#include "Vector.hpp"
#include "../exceptions/OutOfBoundsException.hpp"
#include "../exceptions/SizeException.hpp"

/*
 * Overridden copy constructor
 * Allocates memory for new vector, and copies entries of other vector into it
 */
Vector::Vector(const Vector& otherVector) :
    mSize(otherVector.mSize), 
    mData(otherVector.mData)
{
}

/*
 * Constructor for vector of a given size
 * Allocates memory, initialises entries to zero
 */
Vector::Vector(int size) :
    mSize(size),
    mData(size,0)
{
    // no assertion or exception needed
    // std::vector will throw std::bad_alloc
}

/*
 * Overridden destructor to correctly free memory
 */
Vector::~Vector() 
{
}

/*
 * Method to get the size of a vector
 */
int Vector::getSize() const {

    return mSize;
}

/*
 * Overloading square brackets
 * Note that this uses 'zero-based' indexing, and a check on the validity of
 * the index
 */
double& Vector::operator[](int i) {

    if (i < 0 || i >= mSize) {
        throw (OutOfBoundsException("indexing a vector out of its bounds"));
    }

    return mData[i];
}

/*
 * Overloading square brackets, const version,
 * return of const double reference guarantees that the method is const
 * Note that this is actually not needed to compile
 * zero-based indexing
 */
double Vector::operator[](int i) const {

    if (i < 0 || i >= mSize) {
        throw (OutOfBoundsException("indexing a vector out of its bounds"));
    }

    return mData[i];
}

/*
 * Read-only variant of []
 * REPLACED BY operator[] const
 * Note that this uses 'zero-based' indexing, and a check on the validity of
 * the index
 */
//double Vector::read(int i) const {
//
//    assert(i >= 0);
//    assert(i < mSize);
//
//    return mData[i];
//}

/*
 * Overloading round brackets
 * DEPRECATED
 * Note that this uses 'one-based' indexyng, and a check on the validity of
 * the index
 */
//double& Vector::operator() (int i) {
//
//    assert(i >= 1);
//    assert(i <= mSize);
//
//    return mData[i-1];
//}

/*
 * Overloading the assignment operator
 */
Vector& Vector::operator=(const Vector& otherVector) {

    if (mSize != otherVector.mSize) {
        throw (VectorSizeException("assigning a vector of different size"));
    }

    for (int i = 0; i < mSize; i++) {

        mData[i] = otherVector[i];
    }

    return *this;
}

/*
 * Overloading unary - operator
 */
Vector Vector::operator-() const {

    Vector v(mSize);
    for (int i = 0; i < mSize; i++) {
        v[i] = -mData[i];
    }

    return v;
}

/*
 * Overloading the binary + operator
 */
Vector Vector::operator+(const Vector& v1) const {

    if (mSize != v1.mSize) {
        throw (VectorSizeException("adding vectors of different size"));
    }

    Vector v(mSize);
    for (int i = 0; i < mSize; i++) {
        v[i] = mData[i] + v1.mData[i];
    }

    return v;
}

/*
 * Overloading the binary - operator
 */
Vector Vector::operator-(const Vector& v1) const {

    return *this + (-v1);
}

/*
 * Overloading scalar multiplication
 */
Vector Vector::operator*(double a) const {

    Vector v(mSize);
    for (int i = 0; i < mSize; i++) {
        v[i] = a * mData[i];
    }

    return v;
}

/*
 * Method to calculate norm (with default value p=2 corresponding to the
 * Euclidean norm)
 */
double Vector::calculateNorm(int p) const {

    double normVal, sum = 0.0;
    
    for (int i = 0; i < mSize; i++) {

        sum += pow( fabs( mData[i] ), p );
    }

    normVal = pow( sum, 1.0 / ((double)(p)) );

    return normVal;
}

/*
 * MATLAB style friend to get the size of a vector
 * MOVED TO ANOTHER FILE
 */
//int length(const Vector& v) {
//
//    return v.mSize;
//}
