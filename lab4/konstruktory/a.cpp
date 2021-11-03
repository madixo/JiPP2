#include <iostream>
#include <initializer_list>
#include <cmath>
using namespace std;

// Zadanie 1
class Punkt {

    public:
        int x, y;
        
        Punkt() {}
        Punkt(const Punkt &p) {
            x = p.x;
            y = p.y;
        }
        Punkt(int x, int y) : x(x), y(y) {}

        double odleglosc(Punkt const &p) {

            return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));

        }

};

// Zadanie 2
class Figura {

    public:
        int n;
        Punkt *wierzcholki;

        Figura(initializer_list<Punkt> w) {

            n = w.size();

            wierzcholki = new Punkt[n];

            int i = 0;
            for(auto ptr = w.begin(); ptr != w.end() || i < n; ptr++, i++)
                wierzcholki[i] = *ptr;

        }

        void lista_wierzcholkow() {

            for(int i = 0; i < n; i++)
                cout << "(" << wierzcholki[i].x << " " << wierzcholki[i].y << "), ";

            cout << "\b\b " << endl;

        }

        ~Figura() {

            delete[] wierzcholki;

        }

};

int main() {

    // Zadanie 1
    Punkt p1(2, 4), p2(10, 23);

    cout << "Odleglosc punktu p1(" << p1.x << ", " << p1.y << ") od punktu p2(" << p2.x << ", " << p2.y << ") wynosi " << p1.odleglosc(p2) << endl;

    // Zadanie 2
    Figura f({Punkt(2, 1), Punkt(3, 2), Punkt(4, 3), Punkt(2, 3)});

    cout << "\nLista wierzcholkow figury f:\n";
    f.lista_wierzcholkow();

    return 0;

}