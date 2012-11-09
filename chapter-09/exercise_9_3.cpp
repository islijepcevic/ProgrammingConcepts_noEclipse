#include "data_types/Probability.hpp"
#include "ode_solver_lib/AbstractOdeSolver.hpp"
#include "ode_solver_lib/ForwardEulerSolver.hpp"
#include "ode_solver_lib/RungeKuttaSolver.hpp"

#include <iostream>
#include <cassert>

double f(Probability y, double t) {
    return -100.0 * y;
}

int main(int argc, char *argv[]) {

    assert(argc == 2);
    char argument = argv[1][0];
    assert(argument == 'r' || argument == 'f');

    AbstractOdeSolver<Probability>* solver = NULL;
    if (argument == 'r') {
        solver = new RungeKuttaSolver<Probability>();
    } else {
        solver = new ForwardEulerSolver<Probability>();
    }

    solver->setRightHandSide( f );
    solver->setTimeInterval(0.0, 100.0);
    solver->setInitialValue(0.8);

    double h = 10.;
    bool cont = true;

    while (cont) {

        std::cout << "h = " << h << std::endl;

        solver->setStepSize(h);

        try {
            solver->solveEquation();

            std::cout << "solution found for h = " << h << std::endl;
            cont = false;
        } catch (ProbabilityException& ex) {

            std::cout << "solution couldn't be found for h = " << h << std::endl
                << "reducing h to half of its size\n\n";

            h /= 2;

            if (h < 1e-8) {
                std::cout << "h too small, terminating\n";
                cont = false;
            }
        }
    }

    return 0;
}
