/*
 * project-01-solution.cpp
 *
 * Wallclock timer class
 *
 * Created on: Oct 31, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include "WallClock.hpp"

#include <cstdlib>

// ==========================
// Constructor and destructor
// ==========================
WallClock::WallClock()
{
    reset();
}

// ==========================
// Public methods
// ==========================

void WallClock::start() {
    gettimeofday(&M_startTime, NULL);
}

void WallClock::stop() {
    gettimeofday(&M_stopTime, NULL);

    double seconds = static_cast<double>(M_stopTime.tv_sec
    									 - M_startTime.tv_sec);
    double microseconds = static_cast<double>(M_stopTime.tv_usec
    									      - M_startTime.tv_usec);

    M_elapsedTime += (seconds + microseconds / 1000000.0);
}

void WallClock::reset() {
    M_elapsedTime = 0.0;
}
