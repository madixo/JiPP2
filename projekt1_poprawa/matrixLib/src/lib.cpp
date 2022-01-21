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

    for(int i = 0; i < rows; i++)
        delete[] A[i];
        
    delete[] A;

}

void deallocMatrix(double **A, int rows) {

    for(int i = 0; i < rows; i++)
        delete[] A[i];
        
    delete[] A;

}

int** identityIntMatrix(int rows, int cols) {
    
    int **A = allocIntMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i == j) A[i][j] = 1;
            else A[i][j] = 0;

    return A;

}

double** identityDoubleMatrix(int rows, int cols) {
    
    double **A = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i == j) A[i][j] = 1;
            else A[i][j] = 0;

    return A;

}

/**
 * @brief Zwraca ilosc cyfr w danej liczbie typu int
 * 
 * @param x liczba typu int
 * @return ilosc cyfr x 
 */
int numlen(int const &x) {
    
    int l = log10(abs(x));

    if(x < 0)
        return l + 2;
    return l + 1;

}


/**
 * @brief Zwraca ilosc cyfr w danej liczbie typu double
 * 
 * @param x liczba typu double
 * @return ilosc cyfr x 
 */
int numlen(double const &x) {

    int l = log10(abs(x));

    if(x < 0)
        return l + 2;
    return l + 1;

}

/**
 * @brief Funkcja pomocnicza przy formatowaniu tekstu do wyswietlenia macierzy
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param tab tablica odstepow
 */
void justify(int **A, int rows, int cols, int *tab) {

    int temp;

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            if(i == 0)
                tab[j] = numlen(A[i][j]);
            else
                if((temp = numlen(A[i][j])) > tab[j]) tab[j] = temp;

        }

    }

}

/**
 * @brief Funkcja pomocnicza przy formatowaniu tekstu do wyswietlenia macierzy
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param tab tablica odstepow
 */
void justify(double **A, int rows, int cols, int *tab) {

    int temp;

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            if(i == 0)
                tab[j] = numlen(A[i][j]);
            else
                if((temp = numlen(A[i][j])) > tab[j]) tab[j] = temp;

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

        if(i != rows - 1) std::cout << std::endl;

    }

    delete[] maxlen;

}

void showMatrix(double **A, int rows, int cols) {
    
    int *maxlen = new int[cols];

    justify(A, rows, cols, maxlen);

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            std::cout << std::left << std::setprecision(2) << std::fixed << std::setw(maxlen[j] + 4) << A[i][j];

        }

        if(i != rows - 1) std::cout << std::endl;

    }

    delete[] maxlen;

}

int** inputIntMatrix(int rows, int cols) {
    
    int **A = allocIntMatrix(rows, cols);

    for(int i = 0; i < rows; i++) {

        std::cout << "Podaj elementy " << i + 1 << " wiersza (oddzielone spacja): ";

        for(int j = 0; j < cols; j++) {

            std::cin >> A[i][j];
            
        }

    }

    return A;

}

double** inputDoubleMatrix(int rows, int cols) {
    
    double **A = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++) {

        std::cout << "Podaj elementy " << i + 1 << " wiersza (oddzielone spacja): ";

        for(int j = 0; j < cols; j++) {

            std::cin >> A[i][j];
            
        }

    }

    return A;

}

int** addMatrix(int **A, int **B, int rows, int cols) {
    
    int **C = allocIntMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;

}

double** addMatrix(double **A, double **B, int rows, int cols) {
    
    double **C = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;

}

int** subtractMatrix(int **A, int **B, int rows, int cols) {
    
    int **C = allocIntMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;

}

double** subtractMatrix(double **A, double **B, int rows, int cols) {
    
    double **C = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;

}

int** multiplyMatrix(int **A, int **B, int rowsA, int colsA, int colsB) {

    if(rowsA != colsB) throw "Macierz B musi mieć tyle samo kolumn co macierz A wierszy!";

    int **C = allocIntMatrix(rowsA, colsB), w;

    for(int i = 0; i < rowsA; i++) {

        for(int j = 0; j < colsB; j++) {

            w = 0;

            for(int k = 0; k < colsB; k++)
                w += A[i][k] * B[k][j];

            C[i][j] = w;

        }

    }

    return C;

}

double** multiplyMatrix(double **A, double **B, int rowsA, int colsA, int colsB) {

    if(rowsA != colsB) throw "Macierz B musi mieć tyle samo kolumn co macierz A wierszy!";

    double **C = allocDoubleMatrix(rowsA, colsB), w;

    for(int i = 0; i < rowsA; i++) {

        for(int j = 0; j < colsB; j++) {

            w = 0;

            for(int k = 0; k < colsB; k++)
                w += A[i][k] * B[k][j];
                
            C[i][j] = w;

        }

    }

    return C;

}

int** multiplyByScalar(int **A, int rows, int cols, int x) {

    int **B = allocIntMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            B[i][j] = A[i][j] * x;

    return B;

}

double** multiplyByScalar(double **A, int rows, int cols, double x) {

    double **B = allocDoubleMatrix(rows, cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            B[i][j] = A[i][j] * x;

    return B;

}

int** transpozeMatrix(int **A, int rows, int cols) {
    
    int **B = allocIntMatrix(cols, rows);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            B[j][i] = A[i][j];

    return B;

}

double** transpozeMatrix(double **A, int rows, int cols) {
    
    double **B = allocDoubleMatrix(cols, rows);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            B[j][i] = A[i][j];

    return B;

}

int** powerMatrix(int **A, int rows, int cols, unsigned int n) {

    if(rows != cols) throw "Macierz musi byc kwadratowa!";

    int **W = identityIntMatrix(rows, rows), **V;

    while(n > 0) {

        if(n & 1) {

            V = multiplyMatrix(A, W, rows, rows, rows);
            deallocMatrix(W, rows);
            W = V;

        }

        if((n >>= 1) != 0) {

            V = multiplyMatrix(W, W, rows, rows, rows);
            deallocMatrix(W, rows);
            W = V;

        }

    }

    return W;

}

double** powerMatrix(double **A, int rows, int cols, unsigned int n) {

    if(rows != cols) throw "Macierz musi byc kwadratowa!";

    double **W = identityDoubleMatrix(rows, rows), **V;

    while(n > 0) {

        if(n & 1) {

            V = multiplyMatrix(A, W, rows, rows, rows);
            deallocMatrix(W, rows);
            W = V;

        }

        if((n >>= 1) != 0) {

            V = multiplyMatrix(W, W, rows, rows, rows);
            deallocMatrix(W, rows);
            W = V;

        }

    }

    return W;

}

int determinantMatrix(int **A, int rows, int cols) {
    
    if(rows != cols) throw "Macierz musi byc kwadratowa!";

    if(rows == 1)
        return **A;
    if(rows == 2)
        return (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
    else {

        int **sub = allocIntMatrix(rows - 1, rows - 1), det = 0;

        for(int k = 0; k < rows; k++) {

            for(int i = 1; i < rows; i++) {

                for(int j = 0, jj = 0; j < rows; j++) {

                    if(j == k) continue;

                    sub[i - 1][jj++] = A[i][j];

                }

            }

            det = det + (pow(-1, k) * A[0][k] * determinantMatrix(sub, rows - 1, rows - 1));

        }

        deallocMatrix(sub, rows - 1);

        return det;

    }

}

double determinantMatrix(double **A, int rows, int cols) {
    
    if(rows != cols) throw "Macierz musi byc kwadratowa!";

    if(rows == 1)
        return **A;
    if(rows == 2)
        return (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
    else {

        double **sub = allocDoubleMatrix(rows - 1, rows - 1), det = 0;

        for(int k = 0; k < rows; k++) {

            for(int i = 1; i < rows; i++) {

                for(int j = 0, jj = 0; j < rows; j++) {

                    if(j == k) continue;

                    sub[i - 1][jj++] = A[i][j];

                }

            }

            det = det + (pow(-1, k) * A[0][k] * determinantMatrix(sub, rows - 1, rows - 1));

        }

        deallocMatrix(sub, rows - 1);

        return det;

    }

}

bool matrixIsDiagonal(int **A, int rows, int cols) {
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i != j && A[i][j] != 0)
                return false;

    return true;

}

bool matrixIsDiagonal(double **A, int rows, int cols) {
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i != j && A[i][j] != 0)
                return false;

    return true;

}

void swap(int &a, int &b) {
    
    int temp;
    temp = a;
    a = b;
    b = temp;

}

void swap(double &a, double &b) {
    
    double temp;
    temp = a;
    a = b;
    b = temp;

}

int* sortRow(int *a, int n) {
    
    bool swapped = false;

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - i - 1; j++) {
            
            if(a[j] > a[j + 1]) {
            
                swap(a[j], a[j + 1]);
                swapped = true;

            }

        }

        if(!swapped) break;

    }

    return a;
    
}

double* sortRow(double *a, int n) {
    
    bool swapped = false;

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - i - 1; j++) {

            if(a[j] > a[j + 1]) {
            
                swap(a[j], a[j + 1]);
                swapped = true;

            }

        }

        if(!swapped) break;

    }

    return a;
    
}

int** sortRowsInMatrix(int **A, int rows, int cols) {
    
    for(int i = 0; i < rows; i++)
        sortRow(A[i], cols);

    return A;

}

double** sortRowsInMatrix(double **A, int rows, int cols) {
    
    for(int i = 0; i < rows; i++)
        sortRow(A[i], cols);

    return A;

}