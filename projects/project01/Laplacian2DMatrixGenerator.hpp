/*
 * Laplacian2DMatrixGenerator.hpp
 *
 * Function that generates the finite difference matrix for a 2D Laplacian
 * problem on a regular square grid, with a 5 point FD stencil
 *
 *  Created on: Nov 1, 2012
 *      Author: rpopescu
 */

#ifndef LAPLACIAN2DMATRIXGENERATOR_HPP_
#define LAPLACIAN2DMATRIXGENERATOR_HPP_

#include <string>

class AbstractMatrix;

/*
 * Function that generates the finite difference matrix for a 2D Laplacian
 * problem on a regular square grid, with a 5 point FD stencil
 *
 * Parameters:
 * 		M - AbstractMatrix pointer; does not need to be initialized before
 * 		    calling the function
 * 		npoints - number of points along one side of the square grid
 * 		storageType - can be "dense" or "sparse" (do not select sparse until
 * 			you've implemented the CsrMatrix class)
 */
void Laplacian2DMatrixGenerator(AbstractMatrix*& M,
								const unsigned long npoints,
								const std::string& storageType);

#endif /* LAPLACIAN2DMATRIXGENERATOR_HPP_ */
