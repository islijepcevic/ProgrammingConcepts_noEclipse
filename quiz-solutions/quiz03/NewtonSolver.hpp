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


#endif /* NEWTONSOLVER_HPP_ */
