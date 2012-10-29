#include "RungeKuttaSolver.hpp"

#include <iostream>

RungeKuttaSolver::RungeKuttaSolver() {
}

RungeKuttaSolver::~RungeKuttaSolver() {
}

/*
 * assumes everything has been set
 */
void RungeKuttaSolver::solveEquation() {

    std::cout << "Runge-Kutta method\n";

    double time = getInitialTime();
    double value = getInitialValue();

    while (time <= getFinalTime()) {

        std::cout << "(" << time << ",\t" << value << ")\n";

        double h = getStepSize();

        double k1 = h * rightHandSide(value, time);
        double k2 = h * rightHandSide(value + 0.5 * k1, time + 0.5 * h);
        double k3 = h * rightHandSide(value + 0.5 * k2, time + 0.5 * h);
        double k4 = h * rightHandSide(value + k3, time + h);

        value = value + (k1 + 2.*k2 + 2.*k3 + k4) / 6.0;
        time = time + h;
    }

}

