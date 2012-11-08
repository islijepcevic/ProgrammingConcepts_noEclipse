/*
 * project-01-solution.cpp
 *
 * Conjugate gradient solver for 2D Laplacian problem on a square regular
 * grid.
 *
 * Laplacian(u) = 0; u(x,0) = 1;
 *
 * The program takes as parameters the number of points along one side of
 * the square grid, the tolerance for the CG solver, the maximum number of
 * iterations to perform and the storage type, dense or csr for the system
 * matrix A
 *
 * Created on: Oct 31, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cstdlib>
#include <iostream>

#include "Vector.hpp"
#include "AbstractMatrix.hpp"
#include "Laplacian2DMatrixGenerator.hpp"
#include "ConjugateGradient.hpp"
#include "WallClock.hpp"

typedef double Scalar;

int main(int argc, char* argv[])
{
	if (argc != 5) {
		std::cout << "Missing parameters. Please run as: \n"
				  << "  ./project-01-solution <npoints> <tol> <maxiter> <storage> with:\n"
				  << "\n<npoints> the number of grid points on the side of the"
				  << "regular square grid\n"
				  << "\n<tol> the desired accuracy for the CG solver\n"
				  << "\n<maxiter> the maximum number of iterations\n"
				  << "\n<storage> dense or band (choose dense until you've "
				  << "implemented the BandMatrix class)"
				  << std::endl;
		return 1;
	}

	// Number of points along one side of the square regular grid
	unsigned long nx = atoi(argv[1]);
	// Tolerance for the CG solver
	Scalar tol = static_cast<Scalar>(atof(argv[2]));
	// Maximum number of CG iterations to perform
	int maxIter = atoi(argv[3]);
	// Storage type for the system matrix A: dense or csr (you must implement
	// CSR storage before selecting it!)
	const std::string storageType(argv[4]);

	// Timer object
	WallClock timer;
	timer.start();

	/*
	 * Number of DOF (N) is equal to just the interior grid points, because of
	 * the Dirichlet boundary conditions.
	 */
	unsigned long N = (nx - 2) * (nx - 2);

	// Right hand side vector
	Vector<Scalar> b(N);
	// Dirichlet boundary conditions on the lower side of the square:
	//    u(x,0) = 1;
	// The static casts are needed to prevent some warnings (-Wconversion)
	Scalar h = static_cast<Scalar>(1.0 / static_cast<Scalar>(nx - 1));
	Scalar h2 = h * h;
	for (unsigned long i = 0; i < nx - 2; ++i) {
		b[i] = static_cast<Scalar>(1.0 / h2);
	}

	// Solution vector
	Vector<Scalar> u(N);

	// Fill the system matrix A
	// The Laplacian matrix generator needs a pointer to the base class
	AbstractMatrix<Scalar>* A;
	Laplacian2DMatrixGenerator(A, nx, storageType);

	// Solve the system Ax = b;
	int numIter = ConjugateGradient(*A, b, u, tol, maxIter);

	timer.stop();

	std::cout << "Solution reached after " << numIter << " iterations:\n";

	u.Print();

	std::cout << "Total execution time is: "
			  << timer.elapsedTime() << std::endl;

	delete A;

    return 0;
}

