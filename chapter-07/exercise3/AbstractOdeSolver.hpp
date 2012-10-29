#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
private:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;

    double (*rhs)(double, double);

public:
    double getStepSize() const;
    double getInitialTime() const;
    double getFinalTime() const;
    double getInitialValue() const;

    void setStepSize(double h);
    void setTimeInterval(double t0, double t1);
    void setInitialValue(double y0);
    void setRightHandSide(double (*fun)(double, double));
    virtual double rightHandSide(double y, double t) const;
    virtual double solveEquation() = 0;
};


#endif /* ABSTRACTODESOLVERDEF */
