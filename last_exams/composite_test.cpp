/*
 * quadrature_test.cpp
 *
 * main function including tests for numerical integration
 *
 * Created on: Dec 17, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>

#include "QuadratureRule.hpp"
#include "MidpointRule.hpp"
#include "SimpsonRule.hpp"

#include "QuadratureFactory.hpp"
#include "MidpointFactory.hpp"
#include "SimpsonFactory.hpp"

#include "Interval.hpp"
#include "IntegrationGrid.hpp"
#include "CompositeIntegrator.hpp"

// typedef for functions
// this was introduced later during the coding
// so it is probably not refactored everywhere
typedef double (*fptr)(double);

/*
 * function that prints usage of the program
 */
void printHelp(char* argv[]) {

    printf("----usage----\n");
    printf("%s <quadrature_type> <function_index> <grid_file>\n\n", argv[0]);
    printf("quadrature_types:\n\t'm' - midpoint\n\t's' - simpson\n");
    printf("function_index:\n\t1\t2\t3\n");
    printf("grid_file:\n\tfile that contains the grid information\n");
    printf("\tevery line of the file contains one uniform grid\n");
    printf("\tone line looks like this:<numIntervals> <xMin> <xMax>\n");
}

// GRID FILE READING

IntegrationGrid createGrid(char* fname) {

    std::ifstream in(fname);

    IntegrationGrid grid;

    int numIntervals;
    double xLow, xHigh;

    while (in >> numIntervals >> xLow >> xHigh) {


        IntegrationGrid newGrid(numIntervals, xLow, xHigh);
        grid.makeUnion(newGrid);
    }

    in.close();

    return grid;
}

// FACTORY CREATOR

QuadratureFactory* createFactory(char methodType) {
    
    QuadratureFactory* factory = NULL;

    if (methodType == 'm') {

        factory = new MidpointFactory();
         
    } else if (methodType == 's') {

        factory = new SimpsonFactory();

    } else {
        printf("there is no such method implemented\n");
        exit(-5);
    }

    return factory;
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

int main(int argc, char* argv[]) {

    if (argc != 4) {
        printHelp(argv);
        return 1;
    }

    // QUADRATURE RULE
    if (strlen(argv[1]) > 1) {
        printHelp(argv);
        return 2;
    } 
    QuadratureFactory* factory = createFactory(argv[1][0]);

    // FUNCTION TO BE USED/TESTED
    int functionIndex = atoi(argv[2]);
    if (functionIndex == 0) {
        printHelp(argv);
        return 3;
    }
    fptr func = chooseFunc(functionIndex);

    // INTEGRATION GRID
    IntegrationGrid grid = createGrid(argv[3]);
    //grid.print();

    CompositeIntegrator integrator(func, factory, grid);

    printf("performing integration\n");
    integrator.integrate();
    printf("result of integrating function %d = %5.3lf\n",
            functionIndex, integrator.getResult());

    return 0;
}
