#include <iostream>
using namespace std;

class Figure {

    public:
        Figure() {}
        virtual double getArea() = 0;

};

class Circle : public Figure {

    private:
        double r;

    public:
        Circle(double r) : r(r) {}

        double getArea() {

            return 3.141 * r * r;

        }

};

class Rectangle : public Figure {

    private:
        double a, b;

    public:
        Rectangle(double a, double b) : a(a), b(b) {}

        double getArea() {

            return a * b;

        }

};

int main() {

    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;

    return 0;

}