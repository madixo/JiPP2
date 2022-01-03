#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    ifstream in("przystanki.csv");

    if(in) {

        ofstream autobusy("autobusy.csv"), tramwaje("tramwaje.csv");

        if(autobusy && tramwaje) {

            string input;

            while(getline(in, input)) {

                if(input.substr(0, input.find(',')).size() == 3) {

                    autobusy << input << '\n';

                }else {

                    tramwaje << input << '\n';

                }

            }

            autobusy.close();
            tramwaje.close();

        }

        in.close();

    }

    return 0;

}