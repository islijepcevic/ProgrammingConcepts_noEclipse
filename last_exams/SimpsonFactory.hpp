/*
 * SimpsonFactory.hpp
 *
 * factory for SimpsonRule
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#ifndef SIMPSON_FACTORY
#define SIMPSON_FACTORY

#include "QuadratureFactory.hpp"
#include "SimpsonRule.hpp"

class SimpsonFactory : public QuadratureFactory {
public:

    virtual QuadratureRule* create(double (*func)(double), double a, double b)
                    const {

        QuadratureRule* integrator = new SimpsonRule(func, a, b);
        return integrator;
    }
};

#endif // SIMPSON_FACTORY


