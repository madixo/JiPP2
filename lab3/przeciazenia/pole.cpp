#include <iostream>
using namespace std;

float pole(float a, float h) /* pole trojkata */ {

    return 1. / 2 * a * h;

}

int pole(int a, int b) /* pole prostokata */ {

    return a * b;

}

int pole(int a) /* pole kwadratu */ {

    return pole(a, a);

}

float pole(int a, int b, int h) /* pole trapezu */ {

    return 1. / 2 * (a + b) * h;

}

int main() {

    float a, b, h;

    cout << "Podaj bok i wysokosc trojkata: ";

    cin >> a >> h;

    cout << "Pole trojkata = " << pole(a, h) << '\n'; 

    cout << "Podaj bok kwadratu: ";

    cin >> a;

    cout << "Pole kwadratu = " << pole((int)a) << '\n'; 

    cout << "Podaj boki prostokata: ";

    cin >> a >> b;

    cout << "Pole prostokata = " << pole((int)a, (int)b) << '\n';

    cout << "Podaj boki i wysokosc trapezu: ";

    cin >> a >> b >> h;

    cout << "Pole trapezu = " << pole(a, b, h) << '\n';

    return 0;

}
