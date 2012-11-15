/*
 * FileNonOpenException.hpp
 *
 *  Created on: Nov 15, 2012
 *      Author: rpopescu
 */

#ifndef FILENOTOPENEXCEPTIONDEF
#define FILENOTOPENEXCEPTIONDEF

#include <string>
#include "Exception.hpp"

class FileNotOpenException : public Exception
{
public:
	FileNotOpenException(std::string probString);
};

#endif //FILENOTOPENEXCEPTIONDEF
