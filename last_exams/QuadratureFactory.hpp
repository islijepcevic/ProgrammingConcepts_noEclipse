/*
 * QuadratureFactory.hpp
 *
 * abstract factory for QuadratureRule family
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#ifndef QUADRATURE_FACTORY
#define QUADRATURE_FACTORY

#include "QuadratureRule.hpp"

class QuadratureFactory {
public:
    virtual QuadratureRule* create(double (*func)(double), double a, double b) 
                        const = 0;
};

#endif // QUADRATURE_FACTORY
