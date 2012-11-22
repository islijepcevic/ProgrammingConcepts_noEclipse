/*
 * LUSolver.hpp
 *
 *  Created on: Nov 21, 2012
 *      Author: rpopescu
 */

#ifndef LUSOLVER_HPP_
#define LUSOLVER_HPP_

#include "AbstractDirectSolver.hpp"

template <typename ValueType>
class LUSolver: public AbstractDirectSolver<ValueType> {
public:
	// Constructor and destructor
	LUSolver();
	virtual ~LUSolver();

	// Methods (virtual)
	/*
	 * Factorization method; after calling this method, the Solve method can
	 * be called.
	 */
	void Factorize(AbstractMatrix<ValueType>& A);

	/*
	 * Solve method
	 *
	 * Parameters:
	 * 		x - Vector<ValueType> the solution, output parameter
	 * 		b - Vector<ValueType> the right hand side, input parameter
	 */
	void Solve(Vector<ValueType>& x, const Vector<ValueType>& b) const;

private:
	// Private data
	AbstractMatrix<ValueType> *mL, *mU;
};

template<typename ValueType>
LUSolver<ValueType>::LUSolver()
	: mL(0),
	  mU(0)
{}

template<typename ValueType>
LUSolver<ValueType>::~LUSolver()
{
	if(this->mFactorized) {
		delete mL;
		delete mU;
	}
}


template<typename ValueType>
void LUSolver<ValueType>::Factorize(AbstractMatrix<ValueType>& A)
{
	A.LUFactorization(mL, mU);
	this->mFactorized = true;
}

template<typename ValueType>
void LUSolver<ValueType>::Solve(Vector<ValueType>& x,
								const Vector<ValueType>& b) const
{
	Vector<ValueType> y(mL->ApplyLowerInv(b));
	x = mU->ApplyUpperInv(y);
}

#endif /* LUSOLVER_HPP_ */
