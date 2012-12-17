/*
 * CompositeIntegrator.hpp
 *
 * a class for composite integrator
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#ifndef COMPOSITE
#define COMPOSITE

#include "IntegrationGrid.hpp"
#include "QuadratureFactory.hpp"

typedef double (*fptr)(double);

/*
 * this class has a role of Context in a strategy design pattern
 * Abstract strategy is the QuadratureRule, while concrete implementations
 * include MidpointRule and SimpsonRule
 */
class CompositeIntegrator {
private:

    fptr mFunction;

    // factory for the integrator 
    QuadratureFactory* mFactory;

    IntegrationGrid mGrid;

    double mResult;

public:

    /*
     * basic constructor
     */
    CompositeIntegrator(fptr func, QuadratureFactory* factory,
                        IntegrationGrid grid) :
        mFunction(func), mFactory(factory), mGrid(grid) {
    }

    void integrate();

    double getResult() const {
        return mResult;
    }

};

#endif // COMPOSITE
