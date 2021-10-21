#include <iostream>
#include <random>
using namespace std;

// Zadanie 1
int random(int min, int max) {

    static random_device dev;
    static mt19937 rng(dev());

    uniform_int_distribution<mt19937::result_type> dist(min, max);

    return dist(rng);

}

// Zadanie 2
void fill_random(int tab[], int n, int min, int max) {

    for(int i = 0; i < n; i++) {

        tab[i] = random(min, max);

    }

}

// Zadanie 3
void reverse(int tab[], int n) {

    for(int i = 0, temp; i < n / 2; i++) {
        
        temp = tab[i];
        tab[i] = tab[n - i - 1];
        tab[n - i - 1] = temp;

    }

}

void show(int tab[], int n) {

    cout << '[';

    for(int i = 0; i < n; i++) cout << tab[i] << ", ";

    cout << "\b\b]\n";

}

int main() {

    int n;

    cout << "Podaj ilosc elementow: ";

    cin >> n;

    int *tab = new int[n];

    fill_random(tab, n, 0, 100);

    show(tab, n);

    reverse(tab, n);

    show(tab, n);

    delete[] tab;

    return 0;

}
