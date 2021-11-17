//
// Created by filip on 11/14/21.
//

#include "Node.hpp"

#include <iostream>
#include <cmath>

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    std::cout << "x: " << x << "\ty: " << y << std::endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b) {

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}