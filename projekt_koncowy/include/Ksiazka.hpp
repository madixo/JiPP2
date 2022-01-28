#ifndef KSIAZKA_HPP
#define KSIAZKA_HPP

#include "Data.hpp"

#include <string>

class Ksiazka {

    private:
        int id;
        std::string nazwa;
        std::string autor;
        Data data_wydania;

    public:
        Ksiazka() = delete;
        Ksiazka(int id, std::string nazwa, std::string autor, Data data_wydania);
        Ksiazka(std::string nazwa, std::string autor, Data data_wydania);

        const int& getId() const;
        const std::string& getNazwa() const;
        const std::string& getAutor() const;
        const Data& getDataWydania() const;

};

#endif // KSIAZKA_HPP