/*
 * exercise_2_5.cpp
 *
 *
 * Created on: Sept 27, 2012
 * 	   Author: Ivan Slijepcevic <ivan.slijepcevic@epfl.ch>
 *
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void inputMatrix(vector< vector<double> > &matrix) {

    matrix.clear();

    for (unsigned int i = 0; i < 2; i++) {
        vector<double> row;
        for (unsigned int j = 0; j < 2; j++) {
            std::cout << "enter M[" << i << "][" << j << "]: ";
            double element;
            std::cin >> element;
            row.push_back(element);
        }
        matrix.push_back(row);
    }
}

void printMatrix(vector< vector<double> > &matrix) {

    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

double computeDeterminant2(vector< vector<double> > &matrix) {

    assert(matrix.size() == 2);

    double det =  matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return det;
}

vector< vector<double> > getInverse2(vector< vector<double> > &matrix) {

    assert(matrix.size() == 1);

    double denom = computeDeterminant2(matrix);

    vector< vector<double> > inverse;

    vector<double> row;
    row.push_back(matrix[1][1] / denom);
    row.push_back(-matrix[0][1] / denom);
    inverse.push_back(row);

    row.clear();
    row.push_back(-matrix[1][0] / denom);
    row.push_back(matrix[0][0] / denom);
    inverse.push_back(row);

    assert(fabs(det) >= 10e-6);
    return inverse;
}

int main(int argc, char* argv[]) {

    vector< vector<double> > matrix;
    inputMatrix(matrix);

    vector< vector<double> > inverse = getInverse2(matrix);
    cout << endl;
    cout << "inverse matrix:" << endl;
    printMatrix(inverse);

    return 0;
}

