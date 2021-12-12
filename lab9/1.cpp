#include <iostream>
using namespace std;

void toupper(string& str) {

    for(char& c : str) {

        c = toupper(c);

    }

}

int main() {

    string text = "ala ma kota";

    toupper(text);

    cout << text;

    return 0;

}

