#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
    double mRealPart;
    double mImaginaryPart;
public:
    // Constructors
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(const ComplexNumber& c);
    ComplexNumber(const double d);

    // Get methods
    double GetRealPart() const;
    double GetImaginaryPart() const;

    // Public methods
    double CalculateModulus() const;
    double CalculateArgument() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber CalculateConjugate() const;
    void SetConjugate();

    // Operators
    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    ComplexNumber operator*(const double d) const;
    ComplexNumber operator*(const ComplexNumber& z) const;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& output,
    								const ComplexNumber& z);
    friend double RealPart(const ComplexNumber& z);
    friend double ImaginaryPart(const ComplexNumber& z);
};

#endif

