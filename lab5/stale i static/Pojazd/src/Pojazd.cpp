#include "Pojazd.hpp"

#include <iostream>

std::string Pojazd::najnowsza_wersja_oprogramowania = "v1.0";

Pojazd::Pojazd(const std::string &numer_rejestracyjny, const std::string &nazwa, const int &ilosc_miejsc, const std::string &marka, const std::string &typ)
: numer_rejestracyjny(numer_rejestracyjny), nazwa(nazwa), ilosc_miejsc(ilosc_miejsc), marka(marka), typ(typ), zainstalowana_wersja_oprogramowania(najnowsza_wersja_oprogramowania) {
    
    pasazerowie = new Pasazer[ilosc_miejsc];

}

Pojazd::Pojazd(const Pojazd &pojazd) {

    numer_rejestracyjny = pojazd.numer_rejestracyjny;
    nazwa = pojazd.nazwa;
    ilosc_miejsc = pojazd.ilosc_miejsc;
    pasazerowie = new Pasazer[ilosc_miejsc];
    marka = pojazd.marka;
    typ = pojazd.typ;
    zainstalowana_wersja_oprogramowania = pojazd.zainstalowana_wersja_oprogramowania;

}

Pojazd::~Pojazd() {
    
    delete[] pasazerowie;

}

void Pojazd::opublikujNoweOprogramowanie(const std::string &nowa_wersja) {

    najnowsza_wersja_oprogramowania = nowa_wersja;

}

void Pojazd::wyswietl() const {
    
    std::cout << "Pojazd {\nnumer_rejestracyjny=" << numer_rejestracyjny << ",\nnazwa=" << nazwa << ",\nilosc_miejsc=" << ilosc_miejsc << ",\nmiejsca=[\n";

    Pasazer *p;
    for(int i = 0; i < ilosc_miejsc; i++) {

        p = pasazerowie + i;

        if(!p->imie.empty())
            std::cout << "\tPasazer{\n\timie=" << p->imie << ",\n\tnazwisko=" << p->nazwisko << "\n\t},\n";
        else
            std::cout << "\tpuste,\n";

    }

    std::cout << "\b\b ],\nmarka=" << marka << ",\ntyp=" << typ << "\n}" << std::endl;

}

void Pojazd::zmien_pasazera(const int &miejsce, const Pasazer &pasazer) const {
    
    pasazerowie[miejsce] = pasazer;

}

std::string Pojazd::getNumerRejestracyjny() const {
    
    return numer_rejestracyjny;

}

void Pojazd::setNumerRejestracyjny(const std::string &numer_rejestracyjny) {
    
    this->numer_rejestracyjny = numer_rejestracyjny;

}

std::string Pojazd::getNazwa() const {
    
    return nazwa;

}

void Pojazd::setNazwa(const std::string &nazwa) {
    
    this->nazwa = nazwa;

}

std::string Pojazd::getMarka() const {
    
    return marka;

}

std::string Pojazd::getTyp() const {
    
    return typ;

}

void Pojazd::wypiszWersjeOprogramowania() const {
    
    std::cout << "Wersja oprogramowania: " << zainstalowana_wersja_oprogramowania << std::endl;

}

void Pojazd::zaktualizujOprogramowanie() {

    zainstalowana_wersja_oprogramowania = najnowsza_wersja_oprogramowania;

}