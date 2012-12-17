#ifndef SO_ODE
#define SO_ODE

class SecondOrderOde {
private:

    // Coefficients on LHS of ODE
    double mCoeffOfUxx;
    double mCoeffOfUx;
    double mCoeffOfU;

    // Function on RHS of ODE
    double (*mpRhsFunc) (double x);

    // Interval for domain
    double mXmin;
    double mXmax;

public:

    SecondOrderOde(double coeffUxx, double coeffUx, double coeffU,
            double (*rightHandSide) (double), double xMin, double xMax) :
        mCoeffOfUxx(coeffUxx), mCoeffOfUx(coeffUx), mCoeffOfU(coeffU),
        mpRhsFunc(rightHandSide), mXmin(xMin), mXmax(xMax) {
    }

    // GETTERS


};

#endif /* SO_ODE */
