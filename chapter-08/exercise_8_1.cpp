#include <iostream>
#include <cassert>

template<unsigned int N>
class RainProbability
{
private:
    double probabilityOfDay[N];

public:

    double& operator[](int index)
    {
        assert(index >= 0);
        assert(index < N);

        double& element = probabilityOfDay[index];

        if (element < 0.)
        {
            element = 0.;
        }
        else if (element > 1.)
        {
            element = 1.;
        }

        return element;
    }
};


int main() {

    RainProbability<5> rainLausanne;

    rainLausanne[0] = 1.0000000000004;
    rainLausanne[1] = 0.004;
    rainLausanne[2] = 0.333;
    rainLausanne[3] = 0.4;
    rainLausanne[4] = 0.7;

    for (int i = 0; i < 5; i++) {
        std::cout << rainLausanne[i] << std::endl;
    }

    return 0;
}
