#include <iostream>
using namespace std;

int main() {

    int a = 5;
    int b = 6;
    const int *const p = &a;

    *p = 55;

    p = &b;

    return 0;

}