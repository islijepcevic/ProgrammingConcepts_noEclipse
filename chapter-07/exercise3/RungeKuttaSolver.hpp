#ifndef RUNGEKUTTASOLVERDEF
#define RUNGEKUTTASOLVERDEF

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver {
public:
    RungeKuttaSolver();
    ~RungeKuttaSolver();

    virtual void solveEquation();
};

#endif /* RUNGEKUTTASOLVERDEF */
