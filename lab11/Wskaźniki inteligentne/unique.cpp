#include <iostream>
using namespace std;

template <typename T>
class Unique {

    private:

        T* ptr;

    public:

    Unique() = delete;
    Unique(Unique& u) = delete;
    Unique(T* ptr) : ptr(ptr) {}
    ~Unique() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

};

int main() {

    Unique<int> u{new int(25)};

    Unique<int> s = u;

    cout << *u;

    return 0;

}