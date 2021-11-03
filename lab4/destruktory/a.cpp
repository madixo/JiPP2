#include <iostream>
using namespace std;

class Klasa {
    
    private:
        double *arr;

    public:
        Klasa() {

            cout << "Konstruktor wywolany!" << endl;

            arr = new double[1024];
        
        }

        ~Klasa() {

            cout << "Destruktor wywolany!" << endl;

            delete[] arr;

        }

};

int main() {

    Klasa *k = new Klasa();

    cin.get();

    delete k;    

    cin.get();

    return 0;

}