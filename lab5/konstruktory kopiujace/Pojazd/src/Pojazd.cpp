#include "Pojazd.hpp"

#include <iostream>

Pojazd::Pojazd(std::string numer_rejestracyjny, std::string nazwa, int ilosc_miejsc, std::string marka, std::string typ)
: numer_rejestracyjny(numer_rejestracyjny), nazwa(nazwa), ilosc_miejsc(ilosc_miejsc), marka(marka), typ(typ) {
    
    pasazerowie = new Pasazer[ilosc_miejsc];

}

Pojazd::Pojazd(Pojazd &pojazd) {

    numer_rejestracyjny = pojazd.numer_rejestracyjny;
    nazwa = pojazd.nazwa;
    ilosc_miejsc = pojazd.ilosc_miejsc;
    pasazerowie = new Pasazer[ilosc_miejsc];
    marka = pojazd.marka;
    typ = pojazd.typ;

}

Pojazd::~Pojazd() {
    
    delete[] pasazerowie;

}

void Pojazd::wyswietl() {
    
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

void Pojazd::zmien_pasazera(int miejsce, Pasazer pasazer) {
    
    pasazerowie[miejsce] = pasazer;

}

std::string Pojazd::getNumerRejestracyjny() {
    
    return numer_rejestracyjny;

}

void Pojazd::setNumerRejestracyjny(std::string numer_rejestracyjny) {
    
    this->numer_rejestracyjny = numer_rejestracyjny;

}

std::string Pojazd::getNazwa() {
    
    return nazwa;

}

void Pojazd::setNazwa(std::string nazwa) {
    
    this->nazwa = nazwa;

}

std::string Pojazd::getMarka() {
    
    return marka;

}

std::string Pojazd::getTyp() {
    
    return typ;

}