#include <iostream>
#include <vector>
#include <algorithm>

#include "exercise3/ComplexNumber.hpp"

int main() {

    std::vector<ComplexNumber> cnumbers;

    cnumbers.push_back(ComplexNumber(3., 4.));
    cnumbers.push_back(ComplexNumber(0., 4.));
    cnumbers.push_back(ComplexNumber(1., 0.));

    sort(cnumbers.begin(), cnumbers.end());

    for (std::vector<ComplexNumber>::const_iterator it = cnumbers.begin();
            it < cnumbers.end(); it++) {

        std::cout << *it << std::endl;
    }

    return 0;
}
