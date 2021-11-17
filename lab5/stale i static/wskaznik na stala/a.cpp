#include <iostream>
using namespace std;

int main() {

    int a = 5;
    int b = 6;
    const int *p;

    *p = 555;

    p = &b;

    return 0;

}