#include "lib.hpp"

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <functional>
using namespace std;

enum class Reason {

    BADARG,
    BADARGNUM,
    BADOPERATION,
    BADTYPE

};

unordered_map<Reason, string> error_messages{
    {Reason::BADARG, "Podano zle argumenty!\n"},
    {Reason::BADARGNUM, "Podano zla ilosc argumentow!\n"},
    {Reason::BADOPERATION, "Podano zla operacje!\n"},
    {Reason::BADTYPE, "Podano zly typ danych!\n"}
};

void show_error(Reason reason) {

    try {

        cout << error_messages.at(reason);

    }catch(out_of_range& e) {

        cout << "Nie znaleziono wiadomosci (PANIC)!\n";

    }

    cout << "Wpisz ./matrixApp help aby otrzymac pomoc!" << endl;

    exit(1);

}

enum class Type {

    DUMMY,
    INT,
    DOUBLE

};

unordered_map<string, Type> str_type{
    {"int", Type::INT},
    {"double", Type::DOUBLE}
};

Type get_type(const string& type) {

    try {

        return str_type.at(type);

    }catch(out_of_range& e) {

        show_error(Reason::BADTYPE);
        return Type::DUMMY;

    }

}

enum class Operation {

    DUMMY,
    ADD,
    SUBTRACT,
    MULTIPLY,
    MULTIPLYSCALAR,
    TRANSPOZE,
    POWER,
    DETERMINANT,
    DIAGONAL,
    SORTROW,
    SORTROWS

};

unordered_map<string, Operation> str_op{
    {"add", Operation::ADD},
    {"subtract", Operation::SUBTRACT},
    {"multiply", Operation::MULTIPLY},
    {"multiplyscalar", Operation::MULTIPLYSCALAR},
    {"transpoze", Operation::TRANSPOZE},
    {"power", Operation::POWER},
    {"determinant", Operation::DETERMINANT},
    {"isdiagonal", Operation::DIAGONAL},
    {"sortrow", Operation::SORTROW},
    {"sortrows", Operation::SORTROWS}
};

Operation get_operation(const string& op) {

    try {

        return str_op.at(op);

    }catch(out_of_range& e) {

        show_error(Reason::BADOPERATION);
        return Operation::DUMMY;

    }

}

unordered_map<Operation, int> op_args{
    {Operation::ADD, 2},
    {Operation::SUBTRACT, 2},
    {Operation::MULTIPLY, 4},
    {Operation::MULTIPLYSCALAR, 3},
    {Operation::TRANSPOZE, 2},
    {Operation::POWER, 3},
    {Operation::DETERMINANT, 2},
    {Operation::DIAGONAL, 2},
    {Operation::SORTROW, 3},
    {Operation::SORTROWS, 2}
};

unordered_map<Operation, int> op_matnum{
    {Operation::ADD, 2},
    {Operation::SUBTRACT, 2},
    {Operation::MULTIPLY, 2},
    {Operation::MULTIPLYSCALAR, 1},
    {Operation::TRANSPOZE, 1},
    {Operation::POWER, 1},
    {Operation::DETERMINANT, 1},
    {Operation::DIAGONAL, 1},
    {Operation::SORTROW, 1},
    {Operation::SORTROWS, 1}
};

void show_help() {

    cout << R"(Projekt macierze

matrixApp [typ] [nazwa dzialania]

Dostepne typy:
    int - dzialania na liczbach typu int
    double - dzialania na liczbach typu double

Dostepne operacje:
    add [rows] [cols]
    subtract [rows] [cols]
    multiply [rows] [cols] [rows] [cols]
    multiplyscalar [rows] [cols] [x] 
    transpoze [rows] [cols]
    power [rows] [cols] [n]
    determinant [rows] [cols]
    isdiagonal [rows] [cols]
    sortRow [rows] [cols] [row index]
    sortRows [rows] [cols]
)";

}

template<typename T>
T validate_user_input(int delimiter = ' ') {

    T in;

    while(true) {

        if(cin >> in) {

            return in;

        }else {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), delimiter);

        }

    }

}

template<typename T>
T user_input(const string& message) {

    cout << message;

    return validate_user_input<T>();

}

template<typename T>
void user_input(const string& message, T* A, int n) {

    cout << message;

    for(int i = 0; i < n; i++)
        A[i] = validate_user_input<T>();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

template<typename T>
T** inputMatrix(int rows, int cols) {

    T **A = allocMatrix<T>(rows, cols);

    for(int i = 0; i < rows; i++) {

        ostringstream ss;
        ss << "Wprowadz wartosci " << i << " wiersza macierzy (po spacji): ";

        user_input<T>(ss.str(), A[i], cols);

    }

    cout << endl;

    return A;

}

bool check_args_num(Operation op, int argc) {

    return !(argc - 3 - op_args.at(op));

}

template<typename T>
vector<T> parse_args(Operation op, int argc, char** argv) {

    if(!check_args_num(op, argc)) show_error(Reason::BADARGNUM);

    vector<T> args;
    args.resize(argc - 3);

    for(int i = 0; i < argc - 3; i++) {

        try {

            if((args[i] = stod(argv[3 + i])) < 1) show_error(Reason::BADARG);

        }catch(...) {

            show_error(Reason::BADARG);

        }

    }

    return args;

}

template<typename T>
void operation(int argc, char** argv) {

    Operation op = get_operation(string{argv[2]});

    vector<T> args = parse_args<T>(op, argc, argv);

    const int rows = args.at(0), cols = args.at(1);

    if(op == Operation::POWER || op == Operation::DETERMINANT || op == Operation::DIAGONAL) {

        if(cols != rows) {

            cout << "Macierz musi byc kwadratowa!" << endl;
            exit(1);

        }

    }else if(op == Operation::MULTIPLY) {

        if(args.at(1) != args.at(2)) {

            cout << "Macierz B musi mieć tyle samo wierszy co macierz A kolumn!" << endl;
            exit(1);

        }

    }

    int n = op_matnum.at(op);

    T ***M = new T**[n];

    if(op != Operation::MULTIPLY) {

        for(int i = 0; i < n; i++) {

            M[i] = inputMatrix<T>(rows, cols);

            ostringstream ss;
            ss << "Macierz " << i << ":\n";

            cout << ss.str();
            showMatrix(M[i], rows, cols);
            cout << '\n';

        }

    }

    switch(op) {

        case Operation::ADD:

            {
                T **out = addMatrix(M[0], M[1], rows, cols);

                cout << "Macierz wynikowa:\n";
                showMatrix(out, rows, cols);

                deallocMatrix(out, rows);
            }

            break;

        case Operation::SUBTRACT:

            {
                T **out = subtractMatrix(M[0], M[1], rows, cols);

                cout << "Macierz wynikowa:\n";
                showMatrix(out, rows, cols);

                deallocMatrix(out, rows);
            }

            break;

        case Operation::MULTIPLY:

            {
                const int rows2 = args.at(2), cols2 = args.at(3);

                M[0] = inputMatrix<T>(rows, cols);

                M[1] = inputMatrix<T>(rows2, cols2);

                cout << "Macierz 1:\n";
                showMatrix(M[0], rows, cols);
                cout << '\n';

                cout << "Macierz 2:\n";
                showMatrix(M[1], rows2, cols2);
                cout << '\n';

                try {

                    T **out = multiplyMatrix(M[0], M[1], rows, cols, cols2);

                    cout << "Macierz wynikowa:\n";
                    showMatrix(out, rows, cols2);

                    deallocMatrix(out, rows);

                }catch(const string& error) {

                    cout << error << endl;

                }

            }

            break;

        case Operation::MULTIPLYSCALAR:

            {
                T **out = multiplyByScalar(M[0], rows, cols, args.at(2));

                cout << "Macierz wynikowa:\n";
                showMatrix(out, rows, cols);

                deallocMatrix(out, rows);
            }

            break;

        case Operation::TRANSPOZE:

            {
                T **out = transpozeMatrix(M[0], rows, cols);

                cout << "Macierz wynikowa:\n";
                showMatrix(out, rows, cols);

                deallocMatrix(out, rows);
            }

            break;

        case Operation::POWER:

            {
                T **out = powerMatrix(M[0], rows, cols, args.at(2));

                cout << "Macierz wynikowa:\n";
                showMatrix(out, rows, cols);

                deallocMatrix(out, rows);
            }

            break;

        case Operation::DETERMINANT:

            {
                cout << "Wyznacznik macierzy: " << determinantMatrix(M[0], rows, cols) << endl;
            }

            break;

        case Operation::DIAGONAL:

            {
                cout << (matrixIsDiagonal(M[0], rows, cols) ? "Jest " : "Nie jest ") << "diagonalna." << endl;
            }

            break;

        case Operation::SORTROW:

            {
                sortRow(M[0][(int)args.at(2)], cols);

                cout << "Macierz wynikowa:\n";
                showMatrix(M[0], rows, cols);
            }

            break;

        case Operation::SORTROWS:

            {
                sortRowsInMatrix(M[0], rows, cols);

                cout << "Macierz wynikowa:\n";
                showMatrix(M[0], rows, cols);
            }

            break;

    }

    for(int i = 0; i < n; i++)
        deallocMatrix(M[i], args.at(0));
    
    delete[] M;

}

void validate_args(int argc, char** argv) {

    if(argc < 3 || argc > 7) show_error(Reason::BADARGNUM);

    switch(get_type(string{argv[1]})) {

        case Type::INT:
            operation<int>(argc, argv);
            break;

        case Type::DOUBLE:
            operation<double>(argc, argv);
            break;

    }

}

int main(int argc, char **argv) {

    if(argc == 2) {

        if(string(argv[1]) == "help")
            show_help();
        else
            show_error(Reason::BADARG);

    }else {

        validate_args(argc, argv);

    }

    return 0;

}