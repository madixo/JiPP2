#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {

    private:
        short rok;
        char miesiac;
        char dzien;

    public:
        Data() = delete;
        Data(short rok, char miesiac, char dzien);

        const short& getRok() const;
        const char& getMiesiac() const;
        const char& getDzien() const;
        const std::string to_string() const;

};

#endif // DATA_HPP