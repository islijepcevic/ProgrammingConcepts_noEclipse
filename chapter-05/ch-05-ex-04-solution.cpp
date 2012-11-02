/*
 * chapter-05-exercise-04.cpp
 *
 * Standard deviation of array
 * Input the array as extra command line arguments:
 * ./ch-05-ex-04-solution 5.0 4.8 5.3 2.9
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <cstdlib>
#include <cmath>
#include <iostream>

void mean_and_std(const double* const v, const double size,
				  double& mean, double& stdev)
{
	mean = 0.0;
	for (int i = 0; i < size; ++i) {
		mean += v[i];
	}
	mean /= size;
	double s1 = 0.0;
	for (int i = 0; i < size; ++i) {
		s1 += std::pow(v[i] - mean, 2);
	}
	stdev = std::sqrt(s1 / (size - 1));
}

/*
 * This function computes the mean and standard deviation of a series
 * of floating point numbers using a recurrence relation.
 * This is useful for continuous processes and is resistant to round-off
 * error.
 *
 * Attributed to B.P. Welford, Technometrics, 4,(1962), 419-420.
 */
void mean_and_std_rec(const double* const v, const double size,
				  	  double& mean, double& stdev)
{
	double mean_prev = v[0];
	double stdev_accum = 0.0;
	double mean_next = 0.0;

	for (int i = 1; i < size; ++i) {
		mean_next = mean_prev + (v[i] - mean_prev) / (i + 1);
		stdev_accum += (v[i] - mean_prev) * (v[i] - mean_next);
		mean_prev = mean_next;
	}

	mean = mean_next;
	stdev = std::sqrt(stdev_accum / (size - 1));
}

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cout << "Please input a series of floating point numbers:\n"
				  << "   ./ch-05-ex-04-solution 5.0 4.8 5.3 2.9"
				  << std::endl;
		return -1;
	}

	const int n = argc - 1;
	double* const v = new double[n];
	for (int i = 0; i < n; ++i) {
		v[i] = std::atof(argv[i + 1]);
	}

	double mean;
	double std_deviation;

	mean_and_std(v, n, mean, std_deviation);

	std::cout << "The mean and standard deviation are: "
			  << mean << " and " << std_deviation << std::endl;

	mean_and_std_rec(v, n, mean, std_deviation);

	std::cout << "The mean and standard deviation are: "
			  << mean << " and " << std_deviation << std::endl;

	delete[] v;

	return 0;
}

