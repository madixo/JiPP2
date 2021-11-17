#ifndef POJAZD_HPP
#define POJAZD_HPP

#include <string>

struct Pasazer {
    std::string imie;
    std::string nazwisko;
};

class Pojazd {

    private:
        static std::string najnowsza_wersja_oprogramowania;
        std::string zainstalowana_wersja_oprogramowania;
        std::string numer_rejestracyjny;
        std::string nazwa;
        int ilosc_miejsc;
        Pasazer *pasazerowie;
        std::string marka;
        std::string typ;

    public:
        Pojazd(const std::string &numer_rejestracyjny, const std::string &nazwa, const int &ilosc_miejsc, const std::string &marka, const std::string &typ);
        Pojazd(const Pojazd &pojazd);
        ~Pojazd();
        static void opublikujNoweOprogramowanie(const std::string &nowa_wersja);
        void wyswietl() const;
        void zmien_pasazera(const int &miejsce, const Pasazer &pasazer) const;
        std::string getNumerRejestracyjny() const;
        void setNumerRejestracyjny(const std::string &numer_rejestracyjny);
        std::string getNazwa() const;
        void setNazwa(const std::string &nazwa);
        std::string getMarka() const;
        std::string getTyp() const;
        void wypiszWersjeOprogramowania() const;
        void zaktualizujOprogramowanie();

};

#endif // POJAZD_HPP