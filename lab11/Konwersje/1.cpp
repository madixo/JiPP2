#include <iostream>
using namespace std;

int main() {

    double a;

    cout << "Podaj liczbe typu double: ";
    cin >> a;

    int b = a;

    cout << "Liczba " << a << " po zmianie na calkowita " << b << endl;

    cout << "Pole kwadratu o boku " << b << " wynosi " << b * b << endl;

    return 0;

}