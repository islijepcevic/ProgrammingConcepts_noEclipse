/*
 * DoubleMatrix2x2.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: radu
 */

#include "DoubleMatrix2x2.hpp"

DoubleMatrix2x2::DoubleMatrix2x2()
{
	mMatrix[0] = 0.0;
	mMatrix[1] = 0.0;
	mMatrix[2] = 0.0;
	mMatrix[3] = 0.0;
}

DoubleMatrix2x2::~DoubleMatrix2x2()
{
}

DoubleMatrix2x2::DoubleMatrix2x2(const double m11, const double m12,
								 const double m21, const double m22)
{
	mMatrix[0] = m11;
	mMatrix[1] = m12;
	mMatrix[2] = m21;
	mMatrix[3] = m22;
}

DoubleMatrix2x2::DoubleMatrix2x2(const DoubleMatrix2x2& m)
{
	mMatrix[0] = m.Get(0, 0);
	mMatrix[1] = m.Get(0, 1);
	mMatrix[2] = m.Get(1, 0);
	mMatrix[3] = m.Get(1, 1);
}

double DoubleMatrix2x2::Get(const int i, const int j) const
{
	return mMatrix[2 * i + j];
}

double DoubleMatrix2x2::Determinant() const
{
	return mMatrix[0] * mMatrix[3] - mMatrix[1] * mMatrix[2];
}

DoubleMatrix2x2 DoubleMatrix2x2::Inverse() const
{
	double det = Determinant();
	if (det == 0) {
		std::cout << "The determinant is 0. Returning an zero matrix"
				  << std::endl;
		return DoubleMatrix2x2();
	} else {
		return DoubleMatrix2x2(Get(1, 1) / det, - Get(0, 1) / det,
							   - Get(1, 0) / det, Get(0, 0) / det);
	}
}

DoubleMatrix2x2& DoubleMatrix2x2::operator=(const DoubleMatrix2x2& m)
{
	mMatrix[0] = m.Get(0, 0);
	mMatrix[1] = m.Get(0, 1);
	mMatrix[2] = m.Get(1, 0);
	mMatrix[3] = m.Get(1, 1);

	return *this;
}

DoubleMatrix2x2 DoubleMatrix2x2::operator-() const
{
	return DoubleMatrix2x2(- mMatrix[0], - mMatrix[1],
						   - mMatrix[2], - mMatrix[3]);
}

DoubleMatrix2x2 DoubleMatrix2x2::operator+(const DoubleMatrix2x2& m) const
{
	return DoubleMatrix2x2(mMatrix[0] + m.Get(0, 0),
						   mMatrix[1] + m.Get(0, 1),
						   mMatrix[2] + m.Get(1, 0),
						   mMatrix[3] + m.Get(1, 1));
}

DoubleMatrix2x2 DoubleMatrix2x2::operator-(const DoubleMatrix2x2& m) const
{
	return DoubleMatrix2x2(mMatrix[0] - m.Get(0, 0),
						   mMatrix[1] - m.Get(0, 1),
						   mMatrix[2] - m.Get(1, 0),
						   mMatrix[3] - m.Get(1, 1));
}

void DoubleMatrix2x2::Multiply(const double d)
{
	mMatrix[0] *= d;
	mMatrix[1] *= d;
	mMatrix[2] *= d;
	mMatrix[3] *= d;
}

std::ostream& operator<<(std::ostream& output, const DoubleMatrix2x2& m)
{
	output << m.mMatrix[0] << " " << m.mMatrix[1] << std::endl;
	output << m.mMatrix[2] << " " << m.mMatrix[3];

	return output;
}
