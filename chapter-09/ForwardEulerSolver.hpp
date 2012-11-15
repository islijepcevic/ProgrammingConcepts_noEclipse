/*
 * ForwardEulerSolver.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef FORWARDEULERSOLVER_HPP_
#define FORWARDEULERSOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver: public AbstractOdeSolver {
public:
	ForwardEulerSolver();
	virtual ~ForwardEulerSolver();

	virtual void SolveEquation(std::ostream& stream);
};

#endif /* FORWARDEULERSOLVER_HPP_ */
