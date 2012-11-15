/*
 * Exception.cpp
 *
 *  Created on: Nov 15, 2012
 *      Author: rpopescu
 */

#include <iostream>
#include "Exception.hpp"

//Constructor
Exception::Exception(std::string tagString, std::string probString)
	: mTag(tagString),
	  mProblem(probString)
{}

void Exception::PrintDebug() const
{
	std::cerr << "** Error (" << mTag<< ") **\n";
	std::cerr << "Problem: " << mProblem << "\n\n";
}
