#include <iostream>
#include <cmath>
using namespace std;

// Obliczanie dlugosci przekatnej trojkata
float pitagoras(float a, float b) {
    
    return sqrt(a * a + b * b);
    
}

int main(int argc, char ** args) {
    
    float a, b;
    
    cout << "Podaj dlugosci bokow a i b trojkata prostokatnego: ";
    cin >> a >> b;
    
    // Sprawdzenie czy dlugosci sa odpowiednie    
    if(a <= 0 || b <= 0) {
        
        cout << "Dlugosci bokow nie moga byc mniejsze lub rowne zeru!\n";
        return -1;
        
    }else {
        
        cout << "Dlugosc c trojkata: " << pitagoras(a, b) << endl;
        
    }
    
    return 0;    
    
}
