/*
 * Laplacian2DMatrixGenerator.hpp
 *
 * Function that generates the finite difference matrix for a 2D Laplacian
 * problem on a regular square grid, with a 5 point FD stencil
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#include "Laplacian2DMatrixGenerator.hpp"
#include "AbstractMatrix.hpp"
#include "DenseMatrix.hpp"
#include "CsrMatrix.hpp"

/*
 * An anonymous namespace is the C++ equivalent of a static function.
 * It is limited in scope to the current source file. Using the static
 * keyword for this purpose is deprecated in C++
 */
namespace {
void insertBlock(AbstractMatrix*& M, const unsigned long row,
				 const unsigned long size,
				 const unsigned long blockSize,
				 const double diagValue,
				 const double offDiagValue)
{
	if (row > blockSize - 1) {
		M->SetElement(row, row - blockSize, offDiagValue);
	}
	M->SetElement(row, row, diagValue);
	M->SetElement(row, row + 1, offDiagValue);
	if (row < size - blockSize) {
		M->SetElement(row, row + blockSize, offDiagValue);
	}

	for (unsigned long k = 1; k < blockSize - 1; ++k) {
		unsigned long offset = row + k;
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

	unsigned long offset = row + blockSize - 1;
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

void Laplacian2DMatrixGenerator(AbstractMatrix*& M,
								const unsigned long npoints,
								const std::string& storageType)
{
	// The number of DOF is equal to the number of interior grid points
	unsigned long nIntPoints = npoints - 2;
	unsigned long N = (nIntPoints) * (nIntPoints);

	if (! storageType.compare("dense")) {
		M = new DenseMatrix(N);
	};
	// Uncomment this block of code after you've implemented the CrsMatrix class
	/*
	if (! storageType.compare("csr")) {
		M = new CsrMatrix(N, 5 * N);
	};
	*/

	double h = 1.0 / static_cast<double>(npoints - 1);
	double diagValue = 4.0 / (h * h);
	double offDiagValue = -1.0 / (h * h);

	for (unsigned long i = 0; i < N; i = i + nIntPoints) {
		insertBlock(M, i, N, nIntPoints, diagValue, offDiagValue);
	}

	// Also uncomment this block, it's absolutely necessary
	/*
	if (! storageType.compare("csr")) {
		CsrMatrix* CsrM = dynamic_cast<CsrMatrix*>(M);
		CsrM->Lock();
	};
	*/
}
