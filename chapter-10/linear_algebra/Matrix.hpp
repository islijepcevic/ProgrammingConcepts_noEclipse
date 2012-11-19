/*
 * Matrix.hpp
 *
 * header for Matrix class
 *
 * created by: Ivan Slijepcevic
 */

#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include <vector>

class Matrix {
private:

    int mNumRows;
    int mNumCols;

    std::vector< std::vector<double> > mData;

public:

    Matrix(const Matrix& m);
    Matrix(int numRows, int numCols);
    virtual ~Matrix();

    int getNumRows() const;
    int gutNumCols() const;
};

#endif // MATRIXHEADERDEF
