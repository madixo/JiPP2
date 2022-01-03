#include <iostream>
using namespace std;

template<typename T>
class Vector {

    private:
        T *arr;
        size_t length;
        size_t current = 0;
    public:
        Vector() {
            arr = new T[1];
            arr[0] = 0;
            length = 1;
        }

        Vector(size_t size) {
            arr = new T[size];
            for(size_t i = 0; i < size; i++) arr[i] = 0;
            length = size;
        }

        ~Vector() {
            delete[] arr;
        }

        void push(T element) {
            if(current == length) {
                T *temp = new T[length];
                for(size_t i = 0; i < length; i++) temp[i] = arr[i];
                delete[] arr;
                arr = new T[++length];
                for(size_t i = 0; i < length - 1; i++) arr[i] = temp[i];
                arr[length - 1] = 0;
                delete[] temp;
            }

            arr[current++] = element;
        }

        T pop() {
            T out = arr[--current];
            arr[current] = 0;
            return out;
        }

        T* get_array() {
            return arr;
        }

};

int main() {

    Vector<int> v{5};

    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);
    v.push(6);

    cout << v.pop();

    cout << endl;

    return 0;

}