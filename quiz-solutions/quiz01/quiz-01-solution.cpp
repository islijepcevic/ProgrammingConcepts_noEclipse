/*
 * quiz-01-solution.cpp
 *
 * Bisection method
 *
 * Created on: Oct 8, 2012
 * 	   Author: Radu Popescu <radu.popescu@epfl.ch>
 */

#include <iostream>
#include <cmath>

double f1(const double x)
{
	return std::sin(2 * x) - 1 + x;
}

double f2(const double x)
{
	return 2 * x / ( 1 + x / 1.5);
}

/*
 * This functions implements the bisection method, used to compute the root
 * of a continuous function f(x), f:[a,b] -> R, f(a) * f(b) < 0
 *
 * Parameters:
 *    Input:
 * 		p_fun    - function pointer; the function to which we apply the method
 * 		a        - the lower end-point of the interval
 * 		b        - the upper end-point of the interval
 * 		tol      - the desired accuracy of the solution
 * 		max_it   - the maximum number of iterations in the bisection method
 * 	  Output:
 * 		solution - variable which will hold the solution
 * 		n_it     - variable which will hold the number of iterations performed
 *    Return:
 *      0 for success, -1 if bisection cannot be used, -2 if max number of
 *      iterations is reached
 */
int bisection(double (*p_fun)(const double),
					const double a,
					const double b,
					const double tol,
					const int max_it,
					double& solution,
					int& n_it)
{
	double left_point = a;
	double right_point = b;
	double mid_point = (left_point + right_point) / 2;

	double f_left = p_fun(left_point);
	double f_right = p_fun(right_point);
	double f_mid = p_fun(mid_point);

	if (f_left * f_right > 0) {
		std::cout << "The function has the same sign at the end-points of the "
				  << "specified interval. The bisection method cannot be used."
				  << std::endl;
		solution = 0.0;
		n_it = 0;
		return -1;
	}

	double err = (right_point - left_point) / 2;
	int k = 0;

	while ((err > tol) && (k < max_it)) {
		// Check if mid-point is solution
		if (std::fabs(f_mid) < tol) {
			solution = mid_point;
			n_it = k;
			return 0;
		}
		// Check if left end-point is solution
		if (std::fabs(f_left) < tol) {
			solution = left_point;
			n_it = k;
			return 0;
		}
		// Check if right end-point is solution
		if (std::fabs(f_right) < tol) {
			solution = right_point;
			n_it = k;
			return 0;
		}
		if (f_mid * f_left > 0) {
			left_point = mid_point;
		} else {
			right_point = mid_point;
		}
		mid_point = (left_point + right_point) / 2;
		f_left = p_fun(left_point);
		f_right = p_fun(right_point);
		f_mid = p_fun(mid_point);
		err /= 2;
		k++;
	}

	solution = mid_point;
	n_it = k;

	if ((n_it == max_it) && (err > tol)) {
		std::cout << "Maximum number of iterations reached without "
				  << "achieving desired accuracy." << std::endl;
		return -2;
	} else {
		return 0;
	}
}

int main(int argc, char* argv[])
{
	const double tol = 1e-7;
	const int max_it = 100;

	const double a1 = -3.0, b1 = 3.0;
	double sol1;
	int n_it1;
	if (! bisection(f1, a1, b1, tol, max_it, sol1, n_it1)) {
		std::cout << "The solution to f1(x) = 0 ; -3 <= x <= 3 is: "
				  << sol1 << " after " << n_it1 << " iterations."
				  << std::endl;
	}

	const double a2 =  1.0, b2 = 2.0;
	double sol2;
	int n_it2;
	if (! bisection(f2, a2, b2, tol, max_it, sol2, n_it2)) {
		std::cout << "The solution to f2(x) = 0 ; 1 <= x <= 2 is: "
				  << sol2 << " after " << n_it2 << " iterations."
				  << std::endl;
	}

	const double a3 =  3.0, b3 = 4.0;
	double sol3;
	int n_it3;
	if (! bisection(f2, a3, b3, tol, max_it, sol3, n_it3)) {
		std::cout << "The solution to f2(x) = 0 ; 3 <= x <= 4 is: "
				  << sol3 << " after " << n_it3 << " iterations."
				  << std::endl;
	}

    return 0;
}

