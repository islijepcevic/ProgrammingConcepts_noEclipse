/*
 * Point2d.hpp
 *
 * 2D Point class
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
public:
	double x, y;
	static double sTolerance;

	Point2d(double a, double b);

	bool operator<(const Point2d& other) const;
};

#endif //POINT2D_H
