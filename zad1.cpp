#include <iostream>
#include <string>
using namespace std;

 /************************************************
 *                                               *
 * Program wczytuje dane i wyswietla je na ekran *
 *                                               *
 ************************************************/

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

    // definiowanie zmiennych
    string imie;
    int wiek;
    pieniadze p;
    
    // Wczytywanie imienia
    cout << "Podaj imie: ";
    cin >> imie;
    
    // Wczytywanie wieku
    cout << "Podaj wiek: ";
    cin >> wiek;
    
    // Wczytywanie ilosci pieniedzy
    cout << "Podaj ilosc pieniedzy <zlotowki grosze>: ";
    cin >> p.zlotowki;
    cin >> p.grosze;
    
    //Wywolanie funkcji wyswietl
    wyswietl(imie, wiek, p);

}
