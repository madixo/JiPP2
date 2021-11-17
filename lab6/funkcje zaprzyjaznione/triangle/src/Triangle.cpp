#include "Triangle.hpp"

Triangle::Triangle(const Node &n1, const Node &n2, const Node &n3, const std::string &name) : nodes{n1, n2, n3}, name(name) {}

void Triangle::display() const {

    std::cout << "Trojkat " << name << ":\n";
    
    for(int i = 0; i < 3; i++) {
    
        nodes[i].display();
    
    }
    
}

double Triangle::distance(const int &firstPointIndex, const int &secondPointIndex) const {
    
    return pointsDistance(nodes[firstPointIndex], nodes[secondPointIndex]);

}

void showTriangleData(Triangle triangle) {
    
    triangle.display();

}

void showTriangleData(Triangle *triangle) {
    
    triangle->display();

}

std::ostream& operator<<(std::ostream &out, const Triangle &t) {

    t.display();
    return out;

}