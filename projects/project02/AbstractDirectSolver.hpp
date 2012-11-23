/*
 * AbstractDirectSolver.hpp
 *
 *  Created on: Nov 21, 2012
 *      Author: rpopescu
 */

#ifndef ABSTRACTDIRECTSOLVER_HPP_
#define ABSTRACTDIRECTSOLVER_HPP_

#include "AbstractMatrix.hpp"
#include "Vector.hpp"

#include <iostream>

template <typename ValueType>
class AbstractDirectSolver {
public:
	// Constructor and destructor
	AbstractDirectSolver();
	virtual ~AbstractDirectSolver() {}

	// Methods (pure virtual)
	/*
	 * Factorization method; after calling this method, the Solve method can
	 * be called.
	 * Parameters:
	 *       A: matrix to be factorized
	 */
	virtual void Factorize(AbstractMatrix<ValueType>& A) = 0;

	/*
	 * Solve method
	 *
	 * Parameters:
	 * 		x - Vector<ValueType> the solution, output parameter
	 * 		b - Vector<ValueType> the right hand side, input parameter
	 */
	virtual void Solve(Vector<ValueType>& x, const Vector<ValueType>& b) const = 0;

protected:
	bool mFactorized;
};

template<typename ValueType>
AbstractDirectSolver<ValueType>::AbstractDirectSolver()
	: mFactorized(false)
{}

#endif /* ABSTRACTDIRECTSOLVER_HPP_ */
