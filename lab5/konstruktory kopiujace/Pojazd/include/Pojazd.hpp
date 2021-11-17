#ifndef POJAZD_HPP
#define POJAZD_HPP

#include <string>

struct Pasazer {
    std::string imie;
    std::string nazwisko;
};

class Pojazd {

    private:
        std::string numer_rejestracyjny;
        std::string nazwa;
        int ilosc_miejsc;
        Pasazer *pasazerowie;
        std::string marka;
        std::string typ;

    public:
        Pojazd(std::string numer_rejestracyjny, std::string nazwa, int ilosc_miejsc, std::string marka, std::string typ);
        Pojazd(Pojazd &pojazd);
        ~Pojazd();
        void wyswietl();
        void zmien_pasazera(int miejsce, Pasazer pasazer);
        std::string getNumerRejestracyjny();
        void setNumerRejestracyjny(std::string numer_rejestracyjny);
        std::string getNazwa();
        void setNazwa(std::string nazwa);
        std::string getMarka();
        std::string getTyp();

};

#endif // POJAZD_HPP