#ifndef MATOP
#define MATOP

double** allocateMatrix(int r, int c);
double* allocateVector(int size);
void deleteMatrix(double **mat, int r);
void deleteVector(double *vector);

void fillMatrix(double **mat, int r, int c);
void fillVector(double *vector, int r);
void printMatrix(double **mat, int r, int c);
void printVector(double *vect, int n);

#endif //MATOP
