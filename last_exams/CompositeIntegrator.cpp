/*
 * CompositeIntegrator.hpp
 *
 * a class for composite integrator
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#include "CompositeIntegrator.hpp"

void CompositeIntegrator::integrate() {

    mResult = 0;

    mGrid.resetIteration();

    while (mGrid.hasNextInterval()) {
        
        const Interval& interval = mGrid.nextInterval();

        QuadratureRule* localIntegrator = mFactory->create(mFunction, 
                                                interval.xLow, interval.xHigh);

        localIntegrator->integrate();

        mResult += localIntegrator->getResult();
    }
}
