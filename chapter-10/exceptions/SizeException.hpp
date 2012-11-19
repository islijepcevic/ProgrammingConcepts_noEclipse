#ifndef VECTORSIZEEXC
#define VECTORSIZEEXC

#include <exception>
#include <string>

class VectorSizeException : public std::exception {
private:
    std::string message;

public:
    VectorSizeException(std::string msg) : message(msg){}
    ~VectorSizeException() throw() {}

    virtual const char* what() const throw() {
        return message.c_str();
    }
};

#endif // OUTOFBOUNDSEXC

