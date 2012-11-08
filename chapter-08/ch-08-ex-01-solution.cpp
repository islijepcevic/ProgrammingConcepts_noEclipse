/*
 * chapter-08-exercise-01.cpp
 *
 * Chance of rain
 *
 * Created on: Nov 1, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cassert>
#include <iostream>

template<unsigned int DIM>
class DoubleVector
{
public:
	/*
	 *  We use operator[] for assigning to the vector, also implementing
	 *  bounds checking
	 */
	double& operator[](const int index)
	{
		assert(index < DIM);
		assert(index > -1);
		return mData[index];
	}

	/*
	 * We use operator() for accessing elements of the vector
	 */
	double operator()(const int index) const
	{
		assert(index < DIM);
		assert(index > -1);
		if (mData[index] >= 0.0 && mData[index] <= 1.0) {
			return mData[index];
		} else if (mData[index] < 0.0 && mData[index] > -1e-6) {
			return 0.0;
		} else if (mData[index] >= 1.0 && mData[index] <= (1.0 + 1e-6)) {
			return 1.0;
		} else {
			assert(0);
			std::cerr << "Value out of range.\n";
			return -2.0;
		}
	}

private:
	double mData[DIM];
};

int main(int argc, char* argv[])
{
	// The number of days is a constant
	const unsigned int N = 5;
	DoubleVector<N> prob;

	prob[0] = 0.1;
	prob[1] = 1.0 + 5e-7;
	prob[2] = 0 - 1.1e-6;
	prob[3] = 1.0;
	prob[4] = 0 - 1e-8;

	std::cout.precision(10);
	for (unsigned int i = 0; i < N; ++i) {
		std::cout << prob(i) << "\n";
	}
	std::cout << std::endl;

    return 0;
}
