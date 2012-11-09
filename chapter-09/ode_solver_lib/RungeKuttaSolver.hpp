#ifndef RUNGEKUTTASOLVERDEF
#define RUNGEKUTTASOLVERDEF

#include "AbstractOdeSolver.hpp"
#include <iostream>

template<class T>
class RungeKuttaSolver : public AbstractOdeSolver<T> {
public:
    RungeKuttaSolver() {}
    ~RungeKuttaSolver() {}

    virtual void solveEquation() {

        std::cout << "Runge-Kutta method\n";

        double time = this->getInitialTime();
        T value = this->getInitialValue();

        while (time <= this->getFinalTime()) {

            std::cout << "(" << time << ",\t" << value << ")\n";

            double h = this->getStepSize();

            T k1 = h * this->rightHandSide(value, time);
            T k2 = h * this->rightHandSide(value + 0.5 * k1, time + 0.5 * h);
            T k3 = h * this->rightHandSide(value + 0.5 * k2, time + 0.5 * h);
            T k4 = h * this->rightHandSide(value + k3, time + h);

            value = value + (k1 + 2.*k2 + 2.*k3 + k4) / 6.0;
            time = time + h;
        }
    }
};

#endif /* RUNGEKUTTASOLVERDEF */
