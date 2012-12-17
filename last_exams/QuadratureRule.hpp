/*
 * QuadratureRule.hpp
 *
 * abstract class for numerical quadratures
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#ifndef QUADRATURE_ABSTRACT
#define QUADRATURE_ABSTRACT

class QuadratureRule {
protected:

    // function
    double (*mFunction)(double);

    // intervals
    double ma;
    double mb;

    double mResult;

public:

    QuadratureRule(double (*func)(double), double a, double b) :
        mFunction(func), ma(a), mb(b), mResult(0.0) {
    }

    virtual void integrate() = 0;

    virtual double getResult() {
        return mResult;
    }
};

#endif /* QUADRATURE_ABSTRACT */
