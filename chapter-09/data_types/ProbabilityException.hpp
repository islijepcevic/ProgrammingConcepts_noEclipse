#ifndef PROBEXC
#define PROBEXC

#include <exception>
#include <string>

class ProbabilityException : public std::exception {
private:
    std::string message;
public:
    ProbabilityException(std::string msg) : message(msg) {}
    ~ProbabilityException() throw() {}

    virtual const char* what() const throw() {

        return message.c_str();
    }
};

#endif /* PROBEXC */
