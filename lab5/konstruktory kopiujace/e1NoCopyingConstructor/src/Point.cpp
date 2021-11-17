//
// Created by filip on 07.11.2021.
//

#include "Point.h"

Point::Point(double x, double y, string name) : name(name) {
    *this->x = x;
    *this->y = y;
}

Point::Point(string name) : name(name) {
    *x = *y = 0;
}

// Dominik
Point::Point(const Point &p) : name(p.getName()) {
    *this->x = *p.x;
    *this->y = *p.y;
}

// Dominik
Point::~Point() {
    delete x;
    delete y;
}

double Point::getX() {
    return *x;
}

void Point::setX(double x) {
    *this->x = x;
}

double Point::getY() {
    return *y;
}

void Point::setY(double y) {
    *this->y = y;
}

void Point::printData() const {
    cout << "Point " << name << " (x = " << *x << ", y = " << *y << ")\n";
}

void Point::setName(string name) {
    this->name = name;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           name == rhs.name;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

// Dominik
Point Point::operator+=(const Point &rhs) const {
    *this->x += *rhs.x;
    *this->y += *rhs.y;
    return *this;
}

// Dominik
Point Point::operator+=(const double &rhs) const {
    *this->x += rhs;
    *this->y += rhs;
    return *this;
}

const string &Point::getName() const {
    return name;
}