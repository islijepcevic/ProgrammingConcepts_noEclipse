/*
 * ForwardEulerSolver.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "ForwardEulerSolver.hpp"
#include "Exception.hpp"

ForwardEulerSolver::ForwardEulerSolver()
{}

ForwardEulerSolver::~ForwardEulerSolver()
{}

void ForwardEulerSolver::SolveEquation(std::ostream& stream)
{
	double y = GetInitialValue();

	double t = GetInitialTime();

	double h = GetStepSize();
	assert(h > 1e-6);
	std::cout << "Step size: " << h << std::endl;

	int n = static_cast<int>(
			std::floor((GetFinalTime() - GetInitialTime()) / h));

	stream << t << " " << y << "\n";

	for (int i = 1; i <= n; ++i) {
		double temp = y + h * RightHandSide(y, t);
		if (-1e-6 <= temp && temp <= 0.0) {
			y = 0.0;
		} else if (1.0 <= temp && temp <= (1.0 + 1e-6) ) {
			y = 1.0;
		} else if (0.0 < temp && temp < 1.0) {
			y = temp;
		} else {
			// Freak out!
			throw Exception("STEP", "Step size too large.");
		}
		t += h;

		stream << t << " " << y << "\n";
	}
}
