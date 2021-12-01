#include <iostream>
using namespace std;

#include "ListNote.hpp"

int main() {

    ListNote n("ala ma kota", "wstepny tekst");

    n.setContent("asd", 1);

    cout << n.getContent(1);

    return 0;

}