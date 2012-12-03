/*
 * chapter-09-exercise-01.cpp
 *
 * Exceptions
 *
 * Created on: Nov 15, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>

#include "Vector.hpp"

int main(int argc, char* argv[])
{

	MPI::Init();

	// Allocating a smaller vector than required
    Vector x(30);
    Vector y(30);

    if (MPI::COMM_WORLD.Get_rank() == 0)
    {
    	x[0] = 5;
    	y[0] = -2;
    }

    double scalarProd(x.dot(y));


    if (MPI::COMM_WORLD.Get_rank() == 0)
    {
    	std::cout << "dot(x,y) = "
    		<< scalarProd << std::endl;
    }

    MPI::Finalize();

	return 0;
}
