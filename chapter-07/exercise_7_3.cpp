#include "exercise3/ForwardEulerSolver.hpp"
#include "exercise3/RungeKuttaSolver.hpp"

#include <iostream>

double odeFunction(double y, double t) {
    return 1.0 + t;
}

double solution(double t) {
    return (t*t + 2.0*t + 4.0) / 2.0;
}

void printSolutionValues(double (*fun)(double), double initialTime,
                            double finalTime, double stepSize) {

    std::cout << "True function values; step size " << stepSize << "\n";
    for (double time = initialTime; time <= finalTime; time += stepSize) {
        std::cout << "(" << time << ",\t" << fun(time) << ")\n";
    }
}

int main() {

    ForwardEulerSolver fwSolver;

    fwSolver.setRightHandSide( odeFunction );
    fwSolver.setTimeInterval(0.0, 1.0);
    fwSolver.setInitialValue(2.0);

    RungeKuttaSolver rkSolver;

    rkSolver.setRightHandSide( odeFunction );
    rkSolver.setTimeInterval(0.0, 1.0);
    rkSolver.setInitialValue(2.0);

    double stepSizes[3] = {0.2, 0.1, 0.05};
    for (int i = 0; i < 3; i++) {
        double stepsize = stepSizes[i];

        fwSolver.setStepSize(stepsize);
        rkSolver.setStepSize(stepsize);

        printSolutionValues(solution, 0.0, 1.0, stepsize);
        std::cout << std::endl;

        fwSolver.solveEquation();
        std::cout << std::endl;

        rkSolver.solveEquation();
        std::cout << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
