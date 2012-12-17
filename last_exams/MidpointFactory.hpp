/*
 * MidpointFactory.hpp
 *
 * factory for MidpointRule
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#ifndef MIDPOINT_FACTORY
#define MIDPOINT_FACTORY

#include "QuadratureFactory.hpp"
#include "MidpointRule.hpp"

class MidpointFactory : public QuadratureFactory {
public:

    virtual QuadratureRule* create(double (*func)(double), double a, double b) 
                    const {

        QuadratureRule* integrator = new MidpointRule(func, a, b);
        return integrator;
    }
};

#endif // MIDPOINT_FACTORY

