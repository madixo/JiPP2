#include "TextNote.hpp"

TextNote::TextNote() {}

TextNote::TextNote(const std::string &title, const std::string &content) : Note(title), content(content) {}

TextNote::~TextNote() {}

std::string TextNote::getContent() const {
    
    return content;

}

void TextNote::setContent(const std::string &content) {
    
    this->content = content;

}