#include <iostream>
#include "lista.hpp"
using namespace std;

int main() {

    Lista<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    cout << l.pop_front();

    return 0;

}