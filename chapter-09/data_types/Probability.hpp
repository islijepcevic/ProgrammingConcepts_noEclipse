#ifndef PROB
#define PROB

#include "ProbabilityException.hpp"

class Probability {
private:
    double p;

    void check() throw(ProbabilityException);

public:
    Probability();
    Probability(double _p);

    //operators
    Probability& operator=(const Probability& prob);
    //Probability operator+() const;
    //Probability operator-() const;
    //Probability operator+(const Probability& prob) const;
    //Probability operator-(const Probability& prob) const;
    //Probability operator*(const Probability& prob) const;
    //Probability operator/(const Probability& prob) const;
    
    //cast (double)
    operator double () const;
    
    //ostream
};

#endif /* PROB */
