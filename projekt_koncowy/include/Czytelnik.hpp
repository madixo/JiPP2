#ifndef KLIENT_HPP
#define KLIENT_HPP

#include <string>

class Czytelnik {

    private:
        int id;
        std::string imie;
        std::string nazwisko;
        std::string adres_zamieszkania;
        int nr_telefonu;

    public:
        Czytelnik() = delete;
        Czytelnik(const std::string& imie, const std::string& nazwisko, const std::string& adres_zamieszkania, const int& nr_telefonu);
        Czytelnik(const int& id, const std::string& imie, const std::string& nazwisko, const std::string& adres_zamieszkania, const int& nr_telefonu);

        const int& getId() const;
        const std::string& getImie() const;
        const std::string& getNazwisko() const;
        const std::string& getAdresZamieszkania() const;
        const int& getNrTelefonu() const;

};

#endif // KLIENT_HPP