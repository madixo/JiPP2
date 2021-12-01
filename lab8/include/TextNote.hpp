#ifndef TEXTNOTE_HPP
#define TEXTNOTE_HPP

#include "Note.hpp"
#include <string>

class TextNote : public Note {

    private:
        std::string content;

    public:
        TextNote();
        TextNote(const std::string &title, const std::string &content);
        ~TextNote();
        std::string getContent() const;
        void setContent(const std::string &content);

};

#endif // TEXTNOTE_HPP