#ifndef OUTOFBOUNDSEXC
#define OUTOFBOUNDSEXC

#include <exception>
#include <string>

class OutOfBoundsException : public std::exception {
private:
    std::string message;

public:
    OutOfBoundsException(std::string msg) : message(msg){}
    ~OutOfBoundsException() throw() {}

    virtual const char* what() const throw() {
        return message.c_str();
    }
};

#endif // OUTOFBOUNDSEXC
