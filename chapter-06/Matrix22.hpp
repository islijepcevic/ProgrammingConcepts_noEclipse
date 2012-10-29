#ifndef MAT22
#define MAT22

#include <iostream>

class Matrix22
{
public:
    Matrix22();
    Matrix22( const Matrix22& cpy );
    Matrix22( double a11, double a12, double a21, double a22);

    ~Matrix22();

    double computeDeterminant() const;
    Matrix22 getInverse() const;

    Matrix22& operator=(const Matrix22& rhs);
    Matrix22 operator-() const;
    Matrix22 operator+(const Matrix22& other) const;
    Matrix22 operator*(const double factor) const;

    friend std::ostream& operator<<(std::ostream& out, const Matrix22& mat);

private:
    double matrix[2][2];
};


#endif /* MAT22 */
