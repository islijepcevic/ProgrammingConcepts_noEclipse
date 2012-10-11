/*
 * ArrayUtil.cpp
 *
 * Utility functions for using 1D and 2D arrays
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <iostream>
#include <fstream>

#include "ArrayUtil.hpp"

/*
 * Reads a matrix from a file/. This function handles memory allocation but
 * the DeleteMatrix function must be called at the end of the program
 */
void Read(const char* file_name, double**& M, int& n_rows,
				int& n_cols)
{
	std::ifstream input_file(file_name, std::ifstream::in);

	input_file >> n_rows >> n_cols;

	M = new double*[n_rows];

	for (int i = 0; i < n_rows; ++i) {
		M[i] = new double[n_cols];
		for (int j = 0; j < n_cols; ++j) {
			input_file >> M[i][j];
		}
	}

	input_file.close();
}

void Read(const char* file_name, double*& v, int& n_elem)
{
	std::ifstream input_file(file_name, std::ifstream::in);

	input_file >> n_elem;

	v = new double[n_elem];

	for (int i = 0; i < n_elem; ++i) {
		input_file >> v[i];
	}

	input_file.close();
}

// Allocate memory for an n_rows x n_cols matrix
void Allocate(double**& M, const int n_rows, const int n_cols)
{
	M = new double*[n_rows];
	for (int i = 0; i < n_rows; ++i) {
		M[i] = new double[n_cols];
	}
}

void Allocate(double*& v, const int n_elem)
{
	v = new double[n_elem];
}

// Release memory used by a previously allocated matrix
void Delete(double**& M, const int n_rows)
{
	for (int i = 0; i < n_rows; ++i) {
		delete [] M[i];
	}
	delete [] M;
}

void Delete(double*& v)
{
	delete[] v;
}

// Does matrix multiplication C = A * B ; C must be allocated
void Multiply(double** A,
			  double** B,
			  const double n_rows_A, const double n_cols_A,
			  const double n_rows_B, const double n_cols_B,
			  double**& C)
{
	assert (n_cols_A == n_rows_B);

	for (int i = 0; i < n_rows_A; ++i) {
		for (int j = 0; j < n_cols_B; ++j) {
			C[i][j] = 0;
			for (int k = 0; k < n_cols_A; ++k) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

// Does matrix multiplication w = v * A; w must be allocated
void Multiply(double* v,
			  double** A,
			  const double n_rows_A, const double n_cols_A,
			  double*& w)
{
	for (int i = 0; i < n_cols_A; ++i) {
		w[i] = 0;
		for (int j = 0; j < n_rows_A; ++j) {
			w[i] += v[j] * A[j][i];
		}
	}
}

// Does matrix multiplication w = A * v; w must be allocated
void Multiply(double** A,
			  double* v,
			  const double n_rows_A, const double n_cols_A,
			  double*& w)
{
	for (int i = 0; i < n_rows_A; ++i) {
		w[i] = 0;
		for (int j = 0; j < n_cols_A; ++j) {
			w[i] += v[j] * A[i][j];
		}
	}
}

// Does matrix multiplication B = A * s ; B must be allocated
void Multiply(double** A,
			  const double s,
			  const double n_rows_A, const double n_cols_A,
			  double**& B)
{
	for (int i = 0; i < n_rows_A; ++i) {
		for (int j = 0; j < n_cols_A; ++j) {
			B[i][j] = A[i][j] * s;
		}
	}
}

void Print(double** M, const int n_rows, const int n_cols,
				 std::ostream& os)
{
	for (int i = 0; i < n_rows; ++i) {
		for (int j = 0; j < n_cols; ++j) {
			os << M[i][j] << " ";
		}
		os << std::endl;
	}
}

void Print(double* v, const int n_elem, std::ostream& os,
		   const bool transpose)
{
	if (transpose) {
		for (int i = 0; i < n_elem; ++i) {
			os << v[i] << std::endl;
		}
	} else {
		for (int i = 0; i < n_elem; ++i) {
			os << v[i] << " ";
		}
		os << std::endl;
	}
}
