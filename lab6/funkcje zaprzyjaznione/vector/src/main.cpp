#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {

    Vector v(5, 4);

    cout << v * 5 << endl;
    
    cout << 5 * v << endl;

    return 0;

}