#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
private:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;

public:
    void setStepSize(double h);
    void setTimeInterval(double t0, double t1);
    void setInitialValue(double y0);
    virtual double rightHandSide(double y, double t) = 0;
    virtual double solveEquation() = 0;
};


#endif /* ABSTRACTODESOLVERDEF */
