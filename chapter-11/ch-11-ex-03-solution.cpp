/*
 * ch-11-ex-03-solution.cpp
 *
 * MPI Send and Recv
 *
 *  Created on: Dec 2, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <mpi.h>

void Print(int V[][10])
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << V[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	MPI::Init(argc, argv);

	int rank = MPI::COMM_WORLD.Get_rank();

	int V[10][10];

	if (rank == 0) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				V[i][j] = 10 * i + j;
			}
		}
	} else {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				V[i][j] = 100 + 10 * i + j;
			}
		}
	}


	// MPI send with buffer - row 0
	int buffer[10];
	if (rank == 0) {
		for (int j = 0; j < 10; ++j) {
			buffer[j] = V[0][j];
		}
		MPI::COMM_WORLD.Send(buffer, 10, MPI::INT, 1, 123);
	} else {
		MPI::COMM_WORLD.Recv(buffer, 10, MPI::INT, 0, 123);
		std::cout << "Process 1 printing V before first transfer." << std::endl;
		Print(V);
		for (int j = 0; j < 10; ++j) {
			V[0][j] = buffer[j];
		}
		std::cout << "Process 1 printing V after first transfer." << std::endl;
		Print(V);
	}

	// MPI send without buffer - rows 5 and 8
	if (rank == 0) {
		MPI::COMM_WORLD.Send(&V[5][0], 10, MPI::INT, 1, 234);
		MPI::COMM_WORLD.Send(&V[8][0], 10, MPI::INT, 1, 345);
	} else {
		MPI::COMM_WORLD.Recv(&V[5][0], 10, MPI::INT, 0, 234);
		MPI::COMM_WORLD.Recv(&V[8][0], 10, MPI::INT, 0, 345);
		std::cout << "Process 1 printing V after second transfer." << std::endl;
		Print(V);
	}

	// MPI Send first column without buffer, using custom MPI datatypes
	MPI::Datatype MyVectorType = MPI::INT.Create_vector(10, 1, 10);
	MyVectorType.Commit();
	if (rank == 0) {
		MPI::COMM_WORLD.Send(&V[0][0], 1, MyVectorType, 1, 456);
	} else {
		MPI::COMM_WORLD.Recv(&V[0][0], 1, MyVectorType, 0, 456);
		std::cout << "Process 1 printing V after final transfer." << std::endl;
		Print(V);
	}

	MPI::Finalize();

	return 0;
}
