#include <iostream>
using namespace std;

// Zadanie 1
class Prostopadloscian {

    private:
        int a, b, h;

    public:
        Prostopadloscian(int a, int b, int h) : a(a), b(b), h(h) {};

        int pole() {

            return 2 * (a * b + a * h + b * h);

        }

        int getA() {

            return a;
            
        }

        void setA(int a) {

            this->a = a;

        }

        int getB() {

            return b;

        }

        void setB(int b) {

            this->b = b;

        }

        int getH() {

            return h;

        }

        void setH(int h) {

            this->h = h;

        }

    };

    // Zadanie 2
    class Kula {

    private:
        int r;

    public:
        Kula(int r) : r(r) {};

        double objetosc() {

            return 4 / 3 * 3.141 * r * r * r;

        }

        int getR() {

            return r;

        }

        void setR(int r) {

            this->r = r;

        }

    };

// Zadanie 3
class FunkcjaKwadratowa {

    private:
        int a, b, c;

    public:
        FunkcjaKwadratowa(int a, int b, int c) : a(a), b(b), c(c) {};

        void wyswietl() {

            cout << "f(x) = " << a << " x^2 + " << b << " x + " << c << endl;

        }

        int getA() {

            return a;
            
        }

        void setA(int a) {

            this->a = a;

        }

        int getB() {

            return b;

        }

        void setB(int b) {

            this->b = b;

        }

        int getC() {

            return c;

        }

        void setC(int c) {

            this->c = c;

        }

};

// Zadanie 4
class Student {

    private:
        string imie, nazwisko;
        int numer_albumu, liczba_pytan, poprawne_odpowiedzi;

    public:
        Student(string imie, string nazwisko, int numer_albumu, int liczba_pytan, int poprawne_odpowiedzi) :
        imie(imie), nazwisko(nazwisko), numer_albumu(numer_albumu), liczba_pytan(liczba_pytan), poprawne_odpowiedzi(poprawne_odpowiedzi) {};

        static Student wczytaj() {

            string imie, nazwisko;
            int numer_albumu, liczba_pytan, poprawne_odpowiedzi;

            cout << "Podaj imie: ";
            cin >> imie;

            cout << "Podaj nazwisko: ";
            cin >> nazwisko;

            cout << "Podaj numer albumu: ";
            cin >> numer_albumu;

            cout << "Podaj liczbe pytan: ";
            cin >> liczba_pytan;

            cout << "Podaj liczbe poprawnych odpowiedz: ";
            cin >> poprawne_odpowiedzi;

            return Student(imie, nazwisko, numer_albumu, liczba_pytan, poprawne_odpowiedzi);

        }

        double procent_poprawnych_odpowiedzi() {

            return (double)poprawne_odpowiedzi / liczba_pytan;

        }

        string getImie() {

            return imie;

        }

        void setImie(string imie) {

            this->imie = imie;

        }

        string getNazwisko() {

            return nazwisko;

        }

        void setNazwisko(string nazwisko) {

            this->nazwisko = nazwisko;

        }

        int getNumerAlbumu() {

            return numer_albumu;

        }

        void setNumerAlbumu(int numer_albumu) {

            this->numer_albumu = numer_albumu;

        }

        int getLiczbaPytan() {

            return liczba_pytan;

        }

        void setLiczbaPytan(int liczba_pytan) {

            this->liczba_pytan = liczba_pytan;

        }

        int getPoprawneOdpowiedzi() {

            return poprawne_odpowiedzi;

        }

        void setPoprawneOdpowiedzi(int poprawne_odpowiedzi) {

            this->poprawne_odpowiedzi = poprawne_odpowiedzi;

        }

};

int main() {

    // Zadanie 1
    Prostopadloscian p(2, 4, 3);

    cout << "Pole prostopadloscianu o podstawie " << p.getA() << " i " << p.getB() << " oraz wysokosci " << p.getH() << " wynosi " << p.pole() << endl;

    // Zadanie 2
    Kula k(4);

    cout << "Kula o promieniu " << k.getR() << " ma objetosc wynoszaca " << k.objetosc() << endl;

    // Zadanie 3
    FunkcjaKwadratowa f(2, 5, 4);

    f.wyswietl();
    
    // Zadanie 4
    Student s = Student::wczytaj();

    cout << "Procent poprawnych odpowiedzi " << s.procent_poprawnych_odpowiedzi() << endl;

    return 0;

}