/*
 * Vector.hpp
 *
 * header file for Vector class
 *
 * created by: Ivan Slijepcevic
 *              12 Nov, 2012
 */

// std::vector instead double*
// shortened constructors Vector(...) : ... {...}

#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class Vector {
private:
    double* mData;  // data stored in vector
    int mSize;      // size of vector

public:
    Vector(const Vector& otherVector);
    Vector(int size);
    virtual ~Vector();

    int getSize() const;
    double& operator[](int i);  // zero-based indexing
    double read(int i) const;   // read-only zero-based indexing
    double& operator() (int i); // one-based indexing

    Vector& operator=(const Vector& otherVector);   // assignment operator
    Vector operator-() const;   // unary -
    Vector operator+(const Vector& v1) const;   // binary +
    Vector operator-(const Vector& v1) const;   // binary -
    Vector operator*(double a) const;   // scalar multiplication

    double calculateNorm(int p = 2) const;  // p-norm method

    friend int length(const Vector& v); // declare length function as a friend
};

// Prototype signature of length() friend function
//int length(const Vector& v);

#endif // VECTORHEADERDEF
