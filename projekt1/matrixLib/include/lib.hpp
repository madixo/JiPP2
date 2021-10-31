#ifndef MATRIX_LIB_HPP
#define MATRIX_LIB_HPP

/**
 * @brief Alokuje pamięć na macierz typu int
 * o rozmiarze rows x cols
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz typu int
 */
int** allocIntMatrix(int rows, int cols);

/**
 * @brief Alokuje pamięć na macierz typu double
 * o rozmiarze rows x cols
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz typu double
 */
double** allocDoubleMatrix(int rows, int cols);

/**
 * @brief Usuwa z pamięci macierz typu int
 * 
 * @param A macierz
 * @param rows ilość wierszy
 */
void deallocMatrix(int **A, int rows);

/**
 * @brief Usuwa z pamięci macierz typu double
 * 
 * @param A macierz
 * @param rows ilość wierszy
 */
void deallocMatrix(double **A, int rows);

/**
 * @brief Tworzy macierz jednostkową typu int
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz jednostkowa typu int
 */
int** identityIntMatrix(int rows, int cols);

/**
 * @brief Tworzy macierz jednostkową typu double
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz jednostkowa typu double
 */
double** identityDoubleMatrix(int rows, int cols);

/**
 * @brief Wyświetla macierz typu int
 * 
 * @param A macierz
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 */
void showMatrix(int **A, int rows, int cols);

/**
 * @brief Wyświetla macierz typu double
 * 
 * @param A macierz
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 */
void showMatrix(double **A, int rows, int cols);

/**
 * @brief Wczytuje macierz od użytkownika
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz podana przez użytkownika
 */
int** inputIntMatrix(int rows, int cols);

/**
 * @brief Wczytuje macierz od użytkownika
 * po zakończeniu korzystania z macierzy,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz podana przez użytkownika
 */
double** inputDoubleMatrix(int rows, int cols);

/**
 * @brief Dodaje ze sobą macierz A i macierz B typu int
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz wynikowa typu int
 */
int** addMatrix(int **A, int **B, int rows, int cols);

/**
 * @brief Dodaje ze sobą macierz A i macierz B typu double
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz wynikowa typu double
 */
double** addMatrix(double **A, double **B, int rows, int cols);

/**
 * @brief Odejmuje od macierzy A macierz B typu int
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz wynikowa typu int
 */
int** subtractMatrix(int **A, int **B, int rows, int cols);

/**
 * @brief Odejmuje od macierzy A macierz B typu double
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz wynikowa typu double
 */
double** subtractMatrix(double **A, double **B, int rows, int cols);

/**
 * @brief Mnoży ze sobą macierze A i B (AxB) typu int
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rowsA ilość wierszy macierzy A
 * @param colsA ilość kolumn macierzy B
 * @param colsB ilość kolumn macierzy B
 * @return macierz wynikowa typu int
 */
int** multiplyMatrix(int **A, int **B, int rowsA, int colsA, int colsB);

/**
 * @brief Mnoży ze sobą macierze A i B (AxB) typu double
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param B macierz B
 * @param rowsA ilość wierszy macierzy A
 * @param colsA ilość kolumn macierzy B
 * @param colsB ilość kolumn macierzy B
 * @return macierz wynikowa typu double
 */
double** multiplyMatrix(double **A, double **B, int rowsA, int colsA, int colsB);

/**
 * @brief Mnoży macierz A ze skalarem x typu int
 * na macierzy wynikowej należy użyć funkcji deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param x skalar x
 * @return macierz wynikowa typu int
 */
int** multiplyByScalar(int **A, int rows, int cols, int x);

/**
 * @brief Mnoży macierz A ze skalarem x typu double
 * na macierzy wynikowej należy użyć funkcji deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param x skalar x
 * @return macierz wynikowa typu double
 */
double** multiplyByScalar(double **A, int rows, int cols, double x);

/**
 * @brief Transponuje macierz A typu int
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return ztransponowana macierz typu int
 */
int** transpozeMatrix(int **A, int rows, int cols);

/**
 * @brief Transponuje macierz A typu double
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return ztransponowana macierz typu double
 */
double** transpozeMatrix(double **A, int rows, int cols);

/**
 * @brief Podnosi macierz A do potęgi n typu int
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param n potęga n
 * @return macierz wynikowa typu int
 */
int** powerMatrix(int **A, int rows, int cols, unsigned int n);

/**
 * @brief Podnosi macierz A do potęgi n typu double
 * po zakończeniu korzystania z macierzy wynikowej,
 * należy na niej wywołać funkcję deallocMatrix
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @param n potęga n
 * @return macierz wynikowa typu double
 */
double** powerMatrix(double **A, int rows, int cols, unsigned int n);

/**
 * @brief Oblicza wyznacznik macierzy A typu int
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return wyznacznik macierzy A
 */
int determinantMatrix(int **A, int rows, int cols);

/**
 * @brief Oblicza wyznacznik macierzy A typu double
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return wyznacznik macierzy A
 */
double determinantMatrix(double **A, int rows, int cols);

/**
 * @brief Sprawdza czy macierz typu int jest diagonalna
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return true - macierz diagonalna, false - macierz niediagonalna
 */
bool matrixIsDiagonal(int **A, int rows, int cols);

/**
 * @brief Sprawdza czy macierz typu double jest diagonalna
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return true - macierz diagonalna, false - macierz niediagonalna
 */
bool matrixIsDiagonal(double **A, int rows, int cols);

/**
 * @brief Zamienia wartość zmiennej a z wartością zmiennej b typu int
 * 
 * @param a zmienna a
 * @param b zmienna b
 */
void swap(int &a, int &b);

/**
 * @brief Zamienia wartość zmiennej a z wartością zmiennej b typu double
 * 
 * @param a zmienna a
 * @param b zmienna b
 */
void swap(double &a, double &b);

/**
 * @brief Sortuje wiersz a macierzy typu int rosnąco
 * 
 * @param a wiersz a
 * @param n ilosc liczb w wierszu
 * @return posortowany wiersz a
 */
int* sortRow(int *a, int n);

/**
 * @brief Sortuje wiersz a macierzy typu double rosnąco
 * 
 * @param a wiersz a
 * @param n ilosc liczb w wierszu
 * @return posortowany wiersz a
 */
double* sortRow(double *a, int n);

/**
 * @brief Sortuje wiersze w macierzy A typu int rosnąco
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz A z posortowanymi wierszami
 */
int** sortRowsInMatrix(int **A, int rows, int cols);

/**
 * @brief Sortuje wiersze w macierzy A typu double rosnąco
 * 
 * @param A macierz A
 * @param rows ilość wierszy
 * @param cols ilość kolumn
 * @return macierz A z posortowanymi wierszami
 */
double** sortRowsInMatrix(double **A, int rows, int cols);

#endif // MATRIX_LIB_HPP