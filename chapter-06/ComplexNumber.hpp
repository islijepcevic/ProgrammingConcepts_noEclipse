#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
    double mRealPart;
    double mImaginaryPart;
public:
    ComplexNumber();
    ComplexNumber(double x, double y);
    ComplexNumber(const ComplexNumber& z);
    ComplexNumber(const double real);

    double getRealPart() const;
    double getImaginaryPart() const;

    double CalculateModulus() const;
    double CalculateArgument() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber CalculateConjugate() const;
    void SetConjugate();

    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber& operator+=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    ComplexNumber operator*(const ComplexNumber& z) const;
    
    friend std::ostream& operator<<(std::ostream& output,
        const ComplexNumber& z);

    friend double realPart(const ComplexNumber& z);
    friend double imaginaryPart(const ComplexNumber& z);
};

#endif
