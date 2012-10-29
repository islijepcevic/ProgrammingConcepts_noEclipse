#include <iostream>

template<typename T>
T abs(T num)
{
    if ( num < (T)0 )
    {
        num = -num;
    }

    return num;
}

int main() {

    int a = -3, b = 4;
    double c = 8.9, d = -1e-4;

    std::cout << abs(a) << " " << abs(b) << " "
        << abs(c) << " " << abs(d) << std::endl;

    return 0;
}
