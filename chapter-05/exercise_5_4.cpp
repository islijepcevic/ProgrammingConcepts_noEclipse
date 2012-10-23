/*
 * exercise_5_4.cpp
 *
 * standard deviation
 *
 * Created on: Oct 05, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cmath>

using namespace std;

double calculateMean(double *vector, int size);

double calculateStandardDeviation(double *vector, int size);

int main(int argc, char* argv[]) {

    int size;
    cout << "enter array size: ";
    cin >> size;

    double *vector = new double[size];
    for (int i = 0; i < size; i++) {
        cout << "enter element " << i << ": ";
        cin >> vector[i];
    }


    cout << endl;
    cout << "mean = " << calculateMean(vector, size) << endl;
    cout << "standard deviation = " << calculateStandardDeviation(vector, size) << endl;

    delete [] vector;

    return 0;
}

double calculateMean(double *vector, int size) {
    double mean = 0;
    for (int i = 0; i < size; i++) {
        mean += vector[i];
    }

    return mean / size;
}

double calculateStandardDeviation(double *vector, int size) {

    double mean = calculateMean(vector, size);

    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + pow(vector[i] - mean, 2.0);
    }

    return sqrt( sum / (size - 1) );
}
