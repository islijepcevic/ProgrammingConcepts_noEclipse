#include <iostream>

#include "linear_algebra/Vector.hpp"

int main() {

    Vector v(5);

    Vector w(-v);

    std::cout << length(v) << std::endl;

    return 0;
}
