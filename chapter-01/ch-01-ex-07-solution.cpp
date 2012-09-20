/*
 * exercise-07.cpp
 *
 * Compile errors and warnings
 *
 *  Created on: Jul 27, 2012
 *      Author: Radu Popescu <radu.popescu@epfl.ch>
 */

int main(int argc, char* argv[])
{
	/* Trying to modify and constant variable; uncomment the following lines
	 * and recompile to see the error
	 */
	//const int var1 = 0;
	//var1 = 2;

	// Assigning a floating point value to an integer
	int var2;
	var2 = 3.2;

	return 0;
}


