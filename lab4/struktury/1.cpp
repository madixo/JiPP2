#include <iostream>
#include <iomanip>
using namespace std;

struct samochod {
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
};

struct len {
    int marka;
    int model;
    int kolor;
};

len max_len(samochod s[], int n) {

    len l = {0, 0, 0};
    int len;

    for(int i = 0; i < n; i++) {
        
        if((len = s[i].marka.size()) >= l.marka) l.marka = len + 1;
        if((len = s[i].model.size()) >= l.model) l.model = len + 1;
        if((len = s[i].kolor.size()) >= l.kolor) l.kolor = len + 1;

    } 

    return l;

}

void wyswietl(samochod *samochody, int n) {

    len l = max_len(samochody, 4);

    cout << left << setw(l.marka) << "Marka" << "|" << left << setw(l.model) << "Model" << "|" << left << setw(5) << "Rok" << "|" << left << setw(l.kolor) << "Kolor" << '\n';

    for(int i = 0; i < n; i++) {

        cout << left << setw(l.marka) << samochody[i].marka << '|' << left << setw(l.model) << samochody[i].model << '|' << left << setw(5) << samochody[i].rok_produkcji << '|' << left << setw(l.kolor) << samochody[i].kolor << '\n';

    }

}

int main() {

    samochod samochody[4] = {{"audi", "rs4", 2000, "bialy"}, {"volkswagen", "golf mk2", 1990, "czarny"}, {"porsche", "718", 1960, "srebrny"}, {"fiat", "126p", 1975, "czerwony"}};

    wyswietl(samochody, 4);    

    return 0;

}
