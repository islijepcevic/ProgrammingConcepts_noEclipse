/*
 * ArrayUtil.cpp
 *
 * Utility functions for using 1D and 2D arrays
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#include <cassert>
#include <iostream>
#include <fstream>

/*
 * Reads a matrix from a file/. This function handles memory allocation but
 * the DeleteMatrix function must be called at the end of the program
 */
void Read(const char* file_name, double**& M, int& n_rows,
				int& n_cols);

/*
 * Reads a vector from a file/. This function handles memory allocation but
 * the DeleteMatrix function must be called at the end of the program
 */
void Read(const char* file_name, double*& v, int& n_elem);

// Allocate memory for an n_rows x n_cols matrix
void Allocate(double**& M, const int n_rows, const int n_cols);

// Allocate memory for an n_elem matrix
void Allocate(double*& v, const int n_elem);

// Release memory used by a previously allocated matrix
void Delete(double**& M, const int n_rows);

// Release memory used by a previously allocated vector
void Delete(double*& v);

// Does matrix multiplication C = A * B ; C must be allocated
void Multiply(double** A,
			  double** B,
			  const double n_rows_A, const double n_cols_A,
			  const double n_rows_B, const double n_cols_B,
			  double**& C);

// Does matrix multiplication w = v * A; w must be allocated
void Multiply(double* v,
			  double** A,
			  const double n_rows_A, const double n_cols_A,
			  double*& w);

// Does matrix multiplication w = A * v; w must be allocated
void Multiply(double** A,
			  double* v,
			  const double n_rows_A, const double n_cols_A,
			  double*& w);

// Does matrix multiplication B = A * s ; B must be allocated
void Multiply(double** A,
			  const double s,
			  const double n_rows_A, const double n_cols_A,
			  double**& B);

void Print(double** M, const int n_rows, const int n_cols,
				 std::ostream& os);

void Print(double* v, const int n_elem, std::ostream& os,
		   const bool transpose);

#endif // ARRAY_UTIL_H
