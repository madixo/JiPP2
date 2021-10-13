#include <iostream>

#include "../include/calc.hpp"

using namespace std; 

void show_help() {

    cout << R"(Simple calculator
SimpleCalc [nazwa dzialania]

Dzialania:
add [a] [b]
    Dodawanie dwoch liczb ([a] i [b]) calkowitych.

subtract [a] [b]
    Odejmowanie dwoch liczb ([a] i [b]) calkowitych.

volume [a] [b] [h] [H]
    Obliczanie pola graniastroslupa prostego o podstawie trapezu,
    gdzie [a] i [b] - dlugosci podstaw,
    [h] - wysokosc podstawy, [H] - wysokosc graniastoslupa
)";

}

void bad_num_args() {

    cout << "Podano zla ilosc argumentow!\n\n";

    show_help();

}

int main(int argc, char** argv) {

    if(argc == 1) {

        show_help();

    }else {

        const string operation = argv[1];

        if(operation == "help") {

            show_help();

        }else if(operation == "add") {

            if(argc == 4) {

                cout << add(stoi(argv[2]), stoi(argv[3]));

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "subtract") {

            if(argc == 4) {

                cout << subtract(stoi(argv[2]), stoi(argv[3]));

            }else {

                bad_num_args();

                return -1;

            }

        }else if(operation == "volume") {

            if(argc == 6) {

                cout << volume(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));

            }else {

                bad_num_args();

                return -1;

            }

        }

    }

    return 0;

}