#include <iostream>
#include <string>
using namespace std;

// Struktura zawierajaca informacje o pieniadzach
struct pieniadze {
    int zlotowki, grosze;
};

/** imie - imie osoby
 *  wiek - wiek osoby
 *  p    - ilosc pieniedzy
 * 
 *  funkcja wyswietla podane dane
 */
void wyswietl(string imie, int wiek, pieniadze p) {
    
    cout << "Imie: " << imie << endl;
    cout << "Wiek: " << wiek << endl;
    cout << "Pieniadze: " << p.zlotowki << "," << p.grosze << "zl" << endl;
    
}

int main(int argc, char ** args) {

    string imie;
    int wiek;
    pieniadze p;
    
    cout << "Podaj imie: ";
    cin >> imie;
    
    cout << "Podaj wiek: ";
    cin >> wiek;
    
    cout << "Podaj ilosc pieniedzy <zlotowki grosze>: ";
    cin >> p.zlotowki;
    cin >> p.grosze;
    
    wyswietl(imie, wiek, p);

}
