/*
 * exercise_1_2.cpp
 *
 * Created on: Sept 28, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    int i=10, j=20;
    int *pi = &i, *pj = &j;
    int *ptmp = new int;

    *ptmp = *pi;
    *pi = *pj;
    *pj = *ptmp;

    delete ptmp;

    cout << "i=" << i << "\tj=" << j << endl;

    return 0;
}

