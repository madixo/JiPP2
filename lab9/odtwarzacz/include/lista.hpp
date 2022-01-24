#ifndef LISTA_HPP
#define LISTA_HPP

#include <iterator>

template<class T>
class Lista {

    private:

    struct Node {

        T data;
        Node *next;
        Node *prev;

        Node(const T& data, Node* const prev, Node* const next) :
        data(data), prev(prev), next(next) {}

        Node(const T& data) : Node(data, this, this) {}

    } *begin, *end;

    public:

    class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

        private:
        
        pointer ptr;

        public:

        iterator(pointer ptr) : ptr(ptr) {}

    };

    iterator begin() { return iterator(); }
    iterator end() {}

    Lista() {

        begin = nullptr;
        end = nullptr;

    }

    ~Lista() {

        Node *current = begin, *next;

        while(current != end) {

            next = current->next;

            delete current;
            
            current = next;

        }

        delete end;

    }

    void push_back(const T& data) {

        if(end == nullptr) {

            begin = end = new Node(data);

        }else {

            Node *n = new Node(data, end, begin);

            end->next = n;
            begin->prev = n;

            end = n;

        }

    }

    void push_front(const T& data) {

        if(begin == nullptr) {

            begin = end = new Node(data);

        }else {

            Node *n = new Node(data, end, begin);

            begin->prev = n;
            end->next = n;

            begin = n;

        }

    }

    T pop_back() {

        if(end == nullptr) {

            throw "List is empty";

        }else if(begin == end) {

            T data = end->data;

            delete end;

            begin = end = nullptr;

            return data;

        }else {

            T data = end->data;

            Node *prev = end->prev;

            prev->next = begin;
            begin->prev = prev;

            delete end;

            end = prev;

            return data;

        }

    }

    T pop_front() {

        if(begin == nullptr) {

            throw "List is empty";

        }else if(begin == end) {

            T data = begin->data;

            delete begin;

            begin = end = nullptr;

            return data;

        }else {

            T data = begin->data;

            Node *next = begin->next;

            next->prev = end;
            end->next = next;

            delete begin;

            begin = next;

            return data;

        }

    }

    bool isEmpty() {

        return begin == nullptr && end == nullptr;

    }

};

#endif // LISTA_HPP