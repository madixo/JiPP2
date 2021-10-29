#ifndef MATRIX_LIB_HPP
#define MATRIX_LIB_HPP

int** allocIntMatrix(int rows, int cols);
double** allocDoubleMatrix(int rows, int cols);

void deallocMatrix(int **A, int rows);
void deallocMatrix(double **A, int rows);

void showMatrix(int **A, int rows, int cols);
void showMatrix(double **A, int rows, int cols);

int** addMatrix(int **A, int **B, int rows, int cols);
int** subtractMatrix(int **A, int **B, int rows, int cols);
int** multiplyMatrix(int **A, int **B, int rowsA, int colsA, int colsb);
int** multiplyByScalar(int **A, int rows, int cols, int x);
int** transpozeMatrix(int **A, int rows, int cols);
int** powerMatrix(int **A, int rows, int cols, unsigned int n);
int determinantMatrix(int **A, int rows, int cols);
bool matrixIsDiagonal(int **A, int rows, int cols);
void swap(int &a, int &b);
int* sortRow(int *tab, int n);
int** sortRowsInMatrix(int **A, int rows, int cols);

double** addMatrix(double **A, double **B, int rows, int cols);
double** subtractMatrix(double **A, double **B, int rows, int cols);
double** multiplyMatrix(double **A, double **B, int rowsA, int colsA, int colsb);
double** multiplyByScalar(double **A, int rows, int cols, double x);
double** transpozeMatrix(double **A, int rows, int cols);
double** powerMatrix(double **A, int rows, int cols, double n);
double determinantMatrix(double **A, int rows, int cols);
bool matrixIsDiagonal(double **A, int rows, int cols);
void swap(double &a, double &b);
double* sortRow(double *tab, int n);
double** sortRowsInMatrix(double **A, int rows, int cols);

#endif // MATRIX_LIB_HPP