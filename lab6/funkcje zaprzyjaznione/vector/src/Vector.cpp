#include "Vector.hpp"

#include <cmath>

Vector::Vector() {};

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length() const {

    return sqrt(x * x + y * y);

}

void Vector::print() const {

    std::cout << "{x = " << x << ", y = " << y << "}" << std::endl;

}

Vector Vector::opposite() const {

    return {-x, -y};

}

Vector Vector::operator!() const {

    return opposite();

}

Vector Vector::operator+(const Vector &rhs) const {

    return {x + rhs.x, y + rhs.y};

}

Vector& Vector::operator+=(const Vector &rhs) {

    x += rhs.x;
    y += rhs.y;
    return *this;

}

Vector Vector::operator-(const Vector &rhs) const {

    return {x - rhs.x, y - rhs.y};

}

Vector& Vector::operator-=(const Vector &rhs) {

    x -= rhs.x;
    y -= rhs.y;
    return *this;

}

double Vector::operator*(const Vector &rhs) const {

    return x * rhs.x + y * rhs.y;

}

Vector Vector::operator*(const double &rhs) const {

    return {x * rhs, y * rhs};

}

Vector& Vector::operator*=(const double &rhs) {

    x *= rhs;
    y += rhs;
    return *this;

}

bool Vector::operator==(const Vector &rhs) {

    return x == rhs.x && y == rhs.y;

}

bool Vector::operator!=(const Vector &rhs) {

    return !(*this == rhs);

}

Vector operator*(const double &lhs, const Vector &rhs) {
    
    return rhs * lhs;

}

std::ostream& operator<<(std::ostream &out, const Vector &rhs) {

    out << "{x = " << rhs.x << ", y = " << rhs.y << "}";
    return out;

}