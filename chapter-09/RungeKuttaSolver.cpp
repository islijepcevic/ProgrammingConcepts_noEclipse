/*
 * RungeKuttaSolver.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#include "RungeKuttaSolver.hpp"
#include "Exception.hpp"

#include <cmath>
#include <cassert>
#include <iostream>

RungeKuttaSolver::RungeKuttaSolver()
{}

RungeKuttaSolver::~RungeKuttaSolver()
{}

void RungeKuttaSolver::SolveEquation(std::ostream& stream)
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
		double k1 = h * RightHandSide(y, t);
		double k2 = h * RightHandSide(y + 0.5 * k1, t + 0.5 * h);
		double k3 = h * RightHandSide(y + 0.5 * k2, t + 0.5 * h);
		double k4 = h * RightHandSide(y + k3, t + h);

		double temp = y + 1.0/6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
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
