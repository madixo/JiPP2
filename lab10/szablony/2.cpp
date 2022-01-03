#include <iostream>
using namespace std;

template<typename T, size_t n>
class Array {

    private:
        T *arr;
    public:
        const size_t length = n;

        Array() {
            arr = new T[n];
        }

        ~Array() {
            delete[] arr;
        }
        
        T& operator[](size_t i) {
            return arr[i];
        }

        const size_t size() const {
            return length;
        }

};

int main() {

    Array<int, 5> a;

    a[0] = 1;

    cout << "Wielkosc tablicy: " << a.length << endl;

    cout << "Pierwszy element tablicy: " << a[0] << endl;

    return 0;

}