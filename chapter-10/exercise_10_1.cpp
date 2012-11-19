#include <iostream>

#include "linear_algebra/Vector.hpp"
#include "linear_algebra/vector_functions.hpp"

int main() {

    Vector v(5);

    Vector w(-v);

    std::cout << length(v) << std::endl;


    Vector a(2);

    a[0] = 4;
    a[1] = 5;

    const Vector b(a);

    std::cout << b[0] << " " << b[2] << std::endl;
    std::cout << b;


    return 0;
}
