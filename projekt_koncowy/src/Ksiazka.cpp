#include "Ksiazka.hpp"

Ksiazka::Ksiazka(int id, std::string nazwa, std::string autor, Data data_wydania) :
    id(id), nazwa(nazwa), autor(autor), data_wydania(data_wydania) {}

Ksiazka::Ksiazka(std::string nazwa, std::string autor, Data data_wydania) :
    Ksiazka(0, nazwa, autor, data_wydania) {}

const int& Ksiazka::getId() const {

    return id;

}

const std::string& Ksiazka::getNazwa() const {
        
    return nazwa;

}

const std::string& Ksiazka::getAutor() const {
        
    return autor;

}

const Data& Ksiazka::getDataWydania() const {
        
    return data_wydania;

}