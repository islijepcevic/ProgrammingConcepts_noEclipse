/*
 * project-01-solution.cpp
 *
 * Wallclock timer class
 *
 * Created on: Oct 31, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#ifndef WALLCLOCK_H
#define WALLCLOCK_H 1

#include <sys/time.h>

class WallClock
{
public:
    // @name Public typedefs
    typedef struct timeval time_Type;

    // @name Constructor and destructor
    WallClock();
    ~WallClock() {};

    // @name Public methods
    void start();
    void stop();
    void reset();

    const double& elapsedTime() const {return M_elapsedTime;}

private:
    // Disabled copy constructor and assignment operator
    WallClock(const WallClock&);
    WallClock& operator=(const WallClock&);

    time_Type M_startTime;
    time_Type M_stopTime;

    double M_elapsedTime;
};

#endif // WALLCLOCK_H
