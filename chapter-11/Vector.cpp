/*
 * Vector.cpp
 *
 * Dense vector class for the Conjugate gradient solver.
 * Templated on the type of the values
 *
 *  Created on: Oct 31, 2012
 *      Author: Simone
 */

#include "Vector.hpp"

// IMPLEMENTATION

Vector::Vector(const int size)
	: mGlobalSize(size),
	  mLocalSize(0),
	  mVector(0)
{
	int N ( MPI::COMM_WORLD.Get_size());
	int k ( MPI::COMM_WORLD.Get_rank());

	mLocalSize = size/N + (k < size % N);

	mVector.resize(mLocalSize,0.0);

}

Vector::Vector(const Vector& v)
	:  mGlobalSize(v.mGlobalSize),
	   mLocalSize(v.mLocalSize),
       mVector(v.mVector)
{}

// Operators

Vector& Vector::operator=(const Vector& v)
{
	 mGlobalSize = v.mGlobalSize;
	 mLocalSize =v.mLocalSize;
	 mVector = v.mVector;

	 return *this;
}

Vector Vector::operator+(const Vector& v) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] += v.mVector[i];
	}

	return tempV;
}

Vector Vector::operator-(const Vector& v) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] -= v.mVector[i];
	}

	return tempV;
}


Vector Vector::operator=(const ValueType d) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] = d;
	}

	return tempV;
}



Vector Vector::operator*(const ValueType d) const
{
	Vector tempV (*this);
	for (unsigned int i = 0; i < mLocalSize; ++i) {
		tempV.mVector[i] *= d;
	}

	return tempV;
}

int Vector::computeOwningProcessorAndIndex(int const index, int& owningProc, int& localIndex) const
{
	int A (mGlobalSize % MPI::COMM_WORLD.Get_size());
	int sizeOverN(mGlobalSize / MPI::COMM_WORLD.Get_size());

	if (index < A * (sizeOverN +1))
	{
		owningProc = index / (sizeOverN+1);
		localIndex = index - owningProc * (sizeOverN+1);
	}
	else
	{
		owningProc = A + ( index - A *(sizeOverN +1) ) / sizeOverN;
		localIndex = index - A - A*sizeOverN;
	}

	return 0;

}

// Const version of bracket operator. Uses the global numbering
const double Vector::GetEntry(const int index) const
{
	/* here we have to decide wether every process calls this function
	 * together with the same entry, or if everyone call this independenlty on
	 * local entries only.
	 *
	 * We decide that every processor calls this method
	*/
	int localIndex;
	int owningProc;

	computeOwningProcessorAndIndex(index, owningProc, localIndex);

	double result;

	if (MPI::COMM_WORLD.Get_rank() == owningProc)
	{
		result = mVector[ localIndex ];
	}

	MPI::COMM_WORLD.Bcast(&result, 1 , MPI::DOUBLE, owningProc );

	return result;
}

// Non-const version of bracked operator
ValueType& Vector::operator[](const int index)
{
	/* here, if the entry in not local, we can not give back a reference!
	*/
	int localIndex;
	int owningProc;

	computeOwningProcessorAndIndex(index, owningProc, localIndex);

	// Execution stops if index is not local
	assert (MPI::COMM_WORLD.Get_rank() == owningProc);

	return mVector[localIndex];
}

ValueType Vector::dot(const Vector& v) const
{
	/* This has to be called by each process */

	ValueType partialSum = 0.0;
	for (unsigned int i = 0; i < mLocalSize; ++i)
	{
		partialSum += mVector[i] * v.mVector[i];
	}

	ValueType globalSum;

	// will need to use
	MPI::COMM_WORLD.Allreduce(&partialSum, &globalSum, 1, MPI::DOUBLE, MPI::SUM);

	return globalSum;
}

ValueType Vector::norm() const
{
	return std::sqrt(dot(*this));
}


void Vector::Print(std::ostream& s)
{
	for (unsigned long i = 0; i < mLocalSize; ++i) {
		s << mVector[i] << "\n";
	}
}

