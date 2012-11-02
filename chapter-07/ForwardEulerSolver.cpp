/*
 * ForwardEulerSolver.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "ForwardEulerSolver.hpp"

#include <cmath>

ForwardEulerSolver::ForwardEulerSolver()
{}

ForwardEulerSolver::~ForwardEulerSolver()
{}

void ForwardEulerSolver::SolveEquation(std::ostream& stream)
{
	double y_prev = GetInitialValue();
	double y_next;

	double t_prev = GetInitialTime();
	double t_next;

	double h = GetStepSize();
	int n = static_cast<int>(
			std::floor((GetFinalTime() - GetInitialTime()) / h));

	stream << t_prev << " " << y_prev << "\n";

	for (int i = 1; i <= n; ++i) {
		y_next = y_prev + h * RightHandSide(y_prev, t_prev);
		t_next = t_prev + h;

		stream << t_next << " " << y_next << "\n";
		y_prev = y_next;
		t_prev = t_next;
	}
}
