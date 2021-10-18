#include <iostream>
#include <random>
using namespace std;

int random(int a, int b) {

    static random_device dev;
    static mt19937 rng(dev());

    uniform_int_distribution<mt19937::result_type> dist(a, b);

    return dist(rng);

}

int main() {

    int a = 5, b = 10;

    cout << random( 1, 10);

    return 0;

}
