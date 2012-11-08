/*
 * Point2d.hpp
 *
 * 2D Point class
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include "Point2d.hpp"

double Point2d::sTolerance = 1e-9;

Point2d::Point2d(double a, double b)
	: x(a),
	  y(b)
{}

bool Point2d::operator<(const Point2d& other) const
{
	if ((x - other.x) < - sTolerance) {
		return true;
	} else if ((x - other.x) > sTolerance) {
		return false;
	} else if ((y - other.y) < -sTolerance) {
		// x == other.x
		return true;
	} else {
		// x == other.x and
		// y >= other.y
		return false;
	}
}
