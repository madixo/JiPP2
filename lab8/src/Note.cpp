#include "Note.hpp"

Note::Note() {}

Note::Note(const std::string &title) : title(title) {}

Note::~Note() {}

std::string Note::getTitle() const {
    
    return title;

}

void Note::setTitle(const std::string &title) {
    
    this-> title = title;

}