/*
 * Interval.hpp
 *
 * a class for a interval of the integration grid
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#ifndef INTERVAL
#define INTERVAL

class Interval {
public:
    
    // bounds of an interval
    double xLow;
    double xHigh;

    /*
     * default constructor
     */
    Interval() : xLow(0.0), xHigh(1.0) {
    }

    /*
     * basic constructor
     */
    Interval(double xL, double xH) : xLow(xL), xHigh(xH) {
    }

    /*
     * copy constructor
     */
    Interval(const Interval& other) : xLow(other.xLow), xHigh(other.xHigh) {
    }

    /*
     * assignment operator
     */
    Interval& operator=(const Interval& other) {
        xLow = other.xLow;
        xHigh = other.xHigh;

        return *this;
    }
    
};

#endif // INTERVAL
