/*
 * ComplexMatrix3x3.cpp
 *
 *  Created on: Oct 19, 2012
 *      Author: rpopescu
 */

#include "ComplexMatrix3x3.hpp"

ComplexMatrix3x3::ComplexMatrix3x3()
{
	mMatrix = new ComplexNumber*[3];
	for (int i = 0; i < 3; ++i) {
		mMatrix[i] = new ComplexNumber[3];
		for (int j = 0; j < 3; ++j) {
			mMatrix[i][j] = 0;
		}
	}
}

ComplexMatrix3x3::ComplexMatrix3x3(const ComplexMatrix3x3& m)
	: mMatrix(new ComplexNumber*[3])
{
	for (int i = 0; i < 3; ++i) {
		mMatrix[i] = new ComplexNumber[3];
		for (int j = 0; j < 3; ++j) {
			mMatrix[i][j] = m.Get(i, j);
		}
	}
}

ComplexMatrix3x3::~ComplexMatrix3x3()
{
	for (int i = 0; i < 3; ++i) {
		delete[] mMatrix[i];
	}
	delete[] mMatrix;
}

ComplexNumber ComplexMatrix3x3::Get(const int i, const int j) const
{
	return mMatrix[i][j];
}

void ComplexMatrix3x3::Set(const int i, const int j,
						   const ComplexNumber& value) {
	mMatrix[i][j] = value;
}

bool ComplexMatrix3x3::IsZero() const
{
	double tol = 1e-10;
	bool isZero = true;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if ((mMatrix[i][j].GetRealPart() > tol)
				|| (mMatrix[i][j].GetImaginaryPart() > tol)) {
				isZero = false;
			}
		}
	}

	return isZero;
}

ComplexMatrix3x3 ComplexMatrix3x3::PowerOverFact(const int n) const
{
	ComplexMatrix3x3 t(*this);

	for (int i = 1; i <= n; ++i) {
		t = t * (*this) * (1.0 / i);
	}

	return t;
}

void ComplexMatrix3x3::Exponential(ComplexMatrix3x3& E,
								   const int power) const
{

	if (power == 0) {
		// Should it return 1 or I_3 ?
		E.Set(0, 0, 1);
		E.Set(1, 1, 1);
		E.Set(2, 2, 1);
		return ;
	}
	if (IsZero()) {
		// The empty constructor initializes to 0 so the next line is not
		// needed in this case; I'm returning 0_3, not scalar 0
		///E = ComplexMatrix3x3();
	}

	// Could also compute this like:
	//     E = 1 + A (1 + A/2 (1 + A/3 (1 + A/4 .....
	//const ComplexMatrix3x3& A(*this);
	for (int i = 1; i <= power; ++i) {
		E = E + PowerOverFact(i);
		//E = (E * (A * (1.0 / i))) + 1.0;
	}
}

void ComplexMatrix3x3::Print(std::ostream& s) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			s << mMatrix[i][j] << " ";
		}
		s << std::endl;
	}
}

ComplexMatrix3x3& ComplexMatrix3x3::operator=(const ComplexMatrix3x3& m)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			mMatrix[i][j] = m.Get(i, j);
		}
	}

	return *this;
}

ComplexMatrix3x3 ComplexMatrix3x3::operator*(const double d) const
{
	ComplexMatrix3x3 t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			t.Set(i, j, mMatrix[i][j] * d);
		}
	}

	return t;
}

ComplexMatrix3x3 ComplexMatrix3x3::operator+(const double d) const
{
	ComplexMatrix3x3 t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			t.Set(i, j, mMatrix[i][j] + d);
		}
	}

	return t;
}

ComplexMatrix3x3 ComplexMatrix3x3::operator+(const ComplexMatrix3x3& m) const
{
	ComplexMatrix3x3 t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			t.Set(i, j, mMatrix[i][j] + m.Get(i, j));
		}
	}

	return t;
}

ComplexMatrix3x3 ComplexMatrix3x3::operator*(const ComplexMatrix3x3& m) const
{
	ComplexMatrix3x3 t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			ComplexNumber accum(0.0);
			for (int k = 0; k < 3; ++k) {
				accum = accum + (mMatrix[i][k] * m.Get(k, j));
			}
			t.Set(i, j, accum);
		}
	}

	return t;
}
