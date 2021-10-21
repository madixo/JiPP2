#include <iostream>
#include <random>
using namespace std;

// Zadanie 1
float srednia(int *a, int *b) {

    return (*a + *b) / 2.;

}

void show(int tab[], int n, bool (*condition)(int)) {

    cout << '[';

    for(int i = 0; i < n; i++) if(condition(tab[i])) cout << tab[i] << ", ";

    cout << "\b\b]\n";

}

// Zadanie 3
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

}

void sort(int *a, int *b, int *c) {

    if(*c > *b) swap(b, c);

    if(*b > *a) swap(a, b);

    if(*c > *b) swap(b, c);

}

// Zadanie 4
void insert(int x, int *w) {

    *w = x;

}

int main() {

    // Zadanie 1
    int a, b;

    cout << "Podaj dwie liczby: ";

    cin >> a >> b;

    cout << "Srednia " << a << " i " << b << " = " << srednia(&a, &b) << '\n';

    // Zadanie 2
    int n;

    cout << "Podaj liczbe elementow tablicy: ";

    cin >> n;

    int *tab = new int[n];

    cout << "Podaj elementy tablicy: ";

    for(int i = 0; i < n; i++) cin >> tab[i];

    cout << "Elementy tablicy wieksze od 0: ";

    show(tab, n, [](int a) {return a > 0;});

    delete[] tab;

    // Zadanie 3
    int c;

    cout << "Podaj 3 liczby: ";

    cin >> a >> b >> c;

    sort(&a, &b, &c);

    cout << "Posortowane: " << a << ", " << b << ", " << c << '\n';

    // Zadanie 4
    a = b = 0;

    cout << "Podaj liczbe: ";

    cin >> a;

    cout << "Wartosc poczatkowa b = " << b << '\n';

    insert(a, &b);

    cout << "Po wstawieniu, wartosc b = " << b << '\n';

    return 0;

}
