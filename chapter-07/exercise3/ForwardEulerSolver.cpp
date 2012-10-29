#include "ForwardEulerSolver.hpp"

#include <iostream>

ForwardEulerSolver::ForwardEulerSolver() {
}

ForwardEulerSolver::~ForwardEulerSolver() {
}

/*
 * assumes everything has been set
 */
void ForwardEulerSolver::solveEquation() {

    std::cout << "Forward Euler method\n";

    double time = getInitialTime();
    double value = getInitialValue();

    while (time <= getFinalTime()) {

        std::cout << "(" << time << ",\t" << value << ")\n";

        value = value + getStepSize() * rightHandSide(value, time);
        time = time + getStepSize();
    }

}
