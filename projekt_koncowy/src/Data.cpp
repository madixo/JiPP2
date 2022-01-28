#include "Data.hpp"

#include <sstream>

Data::Data(short rok, char miesiac, char dzien) :
    rok(rok), miesiac(miesiac), dzien(dzien) {}

const short& Data::getRok() const {

    return rok;

}

const char& Data::getMiesiac() const {
    
    return miesiac;

}

const char& Data::getDzien() const {
    
    return dzien;

}

const std::string Data::to_string() const {

    std::ostringstream oss;
    
    oss << rok << '-' << miesiac << '-' << dzien;

    return oss.str();

}