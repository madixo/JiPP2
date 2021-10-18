#include <iostream>
#include <random>
using namespace std;

int random(int min, int max) {

    static random_device dev;
    static mt19937 rng(dev());

    uniform_int_distribution<mt19937::result_type> dist(min, max);

    return dist(rng);

}

void fill_random(int tab[], int n, int min, int max) {

    for(int i = 0; i < n; i++) {

        tab[i] = random(min, max);

    }

}

int main() {

    int n;

    cout << "Podaj ilosc elementow: ";

    cin >> n;

    int *tab = new int[n];

    fill_random(tab, n, 0, 100);

    cout << '[';

    for(int i = 0; i < n; i++) {

	cout << tab[i] << ", ";

    }

    cout << "\b\b]\n";

    delete[] tab;

    return 0;

}
