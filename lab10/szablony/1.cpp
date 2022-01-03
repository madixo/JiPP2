#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template<typename T, typename sT = size_t>
void printArray(T* a, sT n) {

    cout << '[';

    for(sT i = 0; i < n - 1; i++)
        cout << a[i] << ", ";

    cout << a[n - 1] << ']' << endl;

}

template<typename T, typename sT = size_t>
void printMatrix(T** a, sT n, sT m) {

    size_t *w_val = new size_t[m];

    for(sT i = 0; i < m; i++) {

        w_val[i] = 0;

        for(sT j = 0; j < n; j++) {

            w_val[i] = ::max(w_val[i], (size_t)(a[j][i] < 0 ? log10(abs(a[j][i])) + 2 : log10(a[j][i]) + 1));

        }
        
    }

    for(sT i = 0; i < n; i++) {
    
        if(i == 0 || i == n - 1)
            cout << "- ";
        else
            cout << "| ";

        for(sT j = 0; j < m - 1; j++) {
        

            cout << setw(w_val[i]) << right << a[i][j] << ", ";

        }

        cout << setw(w_val[i]) << right << a[i][m - 1];

        if(i == 0 || i == n - 1)
            cout << " -";
        else
            cout << " |";

        cout << '\n';
    
    }

    delete[] w_val;

    cout.flush();

}

int main() {

    int tab[] = {1, 2, 3, 4, 5};
    int **matrix = new int*[3];
    for(size_t i = 0; i < 3; i++)
        matrix[i] = new int[3];

    for(size_t i = 0; i < 3; i++) {
    
        for(size_t j = 0; j < 3; j++) {
        
            matrix[i][j] = (i + 4 + ((j + i) * 79 % 240)) * pow(-1, i + 1);
        
        }
    
    }

    cout << "min(4, 7) = " << ::min(4, 7) << '\n';
    cout << "max(4, 7) = " << ::max(4, 7) << '\n';
    cout << "tab = ";
    printArray(tab, sizeof(tab) / sizeof(*tab));
    cout << '\n' << "matrix = " << '\n';
    printMatrix(matrix, 3, 3);

    for(size_t i = 0; i < 3; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;

}