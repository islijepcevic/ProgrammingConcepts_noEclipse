#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

template<class T>
class AbstractOdeSolver
{
private:
    double stepSize;
    double initialTime;
    double finalTime;
    T initialValue;

    double (*rhs)(T, double);

public:
    virtual ~AbstractOdeSolver() {}

    double getStepSize() const {
        return stepSize;
    }

    double getInitialTime() const {
        return initialTime;
    }

    double getFinalTime() const {
        return finalTime;
    }

    T getInitialValue() const {
        return initialValue;
    }

    void setStepSize(double h) {
        stepSize = h;
    }

    void setTimeInterval(double t0, double t1) {
        initialTime = t0;
        finalTime = t1;
    }

    void setInitialValue(T y0) {
        initialValue = y0;
    }

    void setRightHandSide(double (*fun)(T, double)) {
        rhs = fun;
    }

    double rightHandSide(T y, double t) const {
        return rhs(y, t);
    }

    virtual void solveEquation() = 0;
};


#endif /* ABSTRACTODESOLVERDEF */
