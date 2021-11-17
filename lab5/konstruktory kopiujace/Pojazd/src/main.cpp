#include <iostream>
using namespace std;

#include "Pojazd.hpp"

int main() {

    Pojazd p("KR 52042", "A5", 5, "Audi", "Osobowy");

    p.zmien_pasazera(0, {"Adam", "Slodowy"});

    p.wyswietl();

    return 0;

}