/*
 * chapter-08-exercise-04.cpp
 *
 * STL and 2D Point class
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <set>

#include "Point2d.hpp"

int main(int argc, char* argv[])
{
	std::set<Point2d> points;

	// Set the tolerance for the comparison operator of Point2d
	Point2d::sTolerance = 1e-6;

	Point2d origin(0.0, 0.0);

	points.insert(origin);
	points.insert(Point2d(-2.0, 1.0));
	points.insert(Point2d(-2.0, -5.0));
	points.insert(Point2d(0.0, 0.0));

	std::cout << "Number of points in set = " << points.size() << "\n";

	std::set<Point2d>::const_iterator c;
	std::cout.precision(3);
	for (c=points.begin(); c!=points.end(); c++) {
		std::cout << c->x << " " << c->y << "\n";
	}

	return 0;
}
