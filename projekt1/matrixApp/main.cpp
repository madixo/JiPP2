#include <iostream>
#include "lib.hpp"
using namespace std;

int main() {

    int **A = allocIntMatrix(3, 3);

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            A[i][j] = (i + 1) * (j + 1);

        }

    }

    showMatrix(A, 3, 3);

    int **B = addMatrix(A, A, 3, 3);

    showMatrix(B, 3, 3);

    deallocMatrix(A, 3);
    deallocMatrix(B, 3);

    return 0;

}