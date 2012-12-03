/*
 * chapter-11-exercise-01.cpp
 *
 * MPI Hello world
 *
 * Created on: Nov 30, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <fstream>
#include <mpi.h>

int main(int argc, char* argv[])
{
	MPI::Init(argc, argv);

	double t = MPI::Wtime();

	int num_procs = MPI::COMM_WORLD.Get_size();
	int rank = MPI::COMM_WORLD.Get_rank();

	for (int i = 0; i < num_procs; ++i) {
		if (i == rank) {
			std::ofstream output_file;
			if (rank == 0) {
				output_file.open("output.txt", std::ios_base::out);
			} else {
				output_file.open("output.txt", std::ios_base::app);
			}
			output_file << "Hello world from process " << rank
						<< " of " << num_procs << std::endl;
			output_file.close();
		}
		MPI::COMM_WORLD.Barrier();
	}

	t = MPI::Wtime() - t;

	double avg_time = 0.0;
	MPI::COMM_WORLD.Reduce(&t, &avg_time, 1, MPI::DOUBLE, MPI::SUM, 0);

	if (rank == 0) {
		std::cout << "Average run-time is: " << avg_time / num_procs << "s"
				  << std::endl;
	}

	MPI::Finalize();

	return 0;
}
