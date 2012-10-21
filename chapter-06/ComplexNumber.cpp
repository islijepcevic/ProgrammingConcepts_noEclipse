#include "ComplexNumber.hpp"

#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& c)
	: mRealPart(c.GetRealPart()),
	  mImaginaryPart(c.GetImaginaryPart())
{}

// Constructor for number with only real part
ComplexNumber::ComplexNumber(const double d)
	: mRealPart(d),
	  mImaginaryPart(0.0)
{}

// Get methods

double ComplexNumber::GetRealPart() const {
	return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const {
	return mImaginaryPart;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart+
    mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre’s theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);

    return z;
}

// Computes the complex conjugate
ComplexNumber ComplexNumber::CalculateConjugate() const
{
	return ComplexNumber(mRealPart, -mImaginaryPart);
}

void ComplexNumber::SetConjugate()
{
	mImaginaryPart = - mImaginaryPart;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

ComplexNumber ComplexNumber::operator*(const double d) const
{
	ComplexNumber t(mRealPart * d, mImaginaryPart * d);

	return t;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
	return ComplexNumber(mRealPart * z.GetRealPart()
						 - mImaginaryPart * z.GetImaginaryPart(),
						 mImaginaryPart * z.GetRealPart()
						 + mRealPart * z.GetImaginaryPart());
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }

    return output;
}

double RealPart(const ComplexNumber& z)
{
	return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
	return z.mImaginaryPart;
}
