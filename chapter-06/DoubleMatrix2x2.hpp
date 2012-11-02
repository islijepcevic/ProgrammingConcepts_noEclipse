/*
 * DoubleMatrix2x2.hpp
 *
 *  Created on: Oct 21, 2012
 *      Author: radu
 */

#ifndef DOUBLEMATRIX2X2_HPP_
#define DOUBLEMATRIX2X2_HPP_

#include <iostream>

class DoubleMatrix2x2 {
public:
	// Empty constructor
	DoubleMatrix2x2();

	// Alternate constructor
	DoubleMatrix2x2(const double m11, const double m12,
					const double m21, const double m22);

	// Copy constructor
	DoubleMatrix2x2(const DoubleMatrix2x2& m);

	// Destructor
	virtual ~DoubleMatrix2x2();

	// Get methods
	double Get(const int i, const int j) const;

	// Operators
	DoubleMatrix2x2& operator=(const DoubleMatrix2x2& m);
	DoubleMatrix2x2 operator-() const;
	DoubleMatrix2x2 operator+(const DoubleMatrix2x2& m) const;
	DoubleMatrix2x2 operator-(const DoubleMatrix2x2& m) const;

	// Other public methods
	void Multiply(const double d);
	double Determinant() const;
	DoubleMatrix2x2 Inverse() const;

	// Friends
    friend std::ostream& operator<<(std::ostream& output,
    								const DoubleMatrix2x2& z);
private:
	// Private data members
	// We can store the data members as a 1D array:
	// 		M[i][j] = mMatrix[2 * i + j]
	double mMatrix[4];
};

#endif /* DOUBLEMATRIX2X2_HPP_ */
