//
// Created by filip on 11/14/21.
//

#ifndef JIPP2_NODE_HPP
#define JIPP2_NODE_HPP


class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display() const;

    void updateValue(double x, double y);

    friend double pointsDistance(Node a, Node b);
};

double pointsDistance(Node a, Node b);

#endif //JIPP2_NODE_HPP