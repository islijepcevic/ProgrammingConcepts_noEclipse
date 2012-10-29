#include "AbstractOdeSolver.hpp"

void AbstractOdeSolver::setStepSize(double h)
{
    stepSize = h;
}

void AbstractOdeSolver::setTimeInterval(double t0, double t1)
{
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::setInitialValue(double y0)
{
    initialValue = y0;
}
