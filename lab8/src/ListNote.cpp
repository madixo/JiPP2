#include "ListNote.hpp"

ListNote::ListNote() {}

ListNote::ListNote(const std::string &title, const std::string &content) : Note(title) {
    
    setContent(content);

}

ListNote::ListNote(const std::string &title, const std::vector<std::string> &content) : Note(title), content(content) {}

ListNote::~ListNote() {}

std::string ListNote::getContent() const {
    
    std::string out;

    for(std::string s : content) {

        out += (s + '\n');
    }

    return out;

}

std::string ListNote::getContent(const int &i) const {

    if(i < 0 || i >= content.size()) return "";

    return content[i];

}

void ListNote::setContent(const std::string &content) {
    
    if(!this->content.empty()) return;

    this->content.push_back(content);

}

void ListNote::setContent(const std::string &content, const int &i) {
    
    size_t size = content.size();

    if(i == size) {

        this->content.push_back(content);

    }else if(i >= 0 && i < size) {

        this->content[i] = content;

    }

}