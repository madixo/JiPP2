#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>
#include <vector>

class Note {

    private:
        std::string title;

    public:
        Note();
        Note(const std::string &title);
        ~Note();
        std::string getTitle() const;
        void setTitle(const std::string &title);
        virtual std::string getContent() const = 0;
        virtual void setContent(const std::string &content) = 0;


};

#endif // NOTE_HPP