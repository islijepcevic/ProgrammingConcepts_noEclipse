#ifndef FORWARDEULERSOLVERDEF
#define FORWARDEULERSOLVERDEF

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver : public AbstractOdeSolver {
public:
    ForwardEulerSolver();
    ~ForwardEulerSolver();

    virtual void solveEquation();
};

#endif /* FORWARDEULERSOLVERDEF */
