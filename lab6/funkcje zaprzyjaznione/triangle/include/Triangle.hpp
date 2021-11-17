#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>

#include "Node.hpp"

class Triangle {

    private:
        Node nodes[3];
        std::string name;
        std::string toString();

    public:
        Triangle(const Node &n1, const Node &n2, const Node &n3, const std::string &name);
        void display() const;
        double distance(const int &firstPointIndex, const int &secondPointIndex) const;

};

/**
 * 
 * Nie można przeciążać funkcji referencją
 * 
 * void showTriangleData(Triangle triangle)  - kopia oryginalnego obiektu, inny adres
 * void showTriangleData(Triangle &triangle) - przekazanie oryginalnego obiektu, ten sam adres
 * void showTriangleData(Triangle *triangle) - przekazanie wskaźnika do funkcji z adresem oryginalnego obiektu,
 *                                             wskaźnik ma inny adres
 * 
 */

void showTriangleData(Triangle triangle);
//void showTriangleData(Triangle &triangle);
void showTriangleData(Triangle *triangle);

std::ostream& operator<<(std::ostream &out, const Triangle &t);

#endif // TRIANGLE_HPP