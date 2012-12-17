/*
 * SimpsonRule.hpp
 *
 * a class implementing simple simpson rule
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#ifndef SIMPSON
#define SIMPSON

#include "QuadratureRule.hpp"

class SimpsonRule : public QuadratureRule {

public:
    SimpsonRule(double (*func)(double), double a, double b) :
       QuadratureRule(func, a, b) {
   } 

    virtual void integrate();
};


#endif // SIMPSON

