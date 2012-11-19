#include "vector_functions.hpp"

/*
 * MATLAB style friend to get the size of a vector
 */
int length(const Vector& v) {

    return v.getSize();
}

/*
 * output operator for Vector class
 */
void operator<<(std::ostream& output, const Vector& v) {
    
    for (int i = 0; i < v.getSize(); i++) {
        output << v[i] << " ";
    }

    output << std::endl;
}
