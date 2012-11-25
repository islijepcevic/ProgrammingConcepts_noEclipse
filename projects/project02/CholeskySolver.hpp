/*
 * CholeskySolver.hpp
 *
 *  Created on: Nov 21, 2012
 *      Author: rpopescu
 */

#ifndef CHOLESKYSOLVER_HPP_
#define CHOLESKYSOLVER_HPP_

#include "AbstractDirectSolver.hpp"

template <typename ValueType>
class CholeskySolver: public AbstractDirectSolver<ValueType> {
public:
	// Constructor and destructor
	CholeskySolver();
	~CholeskySolver();

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
	AbstractMatrix<ValueType>* mR;
};

template<typename ValueType>
CholeskySolver<ValueType>::CholeskySolver()
	: mR(0)
{}

template<typename ValueType>
CholeskySolver<ValueType>::~CholeskySolver()
{
	if(this->mFactorized) {
		delete mR;
	}
}


template<typename ValueType>
void CholeskySolver<ValueType>::Factorize(AbstractMatrix<ValueType>& A)
{
	if (mR != NULL)
		delete mR;
	mR = NULL;

	A.CholeskyFactorization(mR);
	this->mFactorized = true;
}

template<typename ValueType>
void CholeskySolver<ValueType>::Solve(Vector<ValueType>& x,
									  const Vector<ValueType>& b) const
{
	Vector<ValueType> y(mR->ApplyLowerInv(b)); // forward substitution
	x = mR->ApplyLowerTranspInv(y);    // backward substituion with R transpose
}

#endif /* CHOLESKYSOLVER_HPP_ */
