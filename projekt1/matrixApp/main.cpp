#include <iostream>
#include "lib.hpp"
using namespace std;

void show_help() {

    cout << R"(Projekt macierze
matrixApp [typ] [nazwa dzialania]

Typy:
    int - dzialania na typach int
    double - dzialania na typach double

Dzialania:
add [rows] [cols]
subtract [rows] [cols]
multiply [rows] [cols] [rows] [cols]
multiplys [rows] [cols] [x] 
transpoze [rows] [cols]
power [rows] [cols] [n]
determinant [rows] [cols]
isDiagonal [rows] [cols]
sortRow [rows] [cols] [row] 
sortRows [rows] [cols]
)";

}

void bad_num_args() {

    cout << "Podano zla ilosc argumentow!";

}

void bad_args() {

    cout << "Podano zle argumenty!";

}

void bad_operation() {

    cout << "Podano zla operacje!";

}

int main(int argc, char** argv) {

    if(argc < 4) {

        show_help();

    }else {

        string type_string = argv[1];

        if(type_string != "int" && type_string != "double") {

            bad_args();

            return -1;

        }

        const bool isInt = type_string == "int" ? true : false;

        const string operation = argv[2];

        if(operation == "add") {


            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz A:\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Wprowadz macierz B:\n";
                    int **B = inputIntMatrix(rows, cols),
                        **C = addMatrix(A, B, rows, cols);

                    cout << "Wynik dodawania macierzy:\n";

                    showMatrix(A, rows, cols);

                    cout << "\nz macierza:\n";

                    showMatrix(B, rows, cols);

                    cout << "\nwynosi:\n";

                    showMatrix(C, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);
                    deallocMatrix(C, rows);

                }else {

                    cout << "Wprowadz macierz A:\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    cout << "Wprowadz macierz B:\n";
                    double **B = inputDoubleMatrix(rows, cols),
                        **C = addMatrix(A, B, rows, cols);

                    cout << "Wynik dodawania macierzy:\n";

                    showMatrix(A, rows, cols);

                    cout << "\nz macierza:\n";

                    showMatrix(B, rows, cols);

                    cout << "\nwynosi:\n";

                    showMatrix(C, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);
                    deallocMatrix(C, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "subtract") {
            
            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz A:\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Wprowadz macierz B:\n";
                    int **B = inputIntMatrix(rows, cols),
                        **C = subtractMatrix(A, B, rows, cols);

                    cout << "Wynik odejmowania macierzy:\n";

                    showMatrix(A, rows, cols);

                    cout << "\nz macierza:\n";

                    showMatrix(B, rows, cols);

                    cout << "\nwynosi:\n";

                    showMatrix(C, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);
                    deallocMatrix(C, rows);

                }else {

                    cout << "Wprowadz macierz A:\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    cout << "Wprowadz macierz B:\n";
                    double **B = inputDoubleMatrix(rows, cols),
                        **C = subtractMatrix(A, B, rows, cols);

                    cout << "Wynik odejmowania macierzy:\n";

                    showMatrix(A, rows, cols);

                    cout << "\nz macierza:\n";

                    showMatrix(B, rows, cols);

                    cout << "\nwynosi:\n";

                    showMatrix(C, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);
                    deallocMatrix(C, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "multiply") {
            
            if(argc == 7) {

                int rowsA, colsA, rowsB, colsB;

                try {

                    rowsA = stoi(argv[3]);
                    colsA = stoi(argv[4]);
                    rowsB = stoi(argv[5]);
                    colsB = stoi(argv[6]);


                }catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz A:\n";
                    int **A = inputIntMatrix(rowsA, colsA);

                    cout << "Wprowadz macierz B:\n";
                    int **B = inputIntMatrix(rowsA, colsA);

                    try {

                        int **C = multiplyMatrix(A, B, rowsA, colsA, colsB);

                        cout << "Wynik mnozenia macierzy:\n";

                        showMatrix(A, rowsA, colsA);

                        cout << "\nz macierza:\n";

                        showMatrix(B, rowsA, colsA);

                        cout << "\nwynosi:\n";

                        showMatrix(C, rowsA, colsA);

                        deallocMatrix(A, rowsA);
                        deallocMatrix(B, rowsA);
                        deallocMatrix(C, rowsA);

                    }catch(string const &s) {

                        cout << s << endl;

                        return -1;

                    }

                }else {

                    cout << "Wprowadz macierz A:\n";
                    double **A = inputDoubleMatrix(rowsA, colsA);

                    cout << "Wprowadz macierz B:\n";
                    double **B = inputDoubleMatrix(rowsA, colsA);

                    try {

                        double **C = multiplyMatrix(A, B, rowsA, colsA, colsB);

                        cout << "Wynik mnozenia macierzy:\n";

                        showMatrix(A, rowsA, colsA);

                        cout << "\nz macierza:\n";

                        showMatrix(B, rowsA, colsA);

                        cout << "\nwynosi:\n";

                        showMatrix(C, rowsA, colsA);

                        deallocMatrix(A, rowsA);
                        deallocMatrix(B, rowsA);
                        deallocMatrix(C, rowsA);

                    }catch(string const &s) {

                        cout << s << endl;

                        return -1;

                    }

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "multiplys") {
            
            if(argc == 6) {

                int rows, cols, x;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);
                    x = stoi(argv[5]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz:\n";
                    int **A = inputIntMatrix(rows, cols),
                        **B = multiplyByScalar(A, rows, cols, x);

                    cout << "Wynik mnozenia macierzy\n";

                    showMatrix(A, rows, cols);

                    cout << "\nze skalarem " << x << "wynosi:\n";

                    showMatrix(B, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);

                }else {

                    cout << "Wprowadz macierz:\n";
                    double **A = inputDoubleMatrix(rows, cols),
                        **B = multiplyByScalar(A, rows, cols, x);

                    cout << "Wynik mnozenia macierzy\n";

                    showMatrix(A, rows, cols);

                    cout << "\nze skalarem " << x << "wynosi:\n";

                    showMatrix(B, rows, cols);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "transpoze") {
            
            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                } catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz:\n";
                    int **A = inputIntMatrix(rows, cols),
                        **B = transpozeMatrix(A, rows, cols);

                    cout << "Transpozycja macierzy\n";

                    showMatrix(A, rows, cols);

                    cout << "\nwyglada\n";

                    showMatrix(B, cols, rows);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, cols);

                }else {

                    cout << "Wprowadz macierz:\n";
                    double **A = inputDoubleMatrix(rows, cols),
                        **B = transpozeMatrix(A, rows, cols);

                    cout << "Transpozycja macierzy\n";

                    showMatrix(A, rows, cols);

                    cout << "\nwyglada\n";

                    showMatrix(B, cols, rows);

                    deallocMatrix(A, rows);
                    deallocMatrix(B, cols);

                }                

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "power") {
            
            if(argc == 6) {

                int rows, cols, n;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);
                    n = stoi(argv[5]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;

                }

                if(isInt) {

                    cout << "Wprowadz macierz\n";
                    int **A = inputIntMatrix(rows, cols);

                    try {

                        int **B = powerMatrix(A, rows, cols, n);

                        cout << n << " potega macierzy\n";

                        showMatrix(A, rows, cols);

                        cout << "\nwyglada\n";

                        showMatrix(B, rows, cols);

                        deallocMatrix(A, rows);
                        deallocMatrix(B, rows);

                    }catch(string const &s) {

                        cout << s << endl;

                        return -1;
                        
                    }

                }else {

                    cout << "Wprowadz macierz\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    try {

                        double **B = powerMatrix(A, rows, cols, n);

                        cout << n << " potega macierzy\n";

                        showMatrix(A, rows, cols);

                        cout << "\nwyglada\n";

                        showMatrix(B, rows, cols);

                        deallocMatrix(A, rows);
                        deallocMatrix(B, rows);

                    }catch(string const &s) {

                        cout << s << endl;

                        return -1;
                        
                    }

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "determinant") {
            
            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;
                    
                }

                if(isInt) {

                    cout << "Wprowadz macierz\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Wyznacznik macierzy\n";
                    
                    showMatrix(A, rows, cols);

                    cout << "\nwynosi " << determinantMatrix(A, rows, cols);

                    deallocMatrix(A, rows);

                }else {

                    cout << "Wprowadz macierz\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    cout << "Wyznacznik macierzy\n";
                    
                    showMatrix(A, rows, cols);

                    cout << "\nwynosi " << determinantMatrix(A, rows, cols);

                    deallocMatrix(A, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "isDiagonal") {
            
            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;
                    
                }

                if(isInt) {

                    cout << "Wprowadz macierz\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << (matrixIsDiagonal(A, rows, cols) ? "jest" : "nie jest") << " diagonalna";

                    deallocMatrix(A, rows);

                }else {

                    cout << "Wprowadz macierz\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << (matrixIsDiagonal(A, rows, cols) ? "jest" : "nie jest") << " diagonalna";

                    deallocMatrix(A, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "sortRow") {
            
            if(argc == 6) {

                int rows, cols, row;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);
                    row = stoi(argv[5]);

                    if(row < 0 || row > cols) throw exception();

                }catch(const exception &e) {

                    bad_args();

                    return -1;
                    
                }

                if(isInt) {

                    cout << "Wprowadz macierz\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << "\npo posortowaniu " << row << " wiersza\n";

                    sortRow(A[row], cols);

                    showMatrix(A, rows, cols);

                    deallocMatrix(A, rows);

                }else {

                    cout << "Wprowadz macierz\n";
                    double **A = inputDoubleMatrix(rows, cols);
                    
                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << "\npo posortowaniu " << row << " wiersza\n";

                    sortRow(A[row], cols);

                    showMatrix(A, rows, cols);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "sortRows") {
            
            if(argc == 5) {

                int rows, cols;

                try {

                    rows = stoi(argv[3]);
                    cols = stoi(argv[4]);

                }catch(const exception &e) {

                    bad_args();

                    return -1;
                    
                }

                if(isInt) {

                    cout << "Wprowadz macierz\n";
                    int **A = inputIntMatrix(rows, cols);

                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << "\npo posortowaniu\n";
                    
                    sortRowsInMatrix(A, rows, cols);

                    showMatrix(A, rows, cols);

                    deallocMatrix(A, rows);

                }else {

                    cout << "Wprowadz macierz\n";
                    double **A = inputDoubleMatrix(rows, cols);

                    cout << "Macierz\n";

                    showMatrix(A, rows, cols);

                    cout << "\npo posortowaniu\n";

                    sortRowsInMatrix(A, rows, cols);

                    showMatrix(A, rows, cols);

                    deallocMatrix(A, rows);

                }

            }else {

                bad_num_args();

                return -1;

            }

        }else {

            bad_operation();

            return -1;

        }
        
    }

    return 0;

}