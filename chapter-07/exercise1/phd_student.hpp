#ifndef PHDSTUD
#define PHDSTUD

#include "graduate_student.hpp"

class PhdStudent : public GraduateStudent
{
public:
    PhdStudent(std::string _name);
    PhdStudent(std::string _name, bool _partTime);

    double getMoneyOwed() const;
};

#endif //PHDSTUD
