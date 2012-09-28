/*
 * exercise_4_1.cpp
 *
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

    int i = 5;
    int *p_j = &i;
    *(p_j) = *(p_j) * *(p_j);

    int *p_k = new int;
    *p_k = i;

    cout << "i:\t" << i << endl;
    cout << "*p_j:\t" << *p_j << endl;
    cout << "*p_k:\t" << *p_k << endl;

    delete p_k;
    return 0;
}

