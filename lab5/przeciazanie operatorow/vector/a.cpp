#include <iostream>
#include <cmath>
using namespace std;

class Vector {
    private:
        double x, y;
        
    public:
        Vector() {};
        
        Vector(double x, double y) : x(x), y(y) {}
        
        double length() const {

            return sqrt(x * x + y * y);

        }
        
        void print() const {

            cout << "{x = " << x << ", y = " << y << "}";

        }

        Vector opposite() const {

            return {-x, -y};

        }

        Vector operator!() const {

            return opposite();

        }
        
        Vector operator+(const Vector &rhs) const {

            return {x + rhs.x, y + rhs.y};

        }
        
        Vector& operator+=(const Vector &rhs) {

            x += rhs.x;
            y += rhs.y;
            return *this;

        }

        Vector operator-(const Vector &rhs) const {

            return {x - rhs.x, y - rhs.y};

        }

        Vector& operator-=(const Vector &rhs) {

            x -= rhs.x;
            y -= rhs.y;
            return *this;

        }

        double operator*(const Vector &rhs) const {

            return x * rhs.x + y * rhs.y;

        }

        Vector operator*(const double &rhs) const {

            return {x * rhs, y * rhs};

        }

        Vector& operator*=(const double &rhs) {

            x *= rhs;
            y += rhs;
            return *this;

        }

        bool operator==(const Vector &rhs) {

            return x == rhs.x && y == rhs.y;

        }

        bool operator!=(const Vector &rhs) {

            return !(*this == rhs);

        }
};

ostream& operator<<(ostream &out, const Vector &rhs) {
    rhs.print();
    return out;
}

int main() {

    Vector v1(2, 6), v2(1, 7), v3(2, 6);

    cout << "Wektor przeciwny do " << v1 << " to " << !v1 << endl;

    cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;

    cout << v1 << " - " << v2 << " = " << v1 - v2 << endl;

    cout << v1 << " * " << v2 << " = " << v1 * v2 << endl;

    cout << v1 << " * " << 5 << " = " << v1 * 5 << endl;

    cout << v1 << " == " << v2 << " = " << (v1 == v2 ? "true" : "false") << endl;

    cout << v1 << " == " << v3 << " = " << (v1 == v3 ? "true" : "false") << endl;

    cout << v1 << " != " << v2 << " = " << (v1 != v2 ? "true" : "false") << endl;

    cout << v1 << " != " << v3 << " = " << (v1 != v3 ? "true" : "false") << endl;

    return 0;

}