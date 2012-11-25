/*
 * Laplacian2DMatrixGenerator.hpp
 *
 * Function that generates the finite difference matrix for a 2D Laplacian
 * problem on a regular square grid, with a 5 point FD stencil
 * Templated on the type of the values
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef LAPLACIAN2DMATRIXGENERATOR_HPP_
#define LAPLACIAN2DMATRIXGENERATOR_HPP_

#include <string>

#include "Laplacian2DMatrixGenerator.hpp"

#include "AbstractMatrix.hpp"
#include "DenseMatrix.hpp"
#include "BandedMatrix.hpp"

/*
 * An anonymous namespace is the C++ equivalent of a static function.
 * It is limited in scope to the current source file. Using the static
 * keyword for this purpose is deprecated in C++
 */
namespace {
template<typename ValueType>
void insertBlock(AbstractMatrix<ValueType>*& M,
				 const int row,
				 const int size,
				 const int blockSize,
				 const ValueType diagValue,
				 const ValueType offDiagValue)
{
	if (row > blockSize - 1) {
		M->SetElement(row, row - blockSize, offDiagValue);
	}
	M->SetElement(row, row, diagValue);
	M->SetElement(row, row + 1, offDiagValue);
	if (row < size - blockSize) {
		M->SetElement(row, row + blockSize, offDiagValue);
	}

	for (int k = 1; k < blockSize - 1; ++k) {
		int offset = row + k;
		if (row > blockSize - 1) {
			M->SetElement(offset, offset - blockSize, offDiagValue);
		}
		M->SetElement(offset, offset - 1, offDiagValue);
		M->SetElement(offset, offset, diagValue);
		M->SetElement(offset, offset + 1, offDiagValue);
		if (row < size - blockSize) {
			M->SetElement(offset, offset + blockSize, offDiagValue);
		}
	}

	int offset = row + blockSize - 1;
	if (row > blockSize - 1) {
		M->SetElement(offset, offset - blockSize, offDiagValue);
	}
	M->SetElement(offset, offset - 1, offDiagValue);
	M->SetElement(offset, offset, diagValue);
	if (row < size - blockSize) {
		M->SetElement(offset, offset + blockSize, offDiagValue);
	}
}
}

/*
 * Function that generates the finite difference matrix for a 2D Laplacian
 * problem on a regular square grid, with a 5 point FD stencil
 *
 * Parameters:
 * 		M - AbstractMatrix pointer; does not need to be initialized before
 * 		    calling the function
 * 		npoints - number of points along one side of the square grid
 * 		storageType - can be "dense" or "sparse" (do not select sparse until
 * 			you've implemented the CsrMatrix class)
 */
template<typename ValueType>
void Laplacian2DMatrixGenerator(AbstractMatrix<ValueType>*& M,
								const int npoints,
								const std::string& storageType);

template<typename ValueType>
void Laplacian2DMatrixGenerator(AbstractMatrix<ValueType>*& M,
								const int npoints,
								const std::string& storageType)
{
	// The number of DOF is equal to the number of interior grid points
	int nIntPoints = npoints - 2;
	int N = (nIntPoints) * (nIntPoints);

	if (! storageType.compare("dense")) {
		M = new DenseMatrix<ValueType>(N);
	};
	if (! storageType.compare("band")) {
		M = new BandedMatrix<ValueType>(N, static_cast<int>(nIntPoints),
										static_cast<int>(nIntPoints));
	};

	ValueType h = static_cast<ValueType>(1.0
										 / static_cast<ValueType>(npoints - 1));
	ValueType diagValue = static_cast<ValueType>(4.0 / (h * h));
	ValueType offDiagValue = static_cast<ValueType>(-1.0 / (h * h));

	for (int i = 0; i < N; i = i + nIntPoints) {
		insertBlock(M, i, N, nIntPoints, diagValue, offDiagValue);
	}
}


#endif /* LAPLACIAN2DMATRIXGENERATOR_HPP_ */
