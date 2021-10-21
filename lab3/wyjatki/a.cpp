#include <iostream>
using namespace std;

int main() {

    // Zadanie 1
    int a, b, c;

    cout << "Podaj dzielna i dzielnik: ";

    cin >> a >> b;

    try {

        if(b == 0) throw invalid_argument("Dzielnik nie moze sie rownac 0!\n");

        c = a / b;

        cout << "Iloraz z dzielenia " << a << " i " << b << " wynosi " << c << '\n';

    } catch(invalid_argument& e) {

        cout << e.what();

    }

    // Zadanie2
    string s;

    cout << "Podaj liczbe: ";

    cin >> s;

    try {

        int a = stoi(s);

        cout << "Przekonwertowana liczba " << a << '\n';

    } catch(invalid_argument& e) {

        cout << "Wprowadzono niepoprawna liczbe!\n";

    }catch(out_of_range& e) {

        cout << "Wprowadzona liczba jest zbyt duza!\n";

    }

    return 0;

}
