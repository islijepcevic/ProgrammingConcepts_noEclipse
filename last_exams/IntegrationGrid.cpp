/*
 * IntegrationGrid.cpp
 *
 * a class for an integration grid
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#include "IntegrationGrid.hpp"
#include <cassert>
#include <algorithm>
#include <utility>

/*
 * basic constructor - zero intervals
 */
IntegrationGrid::IntegrationGrid() {
    mCurrentInterval = mIntervals.begin();
}

/*
 * constructor that creates equally spaced nodes
 * @param numIntervals - number of nodes
 * @param xMin - lower bound of the first interval
 * @param xMax - upper bound of the last interval
 */
IntegrationGrid::IntegrationGrid(int numIntervals, double xMin, double xMax) {

    double h = (xMax - xMin) / numIntervals;

    for (int i = 0; i < numIntervals; i++) {

        Interval interval;
        interval.xLow = xMin + h * i;
        interval.xHigh = interval.xLow + h;

        mIntervals.push_back(interval);
    }

    mCurrentInterval = mIntervals.begin();
}

/*
 * copy constsructor
 */
IntegrationGrid::IntegrationGrid(const IntegrationGrid& other) :
    mIntervals(other.mIntervals), mCurrentInterval(other.mCurrentInterval) {
}

/*
 * method that makes union of two grids in the current object
 * also, the iterator over intervals will be reset
 * @param other - different integration grid that needs to be merged with this one
 * @return - pointer to changed "this" object
 */
IntegrationGrid& IntegrationGrid::makeUnion(const IntegrationGrid& other) {

    // this is axis contains points with the char '(' or ')'
    // '(' means open interval, ')' means cosed
    std::vector< std::pair<double, char> > axis;

    std::vector<Interval>::const_iterator thisIter = mIntervals.begin();
    for (; thisIter != mIntervals.end(); thisIter++) {

        axis.push_back(std::make_pair(thisIter->xLow, '('));
        axis.push_back(std::make_pair(thisIter->xHigh, ')'));
    }

    std::vector<Interval>::const_iterator otherIter = other.mIntervals.begin();
    for (; otherIter != other.mIntervals.end(); otherIter++) {
        axis.push_back(std::make_pair(otherIter->xLow, '('));
        axis.push_back(std::make_pair(otherIter->xHigh, ')'));
    }

    sort(axis.begin(), axis.end());

    std::vector<Interval> newGrid;

    int depth = 0;
    for (unsigned int i = 0; i < axis.size() - 1; i++) {

        if (axis[i].second == '(') {
            depth++;
        } else {
            depth--;
        }

        assert(depth >= 0);
        
        // check if iteration is currently between the grids
        if (depth == 0) {
            continue;
        }

        double low = axis[i].first;
        double high = axis[i+1].first;

        Interval newInterval;
        newInterval.xLow = low;
        newInterval.xHigh = high;

        newGrid.push_back(newInterval);
    }

    mIntervals = newGrid;
    mCurrentInterval = mIntervals.begin();

    return *this;
}

/*
 * method that makes union of two grids in the current object
 * @param other - different integration grid that needs to be merged with this one
 * @return - pointer to changed "this" object
 */
//IntegrationGrid& IntegrationGrid::makeUnion(const IntegrationGrid& other) {
//
//    std::vector<Interval>::const_iterator thisIter = mIntervals.begin();
//    std::vector<Interval>::const_iterator otherIter = other.mIntervals.begin();
//
//    std::vector<Interval> newGrid;
//
//    // INCOMPLETE ALGORITHM
//    
//    std::vector<double> nodes;
//    for (; thisIter != mIntervals.end(); thisIter++) {
//        nodes.push_back(thisIter->xLow);
//        nodes.push_back(thisIter->xHigh);
//    }
//    for (; otherIter != other.mIntervals.end(); otherIter++) {
//        nodes.push_back(otherIter->xLow);
//        nodes.push_back(otherIter->xHigh);
//    }
//
//    sort(nodes.begin(), nodes.end());
//
//    for (unsigned int i = 0; i < nodes.size() - 1; i++) {
//        if (nodes[i+1] - nodes[i] < 1e-6) {
//            continue;
//        }
//
//        Interval newInterval;
//        newInterval.xLow = nodes[i];
//        newInterval.xHigh = nodes[i+1];
//
//        newGrid.push_back(newInterval);
//    }
//
//    // END OF INCOMPLETE ALGORITHM
//
////
////    double thisLow;
////
////    while(thisIter != mIntervals.end() && otherIter != other.mIntervals.end()) {
////
////        if (thisLow) {
////            
////        }
////    }
////
//
//    mIntervals = newGrid;
//
//    return *this;
//}

/*
 * method that returns next interval while iterating through the grid
 * @return - reference to an interval
 */
const Interval& IntegrationGrid::nextInterval() {

    assert(hasNextInterval());

    const Interval& current = *mCurrentInterval;
    mCurrentInterval++;

    return current;
}

/*
 * method that tests if there is more intervals
 * @return - true or false
 */
bool IntegrationGrid::hasNextInterval() const {

    if (mCurrentInterval == mIntervals.end()) {
        return false;
    }

    return true;
}

/*
 * method that resets iteration to the beginning of the grid
 */
void IntegrationGrid::resetIteration() {

    mCurrentInterval = mIntervals.begin();
}

/*
 * print method
 */
void IntegrationGrid::print(FILE* stream) {

    fprintf(stream, "printing grid\n");
    for (unsigned int i = 0; i < mIntervals.size(); i++) {
        Interval& intrvl = mIntervals[i];
        fprintf(stream, "interval %d (%lf, %lf)\n", i, intrvl.xLow, intrvl.xHigh);
    }

    fprintf(stream, "\n");
}
