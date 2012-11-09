#include "Probability.hpp"

#include <cmath>

Probability::Probability() : Probability(0.0) {
}

Probability::Probability(double _p) : p(_p) {

    check();
}

void Probability::check() throw(ProbabilityException) {

    if (p < 0.0) {
        if (p > -1e-6) {
            p = 0.0;
        } else {
            throw ProbabilityException("probability out of bounds");
        }
    } else if (p > 1.0) {
        if (p < 1.0 + 1e-6) {
            p = 1.0;
        } else  {
            throw ProbabilityException("probability out of bounds");
        }
    }
}

Probability& Probability::operator=(const Probability& prob) {

    p = prob.p;

    return *this;
}

//Probability Probability::operator+() const {
//
//    return Probability(p);
//}
//
//Probability Probability::operator-() const {
//
//    return Probability(-p);
//}
//
//Probability Probability::operator+(const Probability& prob) const {
//
//    return Probability(p + prob.p);
//}
//
//Probability Probability::operator-(const Probability& prob) const {
//
//    return Probability(p - prob.p);
//}
//
//Probability Probability::operator*(const Probability& prob) const {
//
//    return Probability(p * prob.p);
//}
//
//Probability Probability::operator/(const Probability& prob) const {
//    
//    return Probability(p / prob.p);
//}

Probability::operator double() const {

    return p;
}
