/*
 * chapter-07-exercise-03.cpp
 *
 * ODE solver
 *
 * Created on: Oct 25, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"

double fRhs(double y, double t)
{
	return 1 + t;
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::cout << "Missing paremeter. Please run as:\n"
				  << "  ./ch-07-ex-03-solution <stepsize_euler> <stepsize_rk>\n"
				  << "Aborting.\n";
		return 1;
	}

	double initialTime = 0.0;
	double finalTime = 1.0;
	double initialValue = 2.0;

	AbstractOdeSolver* pSolver = 0;

	// Solving with forward-Euler
	double stepSizeEuler = std::atof(argv[1]);
	pSolver = new ForwardEulerSolver;
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetStepSize(stepSizeEuler);
	pSolver->SetRightHandSide(fRhs);

	std::ofstream eulerSolutionFile("solution_euler.dat");
	if (eulerSolutionFile.is_open()) {
		pSolver->SolveEquation(eulerSolutionFile);
		eulerSolutionFile.close();
	} else {
		std::cout << "Couldn't open solution_euler.dat. Aborting."
				  << std::endl;
		return 1;
	}

	double stepSizeRK = std::atof(argv[2]);
	pSolver = new RungeKuttaSolver;
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetStepSize(stepSizeRK);
	pSolver->SetRightHandSide(fRhs);

	std::ofstream RKSolutionFile("solution_rk.dat");
	if (RKSolutionFile.is_open()) {
		pSolver->SolveEquation(RKSolutionFile);
		RKSolutionFile.close();
	} else {
		std::cout << "Couldn't open solution_rk.dat. Aborting."
				  << std::endl;
		return 1;
	}

    return 0;
}
