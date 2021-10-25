#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

struct samochod {
    string marka;
    string model;
    int moc;
    int rok_produkcji;
    string kolor;
};

struct len {
    int marka;
    int model;
    int moc;
    int kolor;
};

int int_len(int x) {

    return log10(x) + 1;

}

len max_len(samochod s[], int n) {

    len l = {0, 0, 0, 0};
    int len;

    for(int i = 0; i < n; i++) {
        
        if((len = s[i].marka.size()) >= l.marka) l.marka = len + 1;
        if((len = s[i].model.size()) >= l.model) l.model = len + 1;
        if((len = int_len(s[i].moc)) >= l.moc)   l.moc = len + 1;
        if((len = s[i].kolor.size()) >= l.kolor) l.kolor = len + 1;

    }

    return l;

}

void wyswietl(samochod *samochody, int n) {

    len l = max_len(samochody, n);

    cout << left << setw(l.marka) << "Marka" << '|' << left << setw(l.model) << "Model" << '|' << left << setw(l.moc + 2) << "Moc" << '|' << left << setw(5) << "Rok" << '|' << left << setw(l.kolor) << "Kolor" << '\n';

    for(int i = 0; i < n; i++) {

        cout << left << setw(l.marka) << samochody[i].marka << '|' << left << setw(l.model) << samochody[i].model << '|' << left << setw(l.moc) << samochody[i].moc << "KM|" << left << setw(5) << samochody[i].rok_produkcji << '|' << left << setw(l.kolor) << samochody[i].kolor << '\n';

    }

}

map<string, int> zlicz_marka(samochod samochody[], int n) {

    map<string, int> ilosc;

    for(int i = 0; i < n; i++) {

        if(ilosc.find(samochody[i].marka) != ilosc.end()) {

            ilosc[samochody[i].marka]++;

        }else {

            ilosc[samochody[i].marka] = 1;

        }

    }

    return ilosc;

}

int main() {

    samochod samochody[] = {{"audi", "rs4", 380, 2000, "bialy"},
                            {"audi", "q3", 380, 2022, "bialy"},
                            {"audi", "q5", 380, 2022, "bialy"},
                            {"volkswagen", "golf mk2", 89, 1990, "czarny"},
                            {"porsche", "918 spyder", 875, 2015, "srebrny"},
                            {"fiat", "126p", 23, 1975, "czerwony"}};

    int n = sizeof(samochody) / sizeof(samochod);

    wyswietl(samochody, n);

    cout << "\nSamochody z ta sama marka\n";

    map<string, int> ilosc = zlicz_marka(samochody, n);

    for(auto iter = ilosc.begin(); iter != ilosc.end(); iter++) {

        cout << iter->first << " -> " << iter->second << '\n';

    }

    return 0;

}
