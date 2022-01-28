#ifndef BIBLIOTEKA_HPP
#define BIBLIOTEKA_HPP

#include "Czytelnik.hpp"

#include <SQLiteCpp/SQLiteCpp.h>
#include <vector>

class Biblioteka {

    private:
        SQLite::Database db;

    public:
        Biblioteka();

        bool dodaj_czytelnika(const Czytelnik& czytelnik);
        Czytelnik znajdz_czytelnika(const int& id);
        Czytelnik znajdz_czytelnika(std::string imie, std::string nazwisko);
        std::vector<Czytelnik> wszyscy_czytelnicy();

};

#endif // BIBLIOTEKA_HPP