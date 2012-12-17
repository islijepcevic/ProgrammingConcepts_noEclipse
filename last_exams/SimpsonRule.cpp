/*
 * SimpsonsRule.cpp
 *
 * a class implementing simple simpson rule
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#include "SimpsonRule.hpp"

/*
 * method that performs integration
 */
void SimpsonRule::integrate() {

    mResult = mFunction(ma) + mFunction(mb);
    mResult += 4 * mFunction((ma + mb) / 2.0);

    mResult *= (mb - ma);
    mResult /= 6.0;
}

