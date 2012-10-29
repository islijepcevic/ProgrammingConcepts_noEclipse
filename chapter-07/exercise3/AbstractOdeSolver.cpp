#include "AbstractOdeSolver.hpp"

AbstractOdeSolver::~AbstractOdeSolver() {
}

double AbstractOdeSolver::getStepSize() const {
    return stepSize;
}

double AbstractOdeSolver::getInitialTime() const {
    return initialTime;
}

double AbstractOdeSolver::getFinalTime() const {
    return finalTime;
}

double AbstractOdeSolver::getInitialValue() const {
    return initialValue;
}

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

void AbstractOdeSolver::setRightHandSide(double (*fun)(double, double)) {

    rhs = fun;
}

double AbstractOdeSolver::rightHandSide(double y, double t) const {

    return rhs(y, t);
 }
