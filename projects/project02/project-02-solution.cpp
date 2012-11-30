/*
 * project-02-solution.cpp
 *
 * Cholesky solver for 2D Laplacian problem on a square regular
 * grid.
 *
 * Laplacian(u) = 0; u(x,0) = 1;
 *
 * The program takes as parameters the number of points along one side of
 * the square grid and the storage type, dense or csr for the system
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
#include "CholeskySolver.hpp"
#include "LUSolver.hpp"
#include "WallClock.hpp"

typedef double Scalar;

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::cout << "Missing parameters. Please run as: \n"
				  << "  ./project-01-solution <npoints> <storage> with:\n"
				  << "\n<npoints> the number of grid points on the side of the "
				  << "regular square grid\n"
				  << "\n<storage> dense or band"
				  << std::endl;
		return 1;
	}

	// Number of points along one side of the square regular grid
	int nx = atoi(argv[1]);
	// Storage type for the system matrix A: dense or band
	const std::string storageType(argv[2]);

	/*
	 * Number of DOF (N) is equal to just the interior grid points, because of
	 * the Dirichlet boundary conditions.
	 */
	int N = (nx - 2) * (nx - 2);

	// Right hand side vector
	Vector<Scalar> b(N);
	// Dirichlet boundary conditions on the lower side of the square:
	//    u(x,0) = 1;
	// The static casts are needed to prevent some warnings (-Wconversion)
	Scalar h = static_cast<Scalar>(1.0 / static_cast<Scalar>(nx - 1));
	Scalar h2 = h * h;
	for (int i = 0; i < nx - 2; ++i) {
		b[i] = static_cast<Scalar>(1.0 / h2);
	}

	// Fill the system matrix A
	// The Laplacian matrix generator needs a pointer to the base class
	AbstractMatrix<Scalar>* A;
	Laplacian2DMatrixGenerator(A, nx, storageType);

	// Solution vectors
	Vector<Scalar> uChol(N);
	Vector<Scalar> uCG(N);
        Vector<Scalar> uLU(N);

	// Time the solvers
	WallClock timer;

	// Solve the system Ax = b with the CG solver
	timer.start();

	// Solve the system Ax = b;
	int numIter = ConjugateGradient(*A, b, uCG, 1e-6, 100);

	timer.stop();

	std::cout << "CG reached solution after " << numIter << " iterations:\n";

	std::cout << "Solution with CG solver is:\n";
	uCG.Print();

	std::cout << "Time to solution with the CG solver is: "
			  << timer.elapsedTime() << std::endl;
        std::cout << std::endl;


	// Solve the system Ax = b with the Cholesky solver
	timer.start();

	AbstractDirectSolver<Scalar>* cholSolver = new CholeskySolver<Scalar>();
	cholSolver->Factorize(*A);
	cholSolver->Solve(uChol, b);

	timer.stop();

	std::cout << "Time to solution with the Cholesky solver is: "
			  << timer.elapsedTime() << std::endl;

	std::cout << "Solution with Cholesky solver is:\n";
	uChol.Print();

	Vector<Scalar> diff(uChol - uCG);

	std::cout << "norm of the difference between Choleski and CG = "
			<< diff.norm() << std::endl;
        std::cout << std::endl;

        // Solve the system with LU solver
        timer.start();

        AbstractDirectSolver<Scalar>* luSolver = new LUSolver<Scalar>();
        luSolver->Factorize(*A);
        luSolver->Solve(uLU, b);

        timer.stop();

	std::cout << "Time to solution with the LU solver is: "
			  << timer.elapsedTime() << std::endl;

	std::cout << "Solution with LU solver is:\n";
	uLU.Print();

	Vector<Scalar> diff2(uLU - uChol);

	std::cout << "norm of the difference between LU and Cholesky = "
			<< diff2.norm() << std::endl;
        std::cout << std::endl;

	// Clean up
	delete cholSolver;
	delete A;

    return 0;
}
