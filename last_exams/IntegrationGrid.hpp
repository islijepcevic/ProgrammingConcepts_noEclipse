/*
 * IntegrationGrid.hpp
 *
 * a class for an integration grid
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#ifndef INTGRID
#define INTGRID

#include "Interval.hpp"
#include <vector>
#include <cstdio>

class IntegrationGrid {
private:
    // the grid
    std::vector<Interval> mIntervals;

    // "pointer" to current interval for iterating
    std::vector<Interval>::const_iterator mCurrentInterval;
public:

    /*
     * basic constructor - zero intervals
     */
    IntegrationGrid();
    
    /*
     * constructor that creates equally spaced nodes
     * @param numIntervals - number of nodes
     * @param xMin - lower bound of the first interval
     * @param xMax - upper bound of the last interval
     */
    IntegrationGrid(int numIntervals, double xMin, double xMax);
    
    /*
     * copy constsructor
     */
    IntegrationGrid(const IntegrationGrid& other);

    /*
     * method that makes union of two grids in the current object
     * also, the iterator over intervals will be reset
     * @param other - different integration grid that needs to be merged with this one
     * @return - pointer to changed "this" object
     */
    IntegrationGrid& makeUnion(const IntegrationGrid& other);

    /*
     * method that returns next interval while iterating through the grid
     * @return - reference to an interval
     */
    const Interval& nextInterval();

    /*
     * method that tests if there is more intervals
     * @return - true or false
     */
    bool hasNextInterval() const;

    /*
     * method that resets iteration to the beginning of the grid
     */
    void resetIteration();

    /*
     * print method
     */
    void print(FILE* stream = stdout);
};

#endif // INTGRID
