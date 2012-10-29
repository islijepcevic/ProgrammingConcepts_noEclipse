#include <iostream>
#include "exercise1/phd_student.hpp"

int main()
{

    PhdStudent studentosh("Mujo", false);

    std::cout << studentosh.getMoneyOwed() << std::endl;

    return 0;
}
