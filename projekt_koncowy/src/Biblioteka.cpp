#include "Biblioteka.hpp"

#include <iostream>

Biblioteka::Biblioteka() : db("biblioteka.db3", SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE) {

    try {

        db.exec("CREATE TABLE IF NOT EXISTS Czytelnicy("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "imie TEXT NOT NULL,"
            "nazwisko TEXT NOT NULL,"
            "adres_zamieszkania TEXT NOT NULL,"
            "nr_telefonu INTEGER NOT NULL"
        ")");

        db.exec("CREATE TABLE IF NOT EXISTS Ksiazki("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "nazwa TEXT NOT NULL,"
            "autor TEXT NOT NULL,"
            "rok_wydania INTEGER NOT NULL"
        ")");

        db.exec("CREATE TABLE IF NOT EXISTS Wypozyczenia("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "klient INTEGER NOT NULL REFERENCES Klienci,"
            "ksiazka INTEGER NOT NULL REFERENCES Ksiazki,"
            "data_wypozyczenia TEXT NOT NULL,"
            "data_zwrotu TEXT"
        ")");

    }catch(const SQLite::Exception& e) {

        std::cerr << e.what() << std::endl;

    }

}

bool Biblioteka::dodaj_czytelnika(const Czytelnik& czytelnik) {
    
    SQLite::Statement stmt(db, "INSERT INTO Czytelnicy(imie, nazwisko, adres_zamieszkania, nr_telefonu)"
        "VALUES (:imie, :nazwisko, :adres_zamieszkania, :nr_telefonu)"
    ")");

    stmt.bind(":imie", czytelnik.getImie());
    stmt.bind(":nazwisko", czytelnik.getNazwisko());
    stmt.bind(":adres_zamieszkania", czytelnik.getAdresZamieszkania());
    stmt.bind(":nr_telefonu", czytelnik.getNrTelefonu());

    try {

        stmt.exec();

    }catch(const SQLite::Exception& e) {

        std::cerr << e.what() << std::endl;

        return false;

    }

    return true;

}

Czytelnik Biblioteka::znajdz_czytelnika(const int& id) {
    
    SQLite::Statement stmt(db, "SELECT * FROM Czytelnicy WHERE id = :id");

    stmt.bind(":id", id);

    try {

        stmt.executeStep()


    }

}