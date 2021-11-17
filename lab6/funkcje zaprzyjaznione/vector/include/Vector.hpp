#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
    private:
        double x, y;
        
    public:
        Vector();
        Vector(double x, double y);
        double length() const;
        void print() const;
        Vector opposite() const;
        Vector operator!() const;
        Vector operator+(const Vector &rhs) const;
        Vector& operator+=(const Vector &rhs);
        Vector operator-(const Vector &rhs) const;
        Vector& operator-=(const Vector &rhs);
        double operator*(const Vector &rhs) const;
        Vector operator*(const double &rhs) const;
        Vector& operator*=(const double &rhs);
        bool operator==(const Vector &rhs);
        bool operator!=(const Vector &rhs);
        friend Vector operator*(const double &lhs, const Vector &rhs);
        friend std::ostream& operator<<(std::ostream &out, const Vector &rhs);
};

Vector operator*(const double &lhs, const Vector &rhs);

#endif // VECTOR_HPP