#include "phd_student.hpp"

PhdStudent::PhdStudent(std::string _name) :
    PhdStudent(_name, false)
{
}

PhdStudent::PhdStudent(std::string _name, bool _partTime) :
    GraduateStudent(_name, _partTime, 0.0)
{
}

double PhdStudent::getMoneyOwed() const
{
    return 0.0;
}

