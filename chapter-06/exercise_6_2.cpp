#include <iostream>
#include "Matrix22.hpp"

int main() {

    Matrix22 A(1, 0, 0, 2);

    Matrix22 B(0, 1, 0, 0);

    Matrix22 C(-B);

    Matrix22 D = A + B;

    Matrix22 E = A.getInverse();

    Matrix22 F = B * 3.0;

    std::cout << "A:\n" << A << std::endl;
    std::cout << "B:\n" << B << std::endl;
    std::cout << "C:\n" << C << std::endl;
    std::cout << "D:\n" << D << std::endl;
    std::cout << "E:\n" << E << std::endl;
    std::cout << "F:\n" << F << std::endl;

    return 0;
}
