#include <iostream>
using namespace std;

class Figure {

    private:
        string nazwa;
        string kolor;

    public:
        Figure(string nazwa, string kolor) : nazwa(nazwa), kolor(kolor) {}

};

class Triangle : public Figure {

    private:
        double a, b, c, h;

    public:
        Triangle(string nazwa, string kolor, double a, double b, double c, double h) : Figure(nazwa, kolor), a(a), b(b), c(c), h(h) {}

        double pole() {

            return 1. / 2 * a * h;

        }

        double obwod() {

            return a + b + c;

        }

};

class Rectangle : public Figure {

    private:
        double a, b;
    
    public:
        Rectangle(string nazwa, string kolor, double a, double b) : Figure(nazwa, kolor), a(a), b(b) {}

        double pole() {

            return a * b;

        }

        double obwod() {

            return 2 * a + 2 * b;

        }

};

class Square : public Rectangle {

    public:
        Square(string nazwa, string kolor, double a) : Rectangle(nazwa, kolor, a, a) {}

};

int main() {

    Triangle t("trojkat1", "zolty", 3, 4, 5, 8);

    Rectangle r("prostokat1", "zielony", 5, 1.7);

    Square s("kwadrat1", "niebieski", 3);

    cout << "Trojkat obwod = " << t.obwod() << " pole = " << t.pole() << endl;

    cout << "Prostokat obwod = " << r.obwod() << " pole = " << r.pole() << endl;

    cout << "Kwadrat obwod = " << s.obwod() << " pole = " << s.pole() << endl;

    return 0;

}