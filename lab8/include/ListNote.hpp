#ifndef LISTNOTE_HPP
#define LISTNOTE_HPP

#include "TextNote.hpp"

#include <vector>

class ListNote : public Note {

    private:
        std::vector<std::string> content;

    public:
        ListNote();
        ListNote(const std::string &title, const std::string &content);
        ListNote(const std::string &title, const std::vector<std::string> &content);
        ~ListNote();
        std::string getContent() const;
        std::string getContent(const int &i) const;
        void setContent(const std::string &content);
        void setContent(const std::string &content, const int &i);

};

#endif // LISTNOTE_HPP