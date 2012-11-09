#ifndef FORWARDEULERSOLVERDEF
#define FORWARDEULERSOLVERDEF

#include "AbstractOdeSolver.hpp"
#include <iostream>

template<class T>
class ForwardEulerSolver : public AbstractOdeSolver<T> {
public:
    ForwardEulerSolver() {}
    ~ForwardEulerSolver() {}

    virtual void solveEquation() {

        std::cout << "Forward Euler method\n";

        double time = this->getInitialTime();
        T value = this->getInitialValue();

        while (time <= this->getFinalTime()) {

            std::cout << "(" << time << ",\t" << value << ")\n";

            value = value + this->getStepSize() * this->rightHandSide(value, time);
            time = time + this->getStepSize();
        }
    }
};

#endif /* FORWARDEULERSOLVERDEF */
