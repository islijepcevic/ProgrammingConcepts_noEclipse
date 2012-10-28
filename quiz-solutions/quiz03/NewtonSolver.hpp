/*
 * NewtonSolver.hpp
 *
 * This class is a templated Newton solver. The template parameter is:
 * dataType - the type of the domain and range of the non-linear function;
 * 			  this class must implement arithmetic operators and must be
 * 			  printable to a std::ostream
 *
 *  Created on: Oct 27, 2012
 *      Author: radu
 */

#ifndef NEWTONSOLVER_HPP_
#define NEWTONSOLVER_HPP_

#include <iostream>

template<typename dataType>
int NewtonSolver(dataType& x0,
		         dataType (*function) (const dataType&),
		         dataType (*inverseJacobian) (const dataType&, const dataType&),
		         const double tol,
		         const int maxIter);


template<typename dataType>
int NewtonSolver(dataType& solution,
		         dataType (*function) (const dataType&),
		         dataType (*inverseJacobian) (const dataType&, const dataType&),
		         const double tol,
		         const int maxIter)
{
	dataType delta;
	dataType f_value;
	double error;
	int numIter = 0;

	f_value = function(solution);
	error = f_value.norm();

	std::cout << "x[" << numIter << "] = " << solution
			  << " \t f(x) = " << f_value << std::endl;

	while (error > tol && numIter < maxIter)
	{
		delta = inverseJacobian(solution, f_value);
		solution = solution - delta;
		++numIter;

		f_value = function(solution);
		error = f_value.norm();

		std::cout << "x[" << numIter << "] = " << solution
				  << " \t f(x) = " << f_value << std::endl;
	}

	if ( error > tol )
	{
		std::cout << "Max number of iterations reached without convergence."
				  << std::endl;
		return -numIter;
	}

	return numIter;
}

#endif /* NEWTONSOLVER_HPP_ */
