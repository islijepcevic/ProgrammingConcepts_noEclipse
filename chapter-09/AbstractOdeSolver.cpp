/*
 * AbstractOdeSolver.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "AbstractOdeSolver.hpp"

AbstractOdeSolver::AbstractOdeSolver()
	: stepSize(),
	  initialTime(),
	  finalTime(),
	  initialValue(),
	  f_rhs(0)
{}

AbstractOdeSolver::~AbstractOdeSolver()
{}

void AbstractOdeSolver::SetStepSize(const double h)
{
	stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(const double t0, const double t1)
{
	initialTime = t0;
	finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(const double y0)
{
	initialValue = y0;
}

void AbstractOdeSolver::SetRightHandSide(double (*f)(double y, double t))
{
	f_rhs = f;
}

double AbstractOdeSolver::RightHandSide(double y, double t) const
{
	return f_rhs(y, t);
}
