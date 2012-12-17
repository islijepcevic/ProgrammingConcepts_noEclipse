/*
 * MidpointRule.hpp
 *
 * a class implementing simple midpoint rule
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#ifndef MIDPOINT
#define MIDPOINT

#include "QuadratureRule.hpp"

class MidpointRule : public QuadratureRule {

public:
    MidpointRule(double (*func)(double), double a, double b) :
       QuadratureRule(func, a, b) {
   } 

    virtual void integrate();
};


#endif // MIDPOINT
