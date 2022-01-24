#include <iostream>
using namespace std;

template<typename T>
class Shared {

    private:

        int* i = nullptr;
        T* ptr = nullptr;
    
    public:

        Shared() = delete;

        Shared(T* ptr) : ptr(ptr) {

            i = new int(1);

        }

        Shared(Shared& s) : i(s.i), ptr(s.ptr) {

            (*i)++;

        }

        ~Shared() {

            if(--(*i) == 0) {

                delete ptr;
                delete i;

            }

        }

        int count() {

            return *i;

        }

        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }

        void operator=(const T& val) { *ptr = val; };

};

int main() {

    Shared<int> s(new int(5));

    {
        Shared<int> s1 = s;
        cout << "s count " << s.count() << endl;
        cout << "s1 count " << s1.count() << endl;

        s = 52;

        cout << "s val " << *s << endl;
        cout << "s1 val " << *s1 << endl;

    }

    return 0;

}