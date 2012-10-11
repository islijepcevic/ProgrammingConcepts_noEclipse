/*
 * Gauss.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: rpopescu
 */

#include <cmath>

#include "Gauss.hpp"
#include "ArrayUtil.hpp"

void GaussPartialPivoting(double**& A, double*& b, const int n)
{
	for (int k = 0; k < n; ++k) {
		Pivot(A, b, k, n);

		for (int i = k + 1; i < n; ++i) {
			double m = A[i][k] / A[k][k];
			for (int j = k + 1; j < n; ++j) {
				A[i][j] -= m * A[k][j];
			}
			b[i] -= m * b[k];
		}
		// Zero out below
		for (int i = k + 1; i < n; ++i) {
			A[i][k] = 0;
		}
	}
}

void Pivot(double**& A, double*& b, const int k, const int n)
{
	double max = std::fabs(A[k][k]);
	int idx_max = k;

	for (int i = k + 1; i < n; ++i) {
		double ev = std::fabs(A[i][k]);
		if (ev > max) {
			max = ev;
			idx_max = i;
		}
	}

	// Swap values in rhs b
	double t = b[k];
	b[k] = b[idx_max];
	b[idx_max] = t;

	// Swap rows in matrix A
	double* p = A[k];
	A[k] = A[idx_max];
	A[idx_max] = p;
}

void BackwardSolve(double**& A, double*& b, const int n, double*& x)
{
	for (int i = n - 1; i >= 0; --i) {
		x[i] = b[i];
		for (int j = i + 1; j < n; ++j) {
			x[i] -= A[i][j] * x[j];
		}
		x[i] /= A[i][i];
	}
}
