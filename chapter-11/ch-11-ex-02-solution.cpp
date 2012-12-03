/*
 * chapter-11-exercise-02.cpp
 *
 * MPI Send
 *
 * Created on: Nov 30, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[])
{
	MPI::Init(argc, argv);

	int num_procs = MPI::COMM_WORLD.Get_size();
	int rank = MPI::COMM_WORLD.Get_rank();

	if (rank == 0) {
		double message[1000000];
		int size = 1;
		while (true) {
			std::cout << "Sending a message of size: " << size << std::endl;
			MPI::COMM_WORLD.Send(&message, size, MPI::DOUBLE,
								 num_procs - 1, 100);
			size *= 2;
		}
	}

	MPI::Finalize();

	return 0;
}
