#include "graduate_student.hpp"

GraduateStudent::GraduateStudent(std::string _name) :
    GraduateStudent(_name, false, 0.0)
{
}

GraduateStudent::GraduateStudent(std::string _name, bool _partTime) :
    GraduateStudent(_name, _partTime, 0.0)
{
}

GraduateStudent::GraduateStudent(std::string _name, double _libraryFines) :
    GraduateStudent(_name, false, _libraryFines)
{
}

GraduateStudent::GraduateStudent(std::string _name, bool _partTime,
                                double _libraryFines) :
    Student(_name, _libraryFines, 0.0), partTime(_partTime)
{
}

double GraduateStudent::getMoneyOwed() const
{
    return libraryFines;
}
