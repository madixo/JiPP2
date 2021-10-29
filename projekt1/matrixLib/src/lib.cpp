#include "lib.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

int** allocIntMatrix(int rows, int cols) {
    
    int **A = new int*[rows];

    for(int i = 0; i < rows; i++) {

        A[i] = new int[cols];
        
    }

    return A;

}

double** allocDoubleMatrix(int rows, int cols) {
    
    double **A = new double*[rows];

    for(int i = 0; i < rows; i++) {

        A[i] = new double[cols];
        
    }

    return A;

}

void deallocMatrix(int **A, int rows) {

    deallocMatrix((double**)A, rows);

}

void deallocMatrix(double **A, int rows) {

    for(int i = 0; i < rows; i++)
        delete[] A[i];
        
    delete[] A;

}

int numlen(const int &x) {
    
    return log10(x) + 1;

}

int numlen(const double &x) {

    return log10(x) + 1;

}

void justify(int **A, int rows, int cols, int *tab) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            if(i == 0)
                tab[j] = A[i][j];
            else
                if(numlen(A[i][j]) > tab[j]) tab[j] = A[i][j];

        }

    }

}

void justify(double **A, int rows, int cols, int *tab) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            if(i == 0)
                tab[j] = A[i][j];
            else
                if(numlen(A[i][j]) > tab[j]) tab[j] = A[i][j];

        }

    }

}

void showMatrix(int **A, int rows, int cols) {
    
    int *maxlen = new int[cols];

    justify(A, rows, cols, maxlen);

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            std::cout << std::left << std::setw(maxlen[j] + 1) << A[i][j];

        }

        std::cout << std::endl;

    }

    delete[] maxlen;

}

void showMatrix(double **A, int rows, int cols) {
    
    int *maxlen = new int[cols];

    justify(A, rows, cols, maxlen);

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            std::cout << std::left << std::setprecision(4) << std::setw(maxlen[j] + 5) << A[i][j];

        }

        std::cout << std::endl;

    }

    delete[] maxlen;

}

int** addMatrix(int **A, int **B, int rows, int cols) {
    
    int **C = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            C[i][j] = A[i][j] + B[i][j];

        }

    }

    return C;

}

double** addMatrix(double **A, double **B, int rows, int cols) {
    
    double **C = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            C[i][j] = A[i][j] + B[i][j];

        }

    }

    return C;

}

void swap(double &a, double &b) {
    
    double temp;
    temp = a;
    a = b;
    b = temp;

}

void swap(int &a, int &b) {
    
    int temp;
    temp = a;
    a = b;
    b = temp;

}

