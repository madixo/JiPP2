#include "lib.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool err;

enum class Reason {

    BADARGNUM,
    BADARG,
    BADOPERATION,
    BADTYPE

};

enum class Type {

    INT,
    DOUBLE

};

enum class OperationType {

    DUMMY,
    ALLOC,
    DEALLOC,
    IDENTITY,
    SHOW,
    INPUT,
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

unordered_map<string, OperationType> str_ops{
    {"add", OperationType::ADD},
    {"subtract", OperationType::SUBTRACT},
    {"multiply", OperationType::MULTIPLY},
    {"multiplyscalar", OperationType::MULTIPLYSCALAR},
    {"transpoze", OperationType::TRANSPOZE},
    {"power", OperationType::POWER},
    {"determinant", OperationType::DETERMINANT},
    {"diagonal", OperationType::DIAGONAL},
    {"sortrow", OperationType::SORTROW},
    {"sortrows", OperationType::SORTROWS}
};

unordered_map<OperationType, int> ops_args{
    {OperationType::ADD, 2},
    {OperationType::SUBTRACT, 2},
    {OperationType::MULTIPLY, 4},
    {OperationType::MULTIPLYSCALAR, 3},
    {OperationType::TRANSPOZE, 2},
    {OperationType::POWER, 3},
    {OperationType::DETERMINANT, 2},
    {OperationType::DIAGONAL, 2},
    {OperationType::SORTROW, 3},
    {OperationType::SORTROWS, 2}
};

enum class InputType {

    NUMBER,
    CHARACTER

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
    isDiagonal [rows] [cols]
    sortRow [rows] [cols] [row index]
    sortRows [rows] [cols]
)";

}

void show_error(Reason reason) {

    switch(reason) {

        case Reason::BADARG:
            cout << "Podano zle argumenty!\n";
            break;

        case Reason::BADARGNUM:
            cout << "Podano zla ilosc argumentow!\n";
            break;

        case Reason::BADOPERATION:
            cout << "Podano zla operacje!\n";
            break;

        case Reason::BADTYPE:
            cout << "Podano zly typ danych!\n";
            break;

    }

    cout << "Wpisz ./matrixApp help aby otrzymac pomoc!" << endl;

    exit(1);

}

template<typename T>
T& validate_user_input(T& val) {

    while(true) {

        if(cin >> val) {

            return val;

        }else {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }

    }

}

template<typename T>
T& user_input(T& val, const string& message) {

    cout << message;

    return validate_user_input(val);

}

bool check_args_num(OperationType type, int argc) {

    auto iter = ops_args.find(type);

    if(iter == ops_args.end())
        show_error(Reason::BADARGNUM);

    if(!(argc - 3 - iter->second))
        return false;

    return true;

}

vector<int> parse_args(OperationType type, int argc, char** argv) {

    if(!check_args_num(type, argc)) show_error(Reason::BADARGNUM);

    vector<int> args;
    args.resize(argc - 3);

    for(int i = 0; i < argc - 3; i++) {

        try {

            args.push_back(stoi(argv[i + 3]));

        }catch(...) {

            show_error(Reason::BADARG);

        }

    }

    return args;

}

OperationType find_operation_type(const string& operation) {

    auto iter = str_ops.find(operation);

    if(iter == str_ops.end())
        show_error(Reason::BADOPERATION);

    return iter->second;

}

void int_operation(char** argv, int argc) {

    OperationType type = find_operation_type(string{argv[2]});

    vector<int> args = parse_args(type, argc, argv);

}

void double_operation(char** argv, int argc) {

    OperationType type = find_operation_type(string{argv[2]});

    vector<int> args = parse_args(type, argc, argv);

    switch(type) {

        case OperationType::ADD:

            break;

    }

}

Type get_type(const string& type) {

    if(type == "int") {

        return Type::INT;

    }else if(type == "double") {

        return Type::DOUBLE;

    }

    show_error(Reason::BADTYPE);

}

void validate_args(const int& argc, char** argv) {

    switch(get_type(string{argv[1]})) {

        case Type::INT:
            int_operation(argv, argc);
            break;

        case Type::DOUBLE:
            double_operation(argv, argc);
            break;

    }

}

int main(int argc, char **argv) {

    if(argc == 2) {

        if(string(argv[1]) == "help")
            show_help();
        else
            show_error(Reason::BADARG);

    }else if(argc >= 5 && argc <= 7) {

        validate_args(argc, argv);

    }else {

        show_error(Reason::BADARGNUM);

    }

    if(err) return 1;

    return 0;

}