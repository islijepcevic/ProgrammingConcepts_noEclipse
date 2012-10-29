#include <cassert>

#include "Matrix22.hpp"


Matrix22::Matrix22(  ) :
    Matrix22(0., 0., 0., 0.)
{
}

Matrix22::Matrix22( const Matrix22 &cpy ) :
    Matrix22(cpy.matrix[0][0], cpy.matrix[0][1], 
            cpy.matrix[1][0], cpy.matrix[1][1])
{
}


Matrix22::Matrix22( double a11, double a12, double a21, double a22)
{
    matrix[0][0] = a11;
    matrix[0][1] = a12;
    matrix[1][0] = a21;
    matrix[1][1] = a22;
}

Matrix22::~Matrix22()
{
}

double Matrix22::computeDeterminant() const
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

Matrix22 Matrix22::getInverse() const
{
    double det = computeDeterminant();
    assert(fabs(det) > 1e-8);

    Matrix22 inv(matrix[1][1], -matrix[0][1], -matrix[1][0], matrix[0][0]);

    return inv * (1.0 / det);
}

Matrix22& Matrix22::operator=(const Matrix22& rhs)
{
    matrix[0][0] = rhs.matrix[0][0];
    matrix[0][1] = rhs.matrix[0][1];
    matrix[1][0] = rhs.matrix[1][0];
    matrix[1][1] = rhs.matrix[1][1];

    return *this;
}

Matrix22 Matrix22::operator-() const
{
    Matrix22 negative(
     -matrix[0][0],
     -matrix[0][1],
     -matrix[1][0],
     -matrix[1][1]
    );

    return negative;
}

Matrix22 Matrix22::operator+(const Matrix22& other) const
{
    Matrix22 sum(
        matrix[0][0] + other.matrix[0][0],
        matrix[0][1] + other.matrix[0][1],
        matrix[1][0] + other.matrix[1][0],
        matrix[1][1] + other.matrix[1][1]
    );

    return sum;
}

Matrix22 Matrix22::operator*(const double factor) const
{
    Matrix22 product(
        matrix[0][0] * factor,
        matrix[0][1] * factor,
        matrix[1][0] * factor,
        matrix[1][1] * factor
    );

    return product;
}

std::ostream& operator<<(std::ostream& out, const Matrix22& mat)
{
    out << mat.matrix[0][0] << " " << mat.matrix[0][1] << std::endl;
    out << mat.matrix[1][0] << " " << mat.matrix[1][1] << std::endl;

    return out;
}
