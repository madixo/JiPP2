#include <iostream>
#include <cmath>
using namespace std;

class Zespolona {

    private:
        double r;
        double im;

    public:
        struct Urojona {
            double im;
            Urojona(const double &im) : im(im) {}
        };

        static double Re(const Zespolona &z) {

            return z.r;

        }

        static double Im(const Zespolona &z) {

            return z.im;

        }

        Zespolona(const double &real, const double &imaginary) : r(real), im(imaginary) {};

        Zespolona operator!() const {

            return {r, -im};

        }

        Zespolona operator+(const double &rhs) const {

            return {r + rhs, im};

        }

        Zespolona& operator+=(const double &rhs) {

            r += rhs;
            return *this;

        }

        Zespolona operator+(const Urojona &rhs) const {

            return {r, im + rhs.im};

        }

        Zespolona& operator+=(const Urojona &rhs) {

            im += rhs.im;
            return *this;

        }

        Zespolona operator+(const Zespolona &rhs) const {

            return {r + rhs.r, im + rhs.im};

        }

        Zespolona& operator+=(const Zespolona &rhs) {

            r += rhs.r;
            im += rhs.im;
            return *this;

        }

        Zespolona operator-(const double &rhs) const {

            return {r - rhs, im};

        }

        Zespolona& operator-=(const double &rhs) {

            r -= rhs;
            return *this;

        }

        Zespolona operator-(const Urojona &rhs) const {

            return {r, im - rhs.im};

        }

        Zespolona& operator-=(const Urojona &rhs) {

            im -= rhs.im;
            return *this;

        }

        Zespolona operator-(const Zespolona &rhs) const {

            return {r - rhs.r, im - rhs.im};

        }

        Zespolona& operator-=(const Zespolona &rhs) {

            r -= rhs.r;
            im -= rhs.im;
            return *this;

        }

        Zespolona operator*(const double &rhs) const {

            return {r * rhs, im * rhs};

        }

        Zespolona& operator*=(const double &rhs) {

            return *this = *this * rhs;

        }

        Zespolona operator*(const Urojona &rhs) const {

            return {-im * rhs.im, r * rhs.im};

        }

        Zespolona& operator*=(const Urojona &rhs) {

            return *this = *this * rhs;

        }

        Zespolona operator*(const Zespolona &rhs) const {

            return {r * rhs.r - im * rhs.im, r * rhs.im + im * rhs.r};

        }

        Zespolona& operator*=(const Zespolona &rhs) {

            return *this = *this * rhs;

        }

        Zespolona operator/(const double &rhs) const {

            return {r / rhs, im / rhs};

        }

        Zespolona operator/=(const double &rhs) {

            return *this = *this / rhs;

        }

        Zespolona operator/(const Urojona &rhs) const {

            return {im / rhs.im, -r / rhs.im};

        }

        Zespolona& operator/=(const Urojona &rhs) {

            return *this = *this / rhs;

        }

        Zespolona operator/(const Zespolona &rhs) const {

            const double dzielnik = rhs.r * rhs.r + rhs.im * rhs.im;
            return {(r * rhs.r + im * rhs.im) / dzielnik, (im * rhs.r - r * rhs.im) / dzielnik};

        }

        Zespolona& operator/=(const Zespolona &rhs) {

            return *this = *this / rhs;

        }

        bool operator==(const Zespolona &rhs) const {

            return r == rhs.r && im == rhs.im;

        }

        bool operator!=(const Zespolona &rhs) const {

            return !(*this == rhs);

        }

        friend Zespolona operator+(const double &a, const Zespolona &z);
        friend Zespolona operator+(const Urojona &im, const Zespolona &z);
        friend Zespolona operator-(const double &a, const Zespolona &z);
        friend Zespolona operator-(const Urojona &im, const Zespolona &z);
        friend Zespolona operator*(const double &a, const Zespolona &z);
        friend Zespolona operator*(const Urojona &im, const Zespolona &z);
        friend Zespolona operator/(const double &a, const Zespolona &z);
        friend Zespolona operator/(const Urojona &im, const Zespolona &z);

};

Zespolona operator+(const double &a, const Zespolona &z) {

    return z + a;

}

Zespolona operator+(const Zespolona::Urojona &im, const Zespolona &z) {
    
    return z + im;
    
}

Zespolona operator-(const double &a, const Zespolona &z) {

    return z - a;

}

Zespolona operator-(const Zespolona::Urojona &im, const Zespolona &z) {

    return z - im;

}

Zespolona operator*(const double &a, const Zespolona &z) {

    return z * a;

}

Zespolona operator*(const Zespolona::Urojona &im, const Zespolona &z) {

    return z * im;

}

Zespolona operator/(const double &a, const Zespolona &z) {

    if(a == 0) return {0, 0};
    else if(a != 1) return a * (1 / z);

    const double dzielnik = z.r * z.r + z.im * z.im;
    return {z.r / dzielnik, -z.im / dzielnik};

}

Zespolona operator/(const Zespolona::Urojona &im, const Zespolona &z) {

    if(im.im == 0) return {0, 0};

    const double dzielnik = z.r * z.r + z.im * z.im;
    return {(z.im * im.im) / dzielnik, (z.r * im.im) / dzielnik};

}

ostream& operator<<(ostream& out, const Zespolona &z) {

    out << "(" << Zespolona::Re(z) << ", " << Zespolona::Im(z) << ")";
    return out;

}

int main() {

    Zespolona z1(5, 2), z2(3, 7);

    cout << !z1;

    return 0;

}