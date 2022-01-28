#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include "Data.hpp"

class Wypozyczenie {

    private:
        int id;
        int klient;
        int ksiazka;
        Data data_wypozyczenia;
        Data data_zwrotu;

};

#endif // WYPOZYCZENIE_H