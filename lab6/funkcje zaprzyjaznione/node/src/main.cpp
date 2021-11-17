#include <iostream>
#include "Node.hpp"
using namespace std;

int main() {

    Node n1(2, 10), n2(2, -5);

    cout << pointsDistance(n1, n2);

    return 0;

}