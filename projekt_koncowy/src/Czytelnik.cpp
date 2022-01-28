#include "Czytelnik.hpp"

Czytelnik::Czytelnik(const int& id, const std::string& imie, const std::string& nazwisko, const std::string& adres_zamieszkania, const int& nr_telefonu) :
    id(id), imie(imie), nazwisko(nazwisko), adres_zamieszkania(adres_zamieszkania), nr_telefonu(nr_telefonu) {}

Czytelnik::Czytelnik(const std::string& imie, const std::string& nazwisko, const std::string& adres_zamieszkania, const int& nr_telefonu) :
    Czytelnik(0, imie, nazwisko, adres_zamieszkania, nr_telefonu) {}

const int& Czytelnik::getId() const {
    
    return id;

}

const std::string& Czytelnik::getImie() const {
    
    return imie;

}

const std::string& Czytelnik::getNazwisko() const {
    
    return nazwisko;

}

const std::string& Czytelnik::getAdresZamieszkania() const {
    
    return adres_zamieszkania;

}

const int& Czytelnik::getNrTelefonu() const {
    
    return nr_telefonu;

}