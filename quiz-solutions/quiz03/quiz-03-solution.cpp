/*
 * quiz-03-solution.cpp
 *
 * Templated Newton solver
 *
 * Created on: Oct 26, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include "Vector2D.hpp"
#include "Scalar.hpp"
#include "Functions.hpp"
#include "NewtonSolver.hpp"



int main(int argc, char* argv[])
{
	// Perform the solve for the Vector2D function
	Vector2D solution(0.7, 0.3);
	double tolerance = 1e-6;
	int maxIterations = 50;
	int iterations;

	iterations = NewtonSolver<Vector2D>(solution, VectorFunction,
										VectorSolveJacobian,
										tolerance, maxIterations);

	std::cout << "solution = " << solution << " reached after "
			  << iterations << " iterations." << std::endl;

	// Perform the solve for the scalar function
	Scalar x(0.7);

	iterations = NewtonSolver<Scalar>(x, ScalarFunction, ScalarSolveJacobian,
									  tolerance, maxIterations);

	std::cout << "solution = " << x << " reached after "
			  << iterations << " iterations." << std::endl;

    return 0;
}

