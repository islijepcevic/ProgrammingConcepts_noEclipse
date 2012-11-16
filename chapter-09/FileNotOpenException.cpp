/*
 * FileNotOpenException.cpp
 *
 *  Created on: Nov 15, 2012
 *      Author: rpopescu
 */

#include <iostream>
#include "FileNotOpenException.hpp"

//Constructor
FileNotOpenException::FileNotOpenException(std::string probString)
	: Exception("FILE_NOT_OPEN", probString)
{}
