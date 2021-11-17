#include <iostream>
using namespace std;

int main() {

    int a = 5;
    int b = 6;
    int *const p = &a;

    *p = 555;

    p = &b;

    return 0;

}