#include <iostream>
using namespace std;

#include "Pojazd.hpp"

int main() {

    Pojazd p("KR 52042", "A5", 5, "Audi", "Osobowy");

    p.wypiszWersjeOprogramowania();

    cout << "Zmiana najnowszego oprogramowania do v1.1" << endl;
    Pojazd::opublikujNoweOprogramowanie("v1.1");

    cout << "Przed zaktualizowaniem oprogramowania" << endl;
    p.wypiszWersjeOprogramowania();

    p.zaktualizujOprogramowanie();

    cout << "Po zaktualizowaniu oprogramowania" << endl;
    p.wypiszWersjeOprogramowania();

    return 0;

}