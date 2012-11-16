/*
 * Exception.hpp
 *
 *  Created on: Nov 15, 2012
 *      Author: rpopescu
 */

#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>

class Exception
{
private:
	std::string mTag, mProblem;
public:
	Exception(std::string tagString, std::string problemString);
	void PrintDebug() const;
};

#endif //EXCEPTIONDEF
