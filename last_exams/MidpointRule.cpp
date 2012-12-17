/*
 * MidpointRule.cpp
 *
 * a class implementing simple midpoint rule
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

#include "MidpointRule.hpp"

/*
 * method that performs integration
 */
void MidpointRule::integrate() {

    mResult = (mb - ma) * mFunction((ma + mb) / 2.0);
}

