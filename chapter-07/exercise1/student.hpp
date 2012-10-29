#ifndef STUDENT
#define STUDENT

#include <string>

class Student
{
protected:
    double libraryFines;

public:
    Student(std::string _name);
    Student(std::string _name, double _libraryFines, double _tuitionFee);
 
    std::string name;
    double tuitionFee;

    double getLibraryFines() const;
    void setLibraryFines(double newLibraryFine);
    virtual double getMoneyOwed() const;

};

#endif //STUDENT
