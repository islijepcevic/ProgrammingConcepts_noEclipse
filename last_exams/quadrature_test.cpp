/*
 * quadrature_test.cpp
 *
 * main function including tests for numerical integration
 *
 * Created on: Dec 4, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "QuadratureRule.hpp"
#include "MidpointRule.hpp"
#include "SimpsonRule.hpp"

// typedef for functions
// this was introduced later during the coding
// so it is probably not refactored everywhere
typedef double (*fptr)(double);

/*
 * function that prints usage of the program
 */
void printHelp(char* argv[]) {

    printf("----usage----\n");
    printf("%s <quadrature_type> <function_index> [<a> <b>]\n\n", argv[0]);
    printf("quadrature_types:\n\t'm' - midpoint\n\t's' - simpson\n");
    printf("function_index:\n\t1\t2\t3\n");
    printf("a:\n\tleft side of interval\n");
    printf("b:\n\tright side of interval\n");
}

// MATH FUNCTIONS

double function1(double x) {
    return 1;
}

double function2(double x) {
    return 1 + 2*x;
}

double function3(double x) {
    return 1 + (4 * x * x);
}

/*
 * function that returns wanted math-function, based on given index
 */
fptr chooseFunc(int index) {

    fptr func = NULL;
    switch(index) {
        case 1:
            func = function1;
            break;
        case 2:
            func = function2;
            break;
        case 3:
            func = function3;
            break;
        default:
            printf("there is no such function\n");
            exit(-10);
    }

    return func;
}

/*
 * factory method for creating an integrator, based on parameter
 */
QuadratureRule* createMethod(char methodType, fptr func,
                            double a, double b) {

    QuadratureRule* integrator = NULL;

    if (methodType == 'm') {

        integrator = new MidpointRule(func, a, b);
    
    } else if (methodType == 's') {

        integrator = new SimpsonRule(func, a, b);

    } else {
        printf("there is no such method implemented\n");
        exit(-5);
    }

    return integrator;
}

int main(int argc, char* argv[]) {

    double a = 0;
    double b = 2;

    if (argc != 3 && argc != 5) {
        printHelp(argv);
        return 1;
    }

    if (strlen(argv[1]) > 1) {
        printHelp(argv);
        return 2;
    } 
    char method = argv[1][0];

    int functionIndex = atoi(argv[2]);
    if (functionIndex == 0) {
        printHelp(argv);
        return 3;
    }

    if (argc == 5) {
        a = atof(argv[3]);
        b = atof(argv[4]);
        if (b <= a) {
            printHelp(argv);
            return 4;
        }
    }

    fptr func = chooseFunc(functionIndex);
    QuadratureRule* integrator = createMethod(method, func, a, b);

    printf("performing integration\n");
    integrator->integrate();
    printf("result of integrating function %d in interval [%5.3lf, %5.3lf] = %5.3lf\n",
            functionIndex, a, b, integrator->getResult());

    return 0;
}
