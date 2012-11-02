/*
 * RungeKuttaSolver.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef RUNGEKUTTASOLVER_HPP_
#define RUNGEKUTTASOLVER_HPP_

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver: public AbstractOdeSolver {
public:
	RungeKuttaSolver();
	virtual ~RungeKuttaSolver();

	virtual void SolveEquation(std::ostream& stream);
};

#endif /* RUNGEKUTTASOLVER_HPP_ */
