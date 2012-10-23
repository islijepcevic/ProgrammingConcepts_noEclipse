#ifndef GRADSTUD
#define GRADSTUD

#include "student.hpp"

class GraduateStudent : public Student
{
public:
    GraduateStudent(std::string _name);
    GraduateStudent(std::string _name, bool _partTime);
    GraduateStudent(std::string _name, double _libraryFines);
    GraduateStudent(std::string _name, bool _partTime, double _libraryFines);

    double getMoneyOwed() const;

    bool partTime;
};

#endif //GRADSTUD
