/*
 * LUSolver.hpp
 *
 * created on: Nov 26,, 2012
 *      Author: islijepcevic
 */

#ifndef LUSOLVER_HPP
#define LUSOLVER_HPP

#include "AbstractDirectSolver.hpp"

template<typename ValueType>
class LUSolver : public AbstractDirectSolver<ValueType> {
public:

    // constructor, destructor
    LUSolver();
    ~LUSolver();

    // methods (that need to be overridden)

    /*
     * Factorization method; after calling this method,the Solve method can be
     * called
     */
    void Factorize(AbstractMatrix<ValueType>& A);

    /*
     * Solve method
     * @param x - the solution; output parameter
     * @param b - the right hand side, input parameter
     */
    void Solve(Vector<ValueType>& x, const Vector<ValueType>& b) const;

private:
    AbstractMatrix<ValueType>* mL;
    AbstractMatrix<ValueType>* mU;
};

template<typename ValueType>
LUSolver<ValueType>::LUSolver() : mL(NULL), mU(NULL)
{
}

template<typename ValueType>
LUSolver<ValueType>::~LUSolver() {

    if (this->mFactorized) {
        delete mL;
        delete mU;
    }
}

template<typename ValueType>
void LUSolver<ValueType>::Factorize(AbstractMatrix<ValueType>& A)
{
        if (mL != NULL) {
            delete mL;
        }
        
        if (mU != NULL) {
            delete mU;
        }

        mL = mU = NULL;

	A.LUFactorization(mL, mU);
	this->mFactorized = true;

}

template<typename ValueType>
void LUSolver<ValueType>::Solve(Vector<ValueType>& x, 
                                const Vector<ValueType>& b) const
{
        assert(this->mFactorized == true);

        // forward substitution
        Vector<ValueType> y(mL->ApplyLowerInv(b));

        // backward substitution
        x = mU->ApplyLowerTranspInv(y);

}

#endif /* LUSOLVER_HPP */
