/*
 * AbstractOdeSolver.hpp
 *
 *  Created on: Oct 25, 2012
 *      Author: rpopescu
 */

#ifndef ABSTRACTODESOLVER_HPP_
#define ABSTRACTODESOLVER_HPP_

#include<ostream>

class AbstractOdeSolver {
public:
	// Constructor and destructor
	AbstractOdeSolver();
	virtual ~AbstractOdeSolver();

	// Other public methods
	void SetStepSize(const double h);
	void SetTimeInterval(const double t0, const double t1);
	void SetInitialValue(const double y0);
	void SetRightHandSide(double (*f)(double y, double t));

	double RightHandSide(double y, double t) const;
	virtual void SolveEquation(std::ostream& stream) = 0;

	// Get methods
	double GetFinalTime() const {
		return finalTime;
	}

	double GetInitialTime() const {
		return initialTime;
	}

	double GetInitialValue() const {
		return initialValue;
	}

	double GetStepSize() const {
		return stepSize;
	}

private:
	double stepSize;
	double initialTime;
	double finalTime;
	double initialValue;
	double (*f_rhs)(double y, double t);
};

#endif /* ABSTRACTODESOLVER_HPP_ */
