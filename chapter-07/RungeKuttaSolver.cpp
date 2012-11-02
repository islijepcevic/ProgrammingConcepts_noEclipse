/*
 * RungeKuttaSolver.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "RungeKuttaSolver.hpp"

#include <cmath>

RungeKuttaSolver::RungeKuttaSolver()
{}

RungeKuttaSolver::~RungeKuttaSolver()
{}

void RungeKuttaSolver::SolveEquation(std::ostream& stream)
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
		double k1 = h * RightHandSide(y_prev, t_prev);
		double k2 = h * RightHandSide(y_prev + 0.5 * k1, t_prev + 0.5 * h);
		double k3 = h * RightHandSide(y_prev + 0.5 * k2, t_prev + 0.5 * h);
		double k4 = h * RightHandSide(y_prev + k3, t_prev + h);

		y_next = y_prev + 1.0/6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
		t_next = t_prev + h;

		stream << t_next << " " << y_next << "\n";
		y_prev = y_next;
		t_prev = t_next;
	}
}
