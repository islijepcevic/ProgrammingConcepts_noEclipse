/*
 * Vector.hpp
 *
 * header file for Vector class
 *
 * created by: Ivan Slijepcevic
 *              12 Nov, 2012
 */

#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <vector>

class Vector {
private:
    int mSize;      // size of vector
    std::vector<double> mData;  // data stored in vector

public:
    Vector(const Vector& otherVector);
    Vector(int size);
    virtual ~Vector();

    int getSize() const;
    double& operator[](int i);  // zero-based indexing
    double operator[](int i) const; // constant [] operator, zero-based
    
    // read-only zero-based indexing; replaced by operator[] const
    //double read(int i) const;   
    
    // REDUNDANT AND CONFUSING
    //double& operator() (int i); // one-based indexing

    Vector& operator=(const Vector& otherVector);   // assignment operator
    Vector operator-() const;   // unary -
    Vector operator+(const Vector& v1) const;   // binary +
    Vector operator-(const Vector& v1) const;   // binary -
    Vector operator*(double a) const;   // scalar multiplication

    double calculateNorm(int p = 2) const;  // p-norm method

    // moved to another file because this is not the functionality of this class
    //friend int length(const Vector& v); // declare length function as a friend
};

#endif // VECTORHEADERDEF
