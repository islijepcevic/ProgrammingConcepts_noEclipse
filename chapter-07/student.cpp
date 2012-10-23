#include "student.hpp"
#include <cassert>

Student::Student(std::string _name) :
    Student(_name, 0.0, 0.0)
{
}

Student::Student(std::string _name, double _libraryFines, double _tuitionFee) :
    name(_name),
    libraryFines(_libraryFines),
    tuitionFee(_tuitionFee)
{
}

double Student::getLibraryFines() const
{
    return libraryFines;
}

void Student::setLibraryFines(double newLibraryFine)
{
    assert(newLibraryFine >= 0);
    libraryFines = newLibraryFine;
}

double Student::getMoneyOwed() const
{
    return tuitionFee + libraryFines;
}
